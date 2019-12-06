#ifndef HOSTUTILS_H
#define HOSTUTILS_H

#include <llvm/IR/Module.h>
#include <llvm/IR/Instructions.h>
#include <vector>

namespace mekong {

// Analysis Functions
void getKernelLaunches(llvm::Module &m, std::vector<std::pair<llvm::CallBase *, llvm::CallBase *>> &kernelLaunch);
void getLaunchArguments(llvm::Module &m, llvm::CallBase* configureCall, llvm::CallBase* launchCall, std::vector<llvm::Value*> &args);
llvm::Function *getCudaSynchronizeStream(llvm::Module &m);

// Transformation Functions
llvm::Value *createCudaGlobalVar(llvm::Module &m, const std::string name, llvm::Type *varType);
void registerKernel(llvm::Module &m, const std::string name, llvm::Function *kernelWrapper);
llvm::CallBase *replaceKernelCall(llvm::Module &m, llvm::CallBase *configureCall, llvm::CallBase *launchCall,
                                  llvm::Function *replacement, std::vector<llvm::Value *> &additionalArguments);
llvm::Function *createKernelWrapper(llvm::Module &m, const std::string name, llvm::FunctionType *ft);

}

#endif
