//
// Created by Sebastian on 31.07.2022.
//

#pragma once
#include "llvm/IR/Value.h"
#include <memory>

class ExprAST;
class PrototypeAST;

std::unique_ptr<ExprAST> LogError(const char *Str);

std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);

llvm::Value *LogErrorV(const char *Str);