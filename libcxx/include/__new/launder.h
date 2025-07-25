//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___NEW_LAUNDER_H
#define _LIBCPP___NEW_LAUNDER_H

#include <__config>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD
template <class _Tp>
[[__nodiscard__]] inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR _Tp* __launder(_Tp* __p) _NOEXCEPT {
  // The compiler diagnoses misuses of __builtin_launder, so we don't need to add any static_asserts
  // to implement the Mandates.
  return __builtin_launder(__p);
}

#if _LIBCPP_STD_VER >= 17
template <class _Tp>
[[nodiscard]] inline _LIBCPP_HIDE_FROM_ABI constexpr _Tp* launder(_Tp* __p) noexcept {
  return __builtin_launder(__p);
}
#endif
_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___NEW_LAUNDER_H
