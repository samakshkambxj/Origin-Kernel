Origin Kernel v3 Changelog

Changelog from v2:

New Features:
Capacity Aware Superset Scheduler with its full upstream fix series
BORE CPU scheduler support, with CASS remaining the default
ADIOS I/O scheduler enabled as the default
Baseband-Guard LSM that blocks baseband writes from formatting storage
OriginSU with SUSFS, Origin Veil and KPM built into the Reforged variant
ZeroMount VFS path redirection for per-process mounts
CAKE, PIE and FQ-PIE queue disciplines with FQ-PIE as the default
TTL target support for IPv4
BIC, Westwood and HTCP TCP congestion algorithms
DAMON reclaim and LRU sorting with physical address monitoring
ZRAM built into the kernel with multi-compression, writeback and memory tracking
EROFS LZMA and ZSTD compression
Clang full LTO in place of thin LTO
Workqueue power efficiency enabled by default
GKI task struct vendor size raised to 1024 bytes
QUOTA netlink interface, SAFESETID and Android WRAPFD
Separate Origin-Reforged and Origin-Vanilla releases, both tagged in the kernel release string
GitHub Actions builds for Reforged, Vanilla or both

Scheduler and power:
CASS avoids the prime CPU and the idle load balancer, honours uclamp, spreads load correctly on throttled CPUs and handles RT wakeups
CACHE_HOT_BUDDY disabled to keep the idle CPU scan cheap
Idle capacity scan starts after the target CPU
Per-cluster limit on scaling_min_freq
Boeffla wakelock blocker
Wakelocks acquired without a timeout expire instead of pinning the device awake
s2idle enters once per suspend attempt and drops the retry loop
Suspend aborts kick the wakeup path once instead of looping
Freezer timeout reduced to 1 second
Alarm timer wakes the system when the next alarm expires
PCI PME wakeups polled every 4 seconds

Memory and storage:
f2fs GC thread sleeps a minimum of 50 ms and the urgent path sleeps 50 ms
f2fs minimum fsync blocks raised to 200
f2fs congestion wait shortened to 6 ms
vfs_cache_pressure lowered to 50
jbd2 default commit age raised to 30 seconds
struct file aligned to 8 bytes
ZRAM recompression can allocate CMA pages

Networking:
Default socket buffer limits raised by 4x

Core and architecture:
arm64 memcmp, clear_page and copy_template optimised, with source prefetch in copy_template
Generic memset, memcpy and memmove optimised in lib/string
Unicode normalization bypass for empty decompositions fixed
healthd, logd and dashd messages dropped from /dev/kmsg
set affinity failed demoted to debug
Duplicate vvar_pages enum and duplicate swap vendor hook declarations removed

Backported Upstream Fixes:
Linux 6.1.145 through 6.1.182
Android Common Kernel android14-6.1.182_r00
Android Common Kernel android14-6.1.177_r00 and r01
Android Security Bulletin 2026-03 releases r10 through r25
Android Security Bulletin 2026-06 releases r1 through r20
Android Security Bulletin 2026-09 releases r1 through r8
