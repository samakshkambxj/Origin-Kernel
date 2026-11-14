<div align="center">

# 🔥 Origin Kernel

### Performance • Stability • Control

**A feature-rich custom kernel for MediaTek-based Nothing devices.**

[![OriginSU](https://img.shields.io/badge/OriginSU-Supported-green)](https://samakshkambxj.github.io/OriginSU/)
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
- [Recently Landed](#-recently-landed)
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

The project combines kernel features, upstream improvements, custom tuning, and selected third-party components into a single image per variant that boots every supported device.

## 💡 Why Origin Kernel?

Stock MediaTek kernels prioritize stability over performance and lack features power users expect. Origin Kernel fills that gap:

- **Root done right** — OriginSU with SUSFS, Origin Veil, KPM and ZeroMount for seamless root and hiding, compatible with multiple KernelSU managers.
- **Performance without compromise** — CASS and BORE scheduling, Clang Full LTO, and curated optimization patches improve responsiveness without sacrificing battery life.
- **Modern networking** — BBRv3 as default, IPSet, IPv6 NAT, and TTL manipulation out of the box.
- **Unified tuning** — one optimized image boots every supported MT6878 device, so there is no per-device build to keep in sync.
- **Transparent development** — open source, community-driven, with upstream backports for stability and security.

## 📱 Supported Devices

| Device | Codename | Status |
|---|---|---|
| CMF by Nothing Phone 1 | `Tetris` | 🟢 Supported |
| CMF by Nothing Phone 2 Pro | `Galaga` | 🟢 Supported |
| Nothing Phone (3a) Lite | `Galaxian` | 🟢 Supported |

> **Important:** The same kernel image boots all three devices. It is still built for this MT6878 family only — do not flash it on any other Nothing or CMF model. Kernel images and AnyKernel3 packages are interchangeable between the three codenames, but not with any other device.

### 🧩 Feature Availability Matrix

Release notes take priority over this table — availability may change between releases.

| Feature | Tetris | Galaga | Galaxian |
|---|:---:|:---:|:---:|
| **Root & Security** | | | |
| OriginSU | ✅ | ✅ | ✅ |
| SUSFS | ✅ | ✅ | ✅ |
| Origin Veil | ✅ | ✅ | ✅ |
| KPM | ✅ | ✅ | ✅ |
| ZeroMount | ✅ | ✅ | ✅ |
| Multi-manager KSU | ✅ | ✅ | ✅ |
| Baseband-Guard | ✅ | ✅ | ✅ |
| **Performance** | | | |
| Full LTO | ✅ | ✅ | ✅ |
| CASS Scheduler | ✅ | ✅ | ✅ |
| BORE Scheduler | ✅ | ✅ | ✅ |
| ADIOS I/O Scheduler | ✅ | ✅ | ✅ |
| Optimization patches | ✅ | ✅ | ✅ |
| **Memory** | | | |
| ZRAM LZ4 | ✅ | ✅ | ✅ |
| ZRAM Writeback | ✅ | ✅ | ✅ |
| TMPFS_XATTR | ✅ | ✅ | ✅ |
| TMPFS_POSIX_ACL | ✅ | ✅ | ✅ |
| DAMON | ✅ | ✅ | ✅ |
| **Networking** | | | |
| BBRv1 | ✅ | ✅ | ✅ |
| BBRv3 (default) | ✅ | ✅ | ✅ |
| IPSet & IPv6 NAT | ✅ | ✅ | ✅ |
| TTL Target | ✅ | ✅ | ✅ |
| **Advanced** | | | |
| Droidspaces-OSS | ✅ | ✅ | ✅ |
| NetHunter | 🚧 | 🚧 | 🚧 |

**Legend:** ✅ Available · 🚧 WIP · ❌ Unavailable

## ✨ Features

### 🔐 Root & Security

- [**OriginSU**](https://github.com/samakshkambxj/OriginSU) — KernelSU-based root solution for Android GKI devices, tracking its `main` branch and operating in kernel mode to provide root access to userspace applications.
- **Origin Veil 2.0** — kernel-side root-probe observation and per-uid mount cloaking, with a bounded event queue for the manager.
- **KPM** — Kernel Patch Module loading, with `KALLSYMS_ALL` enabled so modules can resolve kernel symbols.
- [**ZeroMount**](https://github.com/Enginex0/zeromount) — VFS path redirection through `/dev/zeromount`, so modules load without adding mount table entries. Requires the ZeroMount userspace module.
- [**SUSFS**](https://gitlab.com/pershoot/susfs4ksu) — kernel-side hiding using the SUSFS inline hook: suspicious paths and mounts, kstat spoofing, open redirect, suspicious maps, uname and cmdline spoofing, AVC log spoofing and symbol hiding.
- **Multi-manager KSU** — works with multiple KernelSU-based managers: OriginSU, [MKSU](https://github.com/5ec1cff/KernelSU), [SukiSU](https://github.com/SukiSU-Ultra/SukiSU-Ultra), [ReSukiSU](https://github.com/ReSukiSU/ReSukiSU), [RKSU](https://github.com/rsuntk/KernelSU), and [KowSU](https://github.com/deepongi-labs/KernelSU-KoWSU).
- [**Baseband-Guard**](https://github.com/vc-teahouse/Baseband-guard) — LSM-based protection that blocks unauthorized writes to critical partitions and device nodes. Boot and recovery protection stays off so kernel and recovery images can still be flashed from Android.

### ⚡ Performance

- **Clang Full LTO** — whole-kernel Link-Time Optimization alongside CFI and Shadow Call Stack, so inlining and dead-code elimination work across translation units.
- **CASS (Capacity Aware Superset Scheduler)** — capacity-based runqueue selection for better multi-core behaviour on big.LITTLE silicon.
- **BORE (Burst-Oriented Response Enhancer)** — prioritizes short-burst, interactive tasks under background load.
- **ADIOS I/O scheduler** — Adaptive Deadline I/O Scheduler, set as the default multi-queue scheduler.
- **Boeffla wakelock blocker** — blocks selected userspace wakelocks to cut idle drain and sleep latency.
- **Optimization patches** — curated memory, I/O, and networking tuning from the Android and Linux communities.

### 🧠 Memory

- **ZRAM with LZ4 compression** — multi-compression streams, writeback and memory tracking for more effective swap.
- **TMPFS_XATTR** — extended attributes for tmpfs (required by Mountify and similar tools).
- **TMPFS_POSIX_ACL** — POSIX access control lists for tmpfs.
- **DAMON** — data access monitoring with reclaim and LRU sorting for proactive memory management.
- [**MemKernel**](https://github.com/Poko-Apps/MemKernel) ❌ — kernel driver for reading/writing physical memory from userspace; not included in the current builds.

### 🌐 Networking

- **BBRv3 [DEFAULT]** — modern TCP congestion control for high throughput and low latency.
- **BBRv1** — legacy BBR option for compatibility.
- **IPSet & IPv6 NAT** — firewall and NAT capabilities for advanced networking.
- **TTL Target** — packet TTL manipulation.
- **CAKE & PIE** — queue disciplines for bufferbloat control.

### 🐧 Advanced / Experimental

- [**Droidspaces-OSS**](https://github.com/ravindu644/Droidspaces-OSS) — lightweight container runtime for running Linux environments on Android, backed by SYSVIPC, PID/UTS/IPC/NET namespaces, binderfs and OverlayFS.
- [**NetHunter**](https://www.kali.org/docs/nethunter/) 🚧 — Kali NetHunter support (work in progress, kept on a separate branch).

## ✅ Recently Landed

Previously tracked as upcoming — all of these are now part of the current builds:

- ✅ **Boeffla Wakelock Blocker** — blocks specific system wakelocks to improve battery life and reduce sleep latency.
- ✅ **BORE CPU Scheduler** — Burst-Oriented Response Enhancer for better UI responsiveness.
- ✅ **ADIOS I/O Scheduler** — Adaptive Deadline-based I/O scheduling for faster storage performance.
- ✅ **WQ Power Efficiency** — reduces CPU wakeups during idle periods.
- ✅ **ZRAM Writeback** — writes idle/compressed ZRAM pages to backing storage for more effective swap.
- ✅ **DAMON** — Data Access MONitor for proactive memory management based on access patterns.

**Backported Upstream Fixes** (integrated in current builds):

- **ZRAM** — multi-stream compression for better ratios, plus recompression (`recompress` knob and algorithm selection).
- **EROFS** — Zstandard compression.
- **f2fs** — inline inode handling, compress cache validation, ACL fixes, write I/O UAF prevention.
- **ext4** — inline data bounds checking, superblock update checks, DAX restrictions on encrypted files.
- **mm** — percpu bitmap overflow, page reporting UAF during suspend, vmalloc ptdump UAF, huge_zero_pfn race.
- **Scheduler** — deadline migration warnings, RT push task race, PSI timer shutdown for power savings.
- **Network** — IGMP UAF prevention, bridge multicast UAF fix, BBRv3 with Android KABI compliance.
- **Core and arm64** — `fchmodat2()`, `cachestat()`, vDSO `getrandom()`, SCS unwinder fixes and optimized `memcmp`/`memcpy`/`memset`.
- **Vendor hooks** — memcg PSI recording skip, migration batch hooks, direct reclaim hooks.

## 🧩 Variants

| Variant | Description |
|---|---|
| **Origin-Reforged** | Includes OriginSU, SUSFS, Origin Veil, KPM, ZeroMount and Baseband-Guard for ready-to-use kernel root. Built from the `main` branch. |
| **Origin-Vanilla** | No pre-integrated root — tuning and backports only, for use in custom ROM builds. Built from the `vanilla` branch. |

Release strings carry the variant: `6.1.182-Origin-Reforged-<commits>-g<sha>` for the rooted build and `6.1.182-Origin-Vanilla-<commits>-g<sha>` for the vanilla build. Each variant ships one image that boots all three supported devices.

> **Note:** Origin-Reforged replaces the previous ReSukiSU and KernelSU-Next rooted variants. Variant availability may differ between devices and releases — check release notes before flashing.

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

1. Download the **AnyKernel3 (AK3) ZIP** for your variant.
2. Clean up any previous root setup:
   - **Magisk:** fully uninstall after flashing.
   - **KSU LKM:** restore the stock image that was patched.
   - **KSU GKI:** restore stock images if not already done.
   - **APatch:** remove `/data/adb` contents to avoid conflicts.
3. Flash the ZIP to the active slot using Kernel Flasher.
4. Install the **OriginSU manager APK** from the release notes.
5. Reboot.

### Method 2 — KernelSU / OriginSU App

If already rooted with OriginSU, KernelSU or a compatible fork, flash the **AnyKernel3 ZIP directly from the manager**. The Origin-Vanilla ZIP ships no root solution, so on an unrooted device use Method 3 instead.

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
# 1. Clone the repository with its submodules
git clone --recurse-submodules https://github.com/samakshkambxj/Origin-Kernel.git
cd Origin-Kernel

# 2. Set up the build environment (clang/LLVM with the integrated assembler)
export ARCH=arm64
export LLVM=1
export LLVM_IAS=1

# 3. Generate defconfig
make O=out gki_defconfig

# 4. Build the kernel
make O=out -j$(nproc) Image
```

Output kernel image will be at `out/arch/arm64/boot/Image`. Use [AnyKernel3](https://github.com/osm0sis/AnyKernel3) to package it as a flashable ZIP.

`gki_defconfig` enables everything documented above, so no menuconfig step is required; the submodules (`KernelSU`, `susfs4ksu`, `Baseband-guard`) must be initialized, so run `git submodule update --init --recursive` if you cloned without `--recurse-submodules`. These commands build Origin-Reforged from `main`; switch to `vanilla` for Origin-Vanilla. Because full LTO is enabled, the final link is a single whole-kernel optimization pass — expect a long link step and several gigabytes of RAM.

## 🔍 Troubleshooting

| Issue | Solution |
|---|---|
| **Bootloop after flashing** | Boot to recovery, restore stock `boot.img` via fastboot: `fastboot flash boot boot.img` |
| **No root access** | Install the OriginSU manager APK from the release notes and reboot |
| **App detects root (SafetyNet/Play Integrity)** | Enable DenyList in the OriginSU manager, enable SUSFS path and mount hiding |
| **Modules do not mount** | Install the ZeroMount userspace module; the kernel only provides `/dev/zeromount` |
| **Device feels slower after flashing** | Clear cache from recovery, reboot again; performance improves after a few charge cycles |
| **WiFi/BT broken** | Restore the stock image and re-flash; make sure you did not mix in a boot image from another firmware branch |

If none of these work, collect logs (`dmesg`, `logcat`) and open an issue on GitHub.

## 🛠️ Kernel Information

| Codename | Device | Kernel | Root Method |
|---|---|---|---|
| `Tetris` | CMF Phone 1 | 6.1.182 | OriginSU |
| `Galaga` | CMF Phone 2 Pro | 6.1.182 | OriginSU |
| `Galaxian` | Nothing Phone (3a) Lite | 6.1.182 | OriginSU |

All three devices share the same image per variant, built from `android14-6.1.182_r00`. Origin-Reforged uses `CONFIG_LOCALVERSION="-Origin-Reforged"` and includes OriginSU; Origin-Vanilla uses `CONFIG_LOCALVERSION="-Origin-Vanilla"` and ships no root solution.

## 🔗 Useful Links

- [Kernel Flasher (fatalcoder524 fork)](https://github.com/fatalcoder524/KernelFlasher/releases/latest)
- [Nothing Archive — spike0en](https://spike0en.github.io/nothing_archive/)
- [Flashing Stock ROM / Unbrick / Downgrade Guide](https://spike0en.github.io/nothing_archive/docs/guides#flashing-stock-rom-unbrick--downgrade)
- [Hard Unbrick Guide](https://spike0en.github.io/nothing_archive/docs/guides#hard-unbrick)

## 💬 Community & Support

- [Telegram Updates Channel](https://t.me/samakshsdump)
- [Telegram Support Chat](https://t.me/samakshsbuilds)
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
- **MKSU** — [5ec1cff](https://github.com/5ec1cff/KernelSU)
- **SUSFS** — [simonpunk](https://gitlab.com/simonpunk/susfs4ksu), with the 6.1 GKI tree from [pershoot](https://gitlab.com/pershoot/susfs4ksu)
- **SUSFS Module** — [sidex15](https://github.com/sidex15)
- **Sultan Kernels** — [kerneltoast](https://github.com/kerneltoast)
- **ZeroMount** — [Enginex0](https://github.com/Enginex0/zeromount)
- **BORE and ADIOS** — Masahito Suzuki (firelzrd)
- **Boeffla wakelock blocker** — Andip71
- **Kernel Flasher and BBRv3 backport** — [fatalcoder524](https://github.com/fatalcoder524)
- **Baseband-Guard** — [vc-teahouse](https://github.com/vc-teahouse/Baseband-guard)

Thanks to all contributors, testers, and the Nothing community.

## ⭐ Like My Work?

If you found **Origin Kernel** useful, consider giving the repo a **star** on GitHub — it helps support the project!

## ⚠️ Disclaimer

Flashing a custom kernel involves inherent risks, including bootloops, data loss, or device failure. Unlocking the bootloader or modifying system software may also affect warranty or service eligibility.

Always back up your data and stock boot images before flashing. All three supported codenames share the same image per variant, but do not flash it on any other device.

**Proceed at your own risk.**
