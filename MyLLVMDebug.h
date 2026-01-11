//============================== MyLLVMDebug.h - My LLVM Debug Utils -*- C++ -*-===//
// 
//
//=================================================================================//

#ifndef  LLVM_MY_LLVM_DEBUG_H
#define  LLVM_MY_LLVM_DEBUG_H

#include "llvm/IR/Value.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/Instruction.h"
#include "llvm/ADT/SetVector.h"

namespace llvm {

void __attribute__((noinline)) __attribute__((used)) 
DumpDCEWorkList(SmallSetVector<Instruction *, 16> &C, StringRef Label = "DCE WorkList") {
    errs() << "\n[DEBUG] --- " << Label << " (Size: " << C.size() << ") ---\n";
    int Index = 0;
    for (const auto *Item : C) {
        errs() << "[" << Index++ << "] ";
        if (Item) {
            Item->print(errs());
        } else {
            errs() << "nullptr";
        }
        errs() << "\n";
    }
    errs() << "[DEBUG] ----------------------------------\n";
}

}
#endif