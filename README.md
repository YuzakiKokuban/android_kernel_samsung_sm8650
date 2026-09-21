# Kokuban 内核 for 三星 Galaxy S24 Snapdragon 系列

<p align="center">
<img src="https://raw.githubusercontent.com/YuzakiKokuban/Kokuban_Kernel_CI_Center/main/docs/kokuban_logo.png" alt="Logo" width="150">
</p>

<p align="center">
<a href="https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases"><img src="https://img.shields.io/github/v/release/YuzakiKokuban/android_kernel_samsung_sm8650?style=for-the-badge&logo=github&color=blue" alt="GitHub release"></a>
<a href="https://t.me/kokubanchat"><img src="https://img.shields.io/badge/Telegram-交流群-blue.svg?style=for-the-badge&logo=telegram" alt="Telegram"></a>
</p>

这是一个面向 **三星 Galaxy S24 Snapdragon 系列** 的自定义内核项目，重点围绕稳定性、性能调优与日常可用性进行构建。项目当前维护 `LKM` 与 `ReSukiSU` 两种发行模式，以满足不同用户对纯净环境和高级功能的需求。

## 项目概览

* **性能优化**：提供面向日常使用与游戏场景的调度与性能调优。
* **精简发行模式**：围绕 `LKM` 与 `ReSukiSU` 两种模式持续维护，减少历史分支带来的维护复杂度。
* **扩展特性支持**：可按 workflow 构建配置集成 `Hybrid Mount`、`SuSFS` 与 `BBG`；自动构建默认集成适用于所有内核的 `Hybrid Mount`，`SuSFS` 仅在 `ReSukiSU` 构建中启用。
* **版本标识**：`-android14-Kokuban-Elysia-DZE1`

## 发行版本说明

* **LKM (Loadable Kernel Module)**
  * 不内置 Root 方案，适合希望保持内核环境尽可能精简的使用方式。
  * 如需 Root，需要通过 KernelSU Manager App 手动修补并刷入设备的 `init_boot` 镜像。

* **ReSuki (ReSukiSU)**
  * 集成 ReSukiSU，并支持 `SUSFS` 与 `KPM` 等高级特性。
  * 适合有模块扩展、隐藏能力或进阶调试需求的用户。

> 当前项目不再维护旧的内置 `KSU/MKSU` 分支模式。

## 安装指南

1. **解锁 Bootloader**：请确保设备已完成 Bootloader 解锁。
2. **准备 Recovery**：建议使用较新的 `TWRP` 或 `OrangeFox Recovery`。
3. **刷入内核**：从本项目 [Releases 页面](https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases) 下载对应版本，并在 Recovery 中刷入内核 `zip` 包。
4. **仅 LKM 版本需要：修补 `init_boot`**
   使用前请先备份当前设备的 `init_boot.img`，再通过 KernelSU Manager App 选择并修补该镜像，随后使用 Fastboot 或 Recovery 将修补后的镜像刷入 `init_boot` 分区。
5. **重启设备**：完成刷入后重启系统并确认功能状态。

## 下载

所有最新构建版本均发布于 [**Releases 页面**](https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases)。

## 反馈与支持

如需获取使用交流、问题反馈或发布通知，可加入 [Telegram 交流群](https://t.me/kokubanchat)。

## 免责声明

刷机有风险，操作需谨慎。在进行任何操作前，请务必完整备份您的个人数据。因刷入此内核而导致的任何设备损坏或数据丢失，本人概不负责。



# Kokuban Kernel for Samsung Galaxy S24 Snapdragon Series

<p align="center">
<img src="https://raw.githubusercontent.com/YuzakiKokuban/Kokuban_Kernel_CI_Center/main/docs/kokuban_logo.png" alt="Logo" width="150">
</p>

<p align="center">
<a href="https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases"><img src="https://img.shields.io/github/v/release/YuzakiKokuban/android_kernel_samsung_sm8650?style=for-the-badge&logo=github&color=blue" alt="GitHub release"></a>
<a href="https://t.me/kokubanchat"><img src="https://img.shields.io/badge/Telegram-Chat-blue.svg?style=for-the-badge&logo=telegram" alt="Telegram"></a>
</p>

This is a custom kernel project for the **Samsung Galaxy S24 Snapdragon Series**, built with a focus on stability, performance tuning, and day-to-day usability. The project currently maintains two release tracks, `LKM` and `ReSukiSU`, to serve both clean setups and advanced power-user workflows.

## Overview

* **Performance Tuned**: Includes targeted scheduling and performance optimizations for smoother daily use and gaming.
* **Streamlined Release Model**: Focuses on the actively maintained `LKM` and `ReSukiSU` variants to keep maintenance predictable and transparent.
* **Optional Feature Integration**: Automated builds integrate `Hybrid Mount` by default and expose a workflow option to disable it. Matching builds may also include `SuSFS` and `BBG`, with `SuSFS` enabled only on `ReSukiSU` releases.
* **Version Identifier**: `-android14-Kokuban-Elysia-DZE1`

## Release Variants

* **LKM (Loadable Kernel Module)**
  * Does not include a built-in root solution and is intended for users who prefer a cleaner kernel environment.
  * If root access is required, patch and flash the device `init_boot` image manually through the KernelSU Manager App.

* **ReSuki (ReSukiSU)**
  * Ships with ReSukiSU integration and supports advanced capabilities such as `SUSFS` and `KPM`.
  * Recommended for users who need module extensibility, root hiding, or other advanced workflows.

> This project no longer maintains the legacy built-in `KSU/MKSU` branch model.

## Installation

1. **Unlock the Bootloader**: Make sure the device bootloader is already unlocked.
2. **Prepare a Recovery Environment**: A recent version of `TWRP` or `OrangeFox Recovery` is recommended.
3. **Flash the Kernel**: Download the appropriate package from the [Releases page](https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases) and flash the kernel `zip` through Recovery.
4. **LKM Builds Only: Patch `init_boot`**
   Back up your current `init_boot.img`, patch it with the KernelSU Manager App, and flash the patched image back to the `init_boot` partition using Fastboot or Recovery.
5. **Reboot the Device**: Restart the system and verify the kernel is running as expected.

## Downloads

All current builds are published on the [**Releases Page**](https://github.com/YuzakiKokuban/android_kernel_samsung_sm8650/releases).

## Support

For release notifications, discussion, or general support, join the [Telegram group](https://t.me/kokubanchat).

## Disclaimer

Flashing custom software carries inherent risks. Please make a full backup of your personal data before proceeding. I am not responsible for any damage to your device or data loss that may occur as a result of flashing this kernel.


<p align="center">
<a href="https://www.paypal.me/LangQin280">☕ Support Me</a>
</p>