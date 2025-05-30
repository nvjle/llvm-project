//===- RegisterOpenACCExtensions.h - OpenACC Extension Registration --===--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef FLANG_OPTIMIZER_OPENACC_REGISTEROPENACCEXTENSIONS_H_
#define FLANG_OPTIMIZER_OPENACC_REGISTEROPENACCEXTENSIONS_H_

namespace mlir {
class DialectRegistry;
} // namespace mlir

namespace fir::acc {

void registerOpenACCExtensions(mlir::DialectRegistry &registry);

/// Register external models for FIR attributes related to OpenACC.
void registerAttrsExtensions(mlir::DialectRegistry &registry);

/// Register all dialects whose operations may be created
/// by the transformational attributes.
void registerTransformationalAttrsDependentDialects(
    mlir::DialectRegistry &registry);

} // namespace fir::acc

#endif // FLANG_OPTIMIZER_OPENACC_REGISTEROPENACCEXTENSIONS_H_
