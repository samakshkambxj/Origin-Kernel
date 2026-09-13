// SPDX-License-Identifier: GPL-2.0

#include <uapi/asm-generic/errno.h>

typeof(__cvdso_getrandom) __kernel_getrandom;

ssize_t __kernel_getrandom(void *buffer, size_t len, unsigned int flags, void *opaque_state, size_t opaque_len)
{
	/*
	 * 6.1 backport: upstream gates the ChaCha path on
	 * alternative_has_cap_likely(ARM64_HAS_FPSIMD), but 6.1 has neither
	 * that helper (its API is alternative_has_feature_likely) nor the
	 * ARM64_HAS_FPSIMD cpucap (it only tracks the inverse,
	 * ARM64_HAS_NO_FPSIMD). FP/ASIMD is architecturally mandatory on
	 * ARMv8 application processors, so the NEON ChaCha path is always
	 * valid here; call straight through. All other failure modes still
	 * fall back to the syscall inside __cvdso_getrandom().
	 */
	return __cvdso_getrandom(buffer, len, flags, opaque_state, opaque_len);
}
