# Origin Kernel v3 Changelog

**The kernel is now Unified - i.e one Image for all 3 devices :- Tetris, Galaga and Galaxian.**

## Changelog from v2:
- Upstreamed to 6.1.182 (from android14-6.1.182_r00, November 2026 ASB)
- Migrated to [OriginSU](https://github.com/samakshkambxj/OriginSU) - custom fork of ReSukiSU designed specifically for Origin Kernel itself.
- Bumped SUSFS to v2.4.0
- Switched to Full LTO for better performance
- Upgraded Compiler to Neutron Clang v24.0
- Dropped MemKernel driver
Improved CASS with the full upstream fix series
- Introduced Origin-Vanilla - a rootless variant for custom ROM builds

## New Features:
- Integrated Origin Veil - kernel side root probe monitoring and per-uid mount cloaking
- Enabled KPM (Kernel Patch Module) loading with KALLSYMS_ALL
- Integrated [ZeroMount](https://github.com/Enginex0/zeromount) VFS driver
- Integrated BORE and ADIOS I/O scheduler
- Integrated Boeffla Wakelock Blocker
- Enabled WQ power efficiency
- Enabled ZRAM multi compression, writeback and memory tracking
- Enabled DAMON reclaim and LRU sorting
- Enabled EROFS Zstandard compression
- Enabled TTL target, CAKE, PIE and FQ-PIE as default qdisc

## Backported Upstream Fixes:
- ZRAM — multi-stream compression for better ratios, plus recompression support.
- f2fs — inline inode handling, compress cache validation, ACL fixes, write I/O UAF prevention.
- ext4 — inline data bounds checking, superblock update checks, DAX restrictions on encrypted files.
- mm — percpu bitmap overflow, page reporting UAF during suspend, vmalloc ptdump UAF, huge_zero_pfn race.
- Scheduler — deadline migration warnings, RT push task race, PSI timer shutdown for power savings.
- Network — IGMP UAF prevention, bridge multicast UAF fix, BBRv3 with Android KABI compliance.
- Core — fchmodat2(), cachestat(), vDSO getrandom(), SCS unwinder fixes and optimized memcmp/memcpy/memset.
- Vendor hooks — memcg PSI recording skip, migration batch hooks, direct reclaim hooks.
