<div align="center">

# 🔥 Origin Kernel

### Performance • Stability • Control

**A feature-rich custom kernel for MediaTek-based Nothing devices.**

[![ReSukiSu](https://img.shields.io/badge/ReSukiSU-Supported-green)](https://resukisu.github.io/)
[![SUSFS](https://img.shields.io/badge/SUSFS-Integrated-orange)](https://gitlab.com/pershoot/susfs4ksu)
[![Nethunter](https://img.shields.io/badge/Nethunter-WIP-blue)](https://www.kali.org/docs/nethunter/)
[![Linux 6.1](https://img.shields.io/badge/Kernel-Linux%206.1-blue)](#-kernel-information)
[![MediaTek](https://img.shields.io/badge/Platform-MediaTek-purple)](#-supported-devices)
[![License](https://img.shields.io/badge/License-GPL%20v2-green)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)
[![GitHub release](https://img.shields.io/github/v/release/samakshkambxj/origin-kernel)](https://github.com/samakshkambxj/origin-kernel/releases)

</div>

<p align="center">
  <img src="./main.png" height="400" alt="Origin Kernel" />
</p>

## 📚 Contents

- [About Origin](#-about-origin)
- [Why Origin Kernel?](#-why-origin-kernel)
- [Supported Devices](#-supported-devices)
- [Features](#-features)
- [Planned / Upcoming](#-planned--upcoming)
- [Variants](#-variants)
- [Installation](#-installation)
- [Building from Source](#-building-from-source)
- [Troubleshooting](#-troubleshooting)
- [Kernel Information](#-kernel-information)
- [Useful Links](#-useful-links)
- [Contributing](#-contributing)
- [Community & Support](#-community--support)
- [Credits](#-credits)
- [Disclaimer](#-disclaimer)

> [!WARNING]
> ### ⚠️ Flash at your own risk
>
> Custom kernel flashing can result in bootloops, data loss, or a non-booting device.
> **Always keep a working copy of your stock boot-related images before modifying your device.**
>
> The maintainer is **not responsible** for bricked devices, damaged hardware, data loss, or any other issues caused by using this kernel. By flashing Origin Kernel, **you accept responsibility for the modifications you make to your device**.

## 🌌 About Origin

Origin Kernel is built with a focus on balancing **performance, stability, battery life, and additional kernel functionality** for MediaTek-based Nothing devices.

The project combines kernel features, upstream improvements, custom tuning, and selected third-party components into device-specific builds.

## 💡 Why Origin Kernel?

Stock MediaTek kernels prioritize stability over performance and lack features power users expect. Origin Kernel fills that gap:

- **Root done right** — ReSukiSU with SUSFS for seamless root and hiding, compatible with multiple KernelSU managers.
- **Performance without compromise** — CASS scheduler, Thin LTO, and curated optimization patches improve responsiveness without sacrificing battery life.
- **Modern networking** — BBRv3 as default, IPSet, IPv6 NAT, and TTL manipulation out of the box.
- **Device-specific tuning** — each device gets its own optimized build, not a one-size-fits-all approach.
- **Transparent development** — open source, community-driven, with upstream backports for stability and security.

## 📱 Supported Devices

| Device | Codename | Status |
|---|---|---|
| CMF by Nothing Phone 1 | `Tetris` | 🟢 Supported |
| CMF by Nothing Phone 2 Pro | `Galaga` | 🟢 Supported |
| Nothing Phone (3a) Lite | `Galaxian` | 🟢 Supported |

> **Important:** Always flash the build intended for your exact device. Kernel images and AnyKernel3 packages are **not** interchangeable between devices.

### 🧩 Feature Availability Matrix

Release notes take priority over this table — availability may change between releases.

| Feature | Tetris | Galaga | Galaxian |
|---|:---:|:---:|:---:|
| **Root & Security** | | | |
| ReSukiSu | ✅ | ✅ | ✅ |
| SUSFS | ✅ | ✅ | ✅ |
| Multi-manager KSU | ✅ | ✅ | ✅ |
| Baseband-Guard | ✅ | ✅ | ✅ |
| **Performance** | | | |
| Thin LTO | ✅ | ✅ | ✅ |
| CASS Scheduler | ✅ | ✅ | ✅ |
| Optimization patches | ✅ | ✅ | ✅ |
| **Memory** | | | |
| ZRAM LZ4 | ✅ | ✅ | ✅ |
| TMPFS_XATTR | ✅ | ✅ | ✅ |
| TMPFS_POSIX_ACL | ✅ | ✅ | ✅ |
| MemKernel | ✅ | ✅ | ❌ |
| **Networking** | | | |
| BBRv1 | ✅ | ✅ | ✅ |
| BBRv3 (default) | ✅ | ✅ | ✅ |
| IPSet & IPv6 NAT | ✅ | ✅ | ✅ |
| TTL Target | 🚧 | 🚧 | 🚧 |
| **Advanced** | | | |
| Droidspaces-OSS | ✅ | ✅ | ✅ |
| NetHunter | 🚧 | 🚧 | 🚧 |

**Legend:** ✅ Available · 🚧 WIP · ❌ Unavailable

## ✨ Features

### 🔐 Root & Security

- [**ReSukiSu**](https://github.com/ReSukiSU/ReSukiSU) — KernelSU-based root solution for Android GKI devices, operating in kernel mode to provide root access to userspace applications.
- [**SUSFS**](https://gitlab.com/simonpunk/susfs4ksu) — Kernel patches and userspace support for KernelSU-oriented root hiding.
- **Multi-manager KSU** — works with multiple KernelSU-based managers: [Official KernelSU](https://github.com/tiann/KernelSU), [KernelSU-Next](https://github.com/KernelSU-Next/KernelSU-Next), [MKSU](https://github.com/5ec1cff/KernelSU), [SukiSU](https://github.com/SukiSU-Ultra/SukiSU-Ultra), [Wild KSU](https://github.com/WildKernels/Wild_KSU), and [KowSU](https://github.com/deepongi-labs/KernelSU-KoWSU).
- [**Baseband-Guard**](https://github.com/vc-teahouse/Baseband-guard) — LSM-based protection that blocks unauthorized writes to critical partitions and device nodes.

### ⚡ Performance

- **Thin LTO** — Link-Time Optimization for smaller and faster kernel builds.
- **CASS (Capacity Aware Superset Scheduler)** — custom CPU scheduler tuning for better battery life and responsiveness.
- **Optimization patches** — curated memory, I/O, and networking tuning from the Android and Linux communities.

### 🧠 Memory

- **ZRAM with LZ4 compression** — compressed swap for more usable memory.
- **TMPFS_XATTR** — extended attributes for tmpfs (required by Mountify and similar tools).
- **TMPFS_POSIX_ACL** — POSIX access control lists for tmpfs.
- [**MemKernel**](https://github.com/Poko-Apps/MemKernel) — kernel driver for reading/writing physical memory from userspace.

### 🌐 Networking

- **BBRv3 [DEFAULT]** — modern TCP congestion control for high throughput and low latency.
- **BBRv1** — legacy BBR option for compatibility.
- **IPSet & IPv6 NAT** — firewall and NAT capabilities for advanced networking.
- **TTL Target** 🚧 — packet TTL manipulation (in development).

### 🐧 Advanced / Experimental

- [**Droidspaces-OSS**](https://github.com/ravindu644/Droidspaces-OSS) — lightweight container runtime for running Linux environments on Android.
- [**NetHunter**](https://www.kali.org/docs/nethunter/) 🚧 — Kali NetHunter support (work in progress).

## 🧪 Planned / Upcoming

Features **in development** that may appear in future releases:

- 🚧 **Boeffla Wakelock Blocker** — blocks specific system wakelocks to improve battery life and reduce sleep latency.
- 🚧 **BORE CPU Scheduler** — Burst-Oriented Response Enhancer for better UI responsiveness.
- 🚧 **ADIOS I/O Scheduler** — Adaptive Deadline-based I/O scheduling for faster storage performance.
- 🚧 **WQ Power Efficiency** — reduces CPU wakeups during idle periods.
- 🚧 **ZRAM Writeback** — writes idle/compressed ZRAM pages to backing storage for more effective swap.
- 🚧 **DAMON** — Data Access MONitor for proactive memory management based on access patterns.

**Backported Upstream Fixes** (pending stable integration):

- **ZRAM** — multi-stream compression for better ratios.
- **f2fs** — inline inode handling, compress cache validation, ACL fixes, write I/O UAF prevention.
- **ext4** — inline data bounds checking, superblock update checks, DAX restrictions on encrypted files.
- **mm** — percpu bitmap overflow, page reporting UAF during suspend, vmalloc ptdump UAF, huge_zero_pfn race.
- **Scheduler** — deadline migration warnings, RT push task race, PSI timer shutdown for power savings.
- **Network** — IGMP UAF prevention, bridge multicast UAF fix.
- **Vendor hooks** — memcg PSI recording skip, migration batch hooks, direct reclaim hooks.

## 🧩 Variants

| Variant | Description |
|---|---|
| **Origin-ReSukiSU** | Includes ReSukiSU for ready-to-use kernel root. |
| **Origin-KSUN** | Built with KernelSU-Next for the latest KernelSU experience. |
| **Origin-Vanilla** | No pre-integrated root — for use in custom ROM builds. |

> **Note:** Variant availability may differ between devices and releases. Check release notes before flashing.

## 📲 Installation

### Prerequisites

- **Unlocked bootloader**
- **Backup of current boot image** (stock `boot.img`, `init_boot`, or `vendor_boot`)
- Root access via **Magisk / KernelSU / APatch** (required for some methods)
- [MagiskBoot](https://github.com/svoboda18/magiskboot) — for manual boot image patching
- [Wild KSU Manager](https://github.com/WildKernels/Wild_KSU/releases/tag/v3.1.2) — for Wild KSU workflow

> [!IMPORTANT]
> ### ⚠️ Fenrir users
> If you are using **Fenrir**, the AnyKernel3 ZIP will **not** change the kernel due to a conflict. Patch your `boot.img` with the Origin Kernel `Image` and flash via **fastboot** instead. See [Method 3](#method-3--manual-boot-image-patching).

### Method 1 — Kernel Flasher

1. Download the correct **AnyKernel3 (AK3) ZIP** for your device.
2. Clean up any previous root setup:
   - **Magisk:** fully uninstall after flashing.
   - **KSU LKM:** restore the stock image that was patched.
   - **KSU GKI:** restore stock images if not already done.
   - **APatch:** remove `/data/adb` contents to avoid conflicts.
3. Flash the ZIP to the active slot using Kernel Flasher.
4. Install the **KernelSU-Next Manager APK** from the release notes.
5. Reboot.

### Method 2 — KernelSU / KernelSU-Next App

If already rooted with KernelSU or a compatible fork, flash the **AnyKernel3 ZIP directly from the manager**.

### Method 3 — Manual Boot Image Patching

```bash
# 1. Unpack stock boot image
./magiskboot unpack boot.img

# 2. Delete the extracted kernel file
rm kernel

# 3. Copy and rename Origin Kernel Image to kernel
cp Image kernel

# 4. Repack
./magiskboot repack boot.img

# 5. Flash the patched image
fastboot flash boot new-boot.img
```

### Method 4 — Wild KSU Manager

1. Obtain root with **Wild KSU**.
2. Open Wild KSU → **Install → GKI → Patch boot image**.
3. Select the **AnyKernel3 ZIP**, then select your stock boot image.
4. Flash the resulting `WildKSU-GKI----` image via Kernel Flasher or fastboot.

## 🔧 Building from Source

```bash
# 1. Clone the repository
git clone https://github.com/samakshkambxj/origin-kernel.git
cd origin-kernel

# 2. Set up the build environment (requires clang + GCC toolchain)
export ARCH=arm64
export SUBARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
export CROSS_COMPILE_ARM32=arm-linux-gnueabi-

# 3. Generate defconfig
make gki_defconfig

# 4. Build the kernel
make -j$(nproc)
```

Output kernel image will be at `arch/arm64/boot/Image`. Use [AnyKernel3](https://github.com/osm0sis/AnyKernel3) to package it as a flashable ZIP.

## 🔍 Troubleshooting

| Issue | Solution |
|---|---|
| **Bootloop after flashing** | Boot to recovery, restore stock `boot.img` via fastboot: `fastboot flash boot boot.img` |
| **No root access** | Install the KernelSU-Next manager APK from the release notes and reboot |
| **App detects root (SafetyNet/Play Integrity)** | Enable DenyList in KernelSU-Next manager, enable SUSFS mount hiding |
| **Device feels slower after flashing** | Clear cache from recovery, reboot again; performance improves after a few charge cycles |
| **WiFi/BT broken** | Ensure you flashed the correct device variant; restore stock image and re-flash |

If none of these work, collect logs (`dmesg`, `logcat`) and open an issue on GitHub.

## 🛠️ Kernel Information

| Codename | Device | Kernel | Root Method |
|---|---|---|---|
| `Tetris` | CMF Phone 1 | 6.1.162 | KernelSU-Next |
| `Galaga` | CMF Phone 2 Pro | 6.1.145 | KernelSU-Next |
| `Galaxian` | Nothing Phone (3a) Lite | 6.1.145 | KernelSU-Next |

## 🔗 Useful Links

- [Kernel Flasher (fatalcoder524 fork)](https://github.com/fatalcoder524/KernelFlasher/releases/latest)
- [Nothing Archive — spike0en](https://spike0en.github.io/nothing_archive/)
- [Flashing Stock ROM / Unbrick / Downgrade Guide](https://spike0en.github.io/nothing_archive/docs/guides#flashing-stock-rom-unbrick--downgrade)
- [Hard Unbrick Guide](https://spike0en.github.io/nothing_archive/docs/guides#hard-unbrick)

## 💬 Community & Support

- [Telegram Updates Channel](https://t.me/itsonlyachannel)
- [Telegram Support Chat](https://t.me/itisnotwhatyouthinkitis)
- [GitHub Issues](https://github.com/samakshkambxj/origin-kernel/issues)

## 🤝 Contributing

Contributions are welcome. Here's how you can help:

- **Bug reports** — open an issue with device model, OS version, and steps to reproduce.
- **Code contributions** — fork the repo, create a feature branch, and submit a pull request.
- **Testing** — flash experimental builds and report back on stability and performance.
- **Documentation** — improve this README, translate guides, or write tutorials.

Please follow the existing code style and test changes on your device before submitting.

## 🙏 Credits

- **KernelSU** — [tiann](https://github.com/tiann/KernelSU)
- **KernelSU-Next / ReSukiSu** — [rifsxd](https://github.com/KernelSU-Next/KernelSU-Next)
- **MKSU** — [5ec1cff](https://github.com/5ec1cff/KernelSU)
- **SUSFS** — [simonpunk](https://gitlab.com/simonpunk/susfs4ksu)
- **SUSFS Module** — [sidex15](https://github.com/sidex15)
- **Sultan Kernels** — [kerneltoast](https://github.com/kerneltoast)
- **Kernel Flasher** — [fatalcoder524](https://github.com/fatalcoder524)
- **Baseband-Guard** — [vc-teahouse](https://github.com/vc-teahouse/Baseband-guard)

Thanks to all contributors, testers, and the Nothing community.

## ⭐ Like My Work?

If you found **Origin Kernel** useful, consider giving the repo a **star** on GitHub — it helps support the project!

## ⚠️ Disclaimer

Flashing a custom kernel involves inherent risks, including bootloops, data loss, or device failure. Unlocking the bootloader or modifying system software may also affect warranty or service eligibility.

Always back up your data and stock boot images before flashing. Use only the build intended for your exact codename.

**Proceed at your own risk.**
