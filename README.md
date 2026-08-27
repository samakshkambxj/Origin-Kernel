<div align="center">

# 🔥 Origin Kernel

### Performance • Stability • Control

**A feature-rich custom kernel for Mediatek chipset based Nothing devices.**

[![ReSukiSu](https://img.shields.io/badge/ReSukiSU-Supported-green)](https://resukisu.github.io/)
[![SUSFS](https://img.shields.io/badge/SUSFS-Integrated-orange)](https://gitlab.com/pershoot/susfs4ksu)
[![Nethunter](https://img.shields.io/badge/Nethunter-WIP-blue)](https://www.kali.org/docs/nethunter/)

</div>

<p align="center">
  <img src="./main.png" height="400" alt="Origin Kernel" />
</p>

> [!WARNING]
> ### ⚠️ Flash at your own risk
>
> Custom kernel flashing can result in bootloops, data loss, or a non-booting device.
> **Always keep a working copy of your stock boot-related images before modifying your device.**
>
> The maintainer is **not responsible** for bricked devices, damaged hardware, data loss, or any other issues caused by using this kernel. By flashing Origin Kernel, **you accept responsibility for the modifications you make to your device**.

## 📱 Supported Devices

Origin Kernel currently targets the following devices:

| Device | Device codename used by releases | Status |
|---|---|---|
| CMF by Nothing Phone 1 | Tetris | 🟢 Supported |
| CMF by Nothing Phone 2 Pro | Galaga | 🟢 Supported |
| Nothing Phone (3a) Lite | Galaxian | 🟢 Supported |

> **Important:** Always flash the build intended for your exact device. Do not assume that a kernel image or AnyKernel3 package is interchangeable between devices.

### 🧩 Feature Availability Matrix

Use the matrix below to quickly check which features are available for each device build. Availability can change between releases, so **release notes take priority over this table**.

| Feature | Tetris | Galaga | Galaxian |
|---|:---:|:---:|:---:|
| ReSukiSu | ✅ | ✅ | ✅ |
| SUSFS | ✅ | ✅ | ✅ |
| Multi-manager KSU support | ✅ | ✅ | ✅ |
| Droidspaces-OSS | ✅ | ✅ | ✅ |
| Baseband-Guard | ✅ | ✅ | ✅ |
| Thin LTO | ✅ | ✅ | ✅ |
| Optimization patches | ✅ | ✅ | ✅ |
| CASS | ✅ | ✅ | ✅ |
| ZRAM LZ4 | ✅ | ✅ | ✅ |
| BBRv1 | ✅ | ✅ | ✅ |
| BBRv3 (default) | ✅ | ✅ | ✅ |
| IPSet & IPv6 NAT | ✅ | ✅ | ✅ |
| Boeffla Wakelock Blocker | ❌ | ❌ | ❌ |
| KCAL / Advanced Display Control | ❌ | ❌ | ❌ |
| KSM (Kernel Samepage Merging) | ❌ | ❌ | ❌ |
| Advanced GPU frequency controls | ❌ | ❌ | ❌ |
| TTL Target | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> |
| TMPFS_XATTR | ✅ | ✅ | ✅ |
| TMPFS_POSIX_ACL | ✅ | ✅ | ✅ |
| MemKernel | ✅ | ✅ | ❌ |
| NetHunter | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> | <img src="https://img.shields.io/badge/WIP-FFD43B?style=for-the-badge&labelColor=555" alt="WIP"> |

**Legend:**

- ✅ **Available** — feature is included for the documented device build.
- ❌ **Unavailable** — feature is not included for that device build.
- 🚧 **WIP** — feature is present but still under development/testing.
- — **Not documented** — device-specific availability has not been established here; check the corresponding release notes.

> **Note:** The project uses **Tetris** for CMF Phone 1, **Galaga** for CMF Phone 2 Pro, and **Galaxian** for Nothing Phone (3a) Lite. Feature availability should still be checked against the release notes for the exact build.

## ✨ Features

### 🔐 Root & Security

- [**ReSukiSu**](https://github.com/ReSukiSU/ReSukiSU) — KernelSU-based root solution for Android GKI devices, operating in kernel mode to provide root access to userspace applications.
- [**SUSFS**](https://gitlab.com/simonpunk/susfs4ksu) — Kernel patches and userspace support for KernelSU-oriented root hiding.
- **Multi-manager support** — compatible manager options include [Official KernelSU](https://github.com/tiann/KernelSU), [RKSU](https://github.com/rsuntk/KernelSU), [MKSU](https://github.com/5ec1cff/KernelSU), [SukiSU](https://github.com/SukiSU-Ultra/SukiSU-Ultra), [Wild KSU](https://github.com/WildKernels/Wild_KSU), and [KowSU](https://github.com/deepongi-labs/KernelSU-KoWSU).
- [**Baseband-Guard**](https://github.com/vc-teahouse/Baseband-guard) — lightweight LSM-based protection designed to block unauthorized writes to critical partitions and device nodes.

### ⚡ Performance

- **Thin LTO** — enabled for kernel build optimization.
- **Optimization patches** — memory, I/O, CPU scheduler, networking, and general tuning changes.
- **Capacity Aware Superset Scheduler (CASS)** — custom CPU scheduling changes targeting battery life and performance.

### 🧠 Memory

- **ZRAM with LZ4 compression** — improves usable compressed swap capacity.
- **TMPFS_XATTR** — extended attributes support for tmpfs, including Mountify-related use cases.
- **TMPFS_POSIX_ACL** — POSIX ACL support for tmpfs.
- [**MemKernel**](https://github.com/Poko-Apps/MemKernel) — Android kernel driver for reading and writing physical memory.

### 🌐 Networking

- **BBRv1** — enabled TCP congestion control option.
- **BBRv3 [DEFAULT]** — default TCP congestion control option.
- **IPSet & IPv6 NAT support** — additional firewall and networking capabilities.
- **TTL Target support** 🚧 — network packet manipulation support.

### 🐧 Advanced / Experimental

- [**Droidspaces-OSS**](https://github.com/ravindu644/Droidspaces-OSS) — lightweight, LXC-like container runtime for Android and Linux.
- [**NetHunter**](https://www.kali.org/docs/nethunter/) 🚧 — Kali NetHunter support is currently a work in progress.

### 🧪 Planned / Currently Unavailable

The following features are **not currently available on any supported Origin Kernel device**. They are listed as potential future additions and are not part of the current kernel builds.

- ❌ **Boeffla Wakelock Blocker** — A kernel module designed to prevent specific system wakelocks from keeping Android devices awake, potentially improving battery life and reducing sleep latency.
- ❌ **Multi-Gen LRU (MGLRU)** — Modern page-reclaim infrastructure designed to improve memory-management efficiency and responsiveness under memory pressure.
- ❌ **KCAL / Advanced Display Control** — Additional kernel-level display calibration and color-control options.
- ❌ **KSM (Kernel Samepage Merging)** — Memory deduplication support that can reduce duplicate memory pages when applicable.
- ❌ **UKSM** — An alternative userspace-oriented memory deduplication implementation for reducing redundant anonymous pages.
- ❌ **Simple Low Memory Killer (Simple LMK)** — Lightweight low-memory reclaim logic for handling memory pressure on Android devices.
- ❌ **Advanced GPU frequency controls** — Additional kernel-level controls for GPU frequency and power-management tuning.

> [!NOTE]
> Features marked **WIP** are incomplete and may not be ready for daily use.
>
> Features marked **Currently Unavailable** are **not included in any current device build** and should not be expected to work until explicitly added and documented in a future release.

## 📦 Downloads

Prebuilt kernel packages are distributed through the project's releases.

**Before flashing:**

1. Confirm the package matches your exact device.
2. Read the release notes for any version-specific requirements.
3. Keep a backup of your stock boot-related images so you can recover if needed.

For supported installation methods, see the [Installation](#-installation) section below.

## 📲 Installation

### Prerequisites

- An **unlocked bootloader**.
- A **backup of your current boot image** (and any other boot-related image you may need to restore).
- Existing root access through **Magisk / KernelSU / APatch (or a compatible fork)** where required by the selected method.
- [MagiskBoot](https://github.com/svoboda18/magiskboot) for manual boot image patching.
- [Wild KSU Manager](https://github.com/WildKernels/Wild_KSU/releases/tag/v3.1.2) when using the Wild KSU boot-image patching workflow.

> [!IMPORTANT]
> ### ⚠️ Fenrir users
> If you are using **Fenrir**, flashing the **AnyKernel3 (AK3) ZIP** will not actually change the kernel because of a conflict with Fenrir. This does **not** mean that Origin Kernel is unsupported alongside Fenrir; the limitation applies specifically to the AnyKernel3 ZIP installation method.
>
> In this case, patch your `boot.img` with the Origin Kernel `Image` and flash the patched image using **fastboot**. See [Method 3 — Manual Boot Image Patching](#method-3--manual-boot-image-patching).

### Method 1 — Kernel Flasher

1. Download the correct **AnyKernel3 (AK3) ZIP** for your device (**Tetris**, **Galaga**, or **Galaxian**).
2. If you previously used another root method, clean up the previous setup first:
   - **Magisk:** perform a complete uninstall after flashing the AnyKernel3 ZIP.
   - **KSU LKM** (patched `boot` / `init_boot` / `vendor_boot`): restore the corresponding stock image(s) that were patched.
   - **KSU GKI:** if you are **100% certain** that stock `init_boot` / `boot` / `vendor_boot` has already been restored, no additional action is required. Otherwise, follow the same restoration process as KSU LKM.
   - **APatch:** remove the `/data/adb` contents to avoid leftover root conflicts after flashing the AnyKernel3 ZIP.
3. Flash the ZIP to the active slot using Kernel Flasher.
4. Install the **KernelSU-Next Manager APK** specified in the release notes. Use the required version.
5. Open the KernelSU-Next app.
6. Reboot the device if you performed any cleanup in step 2.

### Method 2 — KernelSU / KernelSU-Next App

If your device is already rooted with KernelSU, KernelSU-Next, or a compatible fork, you can flash the **AnyKernel3 ZIP directly from the manager**.

### Method 3 — Manual Boot Image Patching

1. Extract your stock `boot.img` and place it in a working directory.
2. Run:

   ```bash
   ./magiskboot unpack boot.img
   ```

3. A file named `kernel` will be created.
4. Delete the extracted `kernel` file.
5. Place the `Image` file from the Origin Kernel release into the same directory.
6. Rename `Image` to `kernel`.
7. Repack the image:

   ```bash
   ./magiskboot repack boot.img
   ```

8. The patched image will be generated as `new-boot.img`.
9. Flash it with fastboot:

   ```bash
   fastboot flash boot new-boot.img
   ```

10. Reboot and verify that the device boots normally.

### Method 4 — Wild KSU Manager

1. Obtain root using **Wild KSU**.
2. Have the **AnyKernel3 ZIP** and stock boot image ready.
3. Open Wild KSU and go to **Install → GKI**.
4. Select **Patch boot image**.
5. Select the **AnyKernel3 ZIP** first, then select your boot image.
6. Wild KSU will patch the boot image with the kernel.
7. The patched boot image will appear in the Downloads section with a name similar to `WildKSU-GKI----`.
8. Flash the resulting boot image using **Kernel Flasher** or **fastboot**.

## 🛠️ Kernel Information

| Codename | Root Method | Kernel Version | Kernel Build |
|---|---|---|---|
| **Tetris** | KernelSU-Next | 6.1.162 | **v1** |
| **Galaga** | KernelSU-Next | 6.1.145 | **v2** |
| **Galaxian** | KernelSU-Next | 6.1.145 | **v2** |

## 🔗 Useful Links

- [Kernel Flasher — fatalcoder524 fork](https://github.com/fatalcoder524/KernelFlasher/releases/latest)
- [Nothing Archive — spike0en](https://spike0en.github.io/nothing_archive/)
- [Flashing Stock ROM / Unbrick / Downgrade Guide](https://spike0en.github.io/nothing_archive/docs/guides#flashing-stock-rom-unbrick--downgrade)
- [Hard Unbrick Guide](https://spike0en.github.io/nothing_archive/docs/guides#hard-unbrick)
- [Telegram Updates Channel](https://t.me/s/CMFPhone2GlobalUpdates)
- [Telegram Chat](https://t.me/CMFPhone2_Global)

## 🙏 Credits

Origin Kernel builds upon the work of many developers and open-source projects:

- **KernelSU:** Developed by [tiann](https://github.com/tiann/KernelSU).
- **KernelSU-Next / ReSukiSu:** Developed by [rifsxd](https://github.com/KernelSU-Next/KernelSU-Next) and the respective project contributors.
- **Magic-KSU:** Developed by [5ec1cff](https://github.com/5ec1cff/KernelSU).
- **SUSFS:** Developed by [simonpunk](https://gitlab.com/simonpunk/susfs4ksu.git).
- **SUSFS Module:** Developed by [sidex15](https://github.com/sidex15).
- **Sultan Kernels:** Developed by [kerneltoast](https://github.com/kerneltoast).
- **Kernel Flasher:** Developed by [fatalcoder524](https://github.com/fatalcoder524).
- **Baseband-Guard (BBG):** Developed by [vc-teahouse](https://github.com/vc-teahouse/Baseband-guard).

Special thanks to all contributors, testers, friends, and the Nothing community for their help and feedback.

## ⭐ Like My Work?

If you found **Origin Kernel** useful or enjoyed my work, consider giving the repository a **star ⭐** on GitHub. It helps support the project and motivates me to keep improving it!

**Thank you for your support! ❤️**

## ⚠️ Disclaimer

Flashing a custom kernel involves inherent risks, including bootloops, data loss, or device failure. Unlocking the bootloader or modifying system software may also affect warranty or service eligibility depending on the manufacturer and region.

Always keep a complete backup of your important data and stock boot-related images before flashing. Make sure you understand the recovery process for your device and use only the build intended for your exact codename.

**Proceed at your own risk.**
