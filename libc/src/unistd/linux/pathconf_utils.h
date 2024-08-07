//===-- Implementation header for pathconf_utils ----------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_UNISTD_PATHCONF_UTILS_H
#define LLVM_LIBC_SRC_UNISTD_PATHCONF_UTILS_H

#include "src/sys/statvfs/linux/statfs_utils.h"

namespace LIBC_NAMESPACE {

long pathconfig(const statfs_utils::LinuxStatFs &s, int name);

} // namespace LIBC_NAMESPACE

#endif // LLVM_LIBC_SRC_UNISTD_PREAD_H
