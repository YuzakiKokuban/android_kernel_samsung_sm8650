#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Mirror the mconsole_request structure layout from the kernel headers */
#include "arch/um/include/shared/mconsole.h"

START_TEST(test_mconsole_len_bounds)
{
    /* Invariant: computed len must never be negative or exceed actual buffer size */
    struct mconsole_request req;
    memset(&req, 0, sizeof(req));

    /* payloads: (ptr_offset, spoofed_len) pairs */
    struct { int offset; int spoofed_len; } cases[] = {
        /* Exact exploit: spoofed len smaller than ptr offset -> negative len */
        { 10, 5 },
        /* Boundary: ptr at end of data, len == 0 */
        { (int)sizeof(req.request.data), 0 },
        /* Valid: ptr at start, len equals full data size */
        { 0, (int)sizeof(req.request.data) },
        /* Overflow: spoofed len far exceeds buffer */
        { 0, INT_MAX },
    };
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++) {
        char *ptr = req.request.data + cases[i].offset;
        int spoofed_len = cases[i].spoofed_len;

        /* Replicate the vulnerable arithmetic from mconsole_kern.c line 122 */
        ptrdiff_t ptr_advance = ptr - req.request.data;
        int computed_len = spoofed_len - (int)ptr_advance;

        /* Security invariant: computed_len must be >= 0 and
         * must not exceed the actual remaining buffer space */
        int actual_remaining = (int)(sizeof(req.request.data) - ptr_advance);

        ck_assert_msg(computed_len >= 0,
            "case %d: computed len is negative (%d) — out-of-bounds read possible",
            i, computed_len);

        ck_assert_msg(computed_len <= actual_remaining,
            "case %d: computed len (%d) exceeds actual buffer remaining (%d) — overflow",
            i, computed_len, actual_remaining);
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s = suite_create("Security");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_mconsole_len_bounds);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = security_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}