#include "llvm-project/llvm/include/llvm/ADT/ArrayRef.h"
#include "llvm-project/llvm/include/llvm/IR/BasicBlock.h"
#include "llvm-project/llvm/include/llvm/IR/DerivedType.h"
#include "llvm-project/llvm/include/llvm/IR/Function.h"
#include "llvm-project/llvm/include/llvm/IR/Context.h"
#include "llvm-project/llvm/include/llvm/IR/Module.cpp"

llvm::LLVMContext Context;

std::unique_ptr<llvm::Module> MyModule(LLVMContext &Context){

    //Poulating all the types needed in the code below

    /*
    extern int baz();
    extern void bar(int);

    void foo(int a, int b){
        int var = a+b;
        if(var == 0xFF){
            bar(var);
            var = baz();
        }
        bar(var);
    }

    -------------------------IR Code for this would be-----------------------------------------

    define void @foo(i32 %arg, i32 %arg1){
        bb1:
            %var = add i32 %a &b
            %cmp = icmp eq i32 %var, 255
            %i  = alloc i32
            %i1 = alloc i32
            %i2 = alloc i32
    }
    */

    Type* Int32Ty  = Type::getInt32Ty(Context);
    Type* VoidTy   = Type::getVoidTy(Context);
    Type* PtrTy    = PointerType::get(Context, 0);


   // Creating Module
    std::make_unque<llvm::Module> MyModule = std::make_unique<llvm::Module>("My_Module",Context);

   // Populate all the declarations
   // Starting with Baz
   FunctionType *bazTy = llvm::FunctionType::get(Int32Ty,ArrayRef<Int32Ty>,false);
   Function *bazFunc   = cast<Function>(MyModule->getOrInsertFunction("baz",BarTy).getCallee());

   //extern void bar();
   FunctionType *barTy   = llvm::FunctionType::get(VoidTy, ArrayRef<VoidTy>, false);
   Function     *barFunc = cast<Function>(MyModule->getOrInsertFunction("bar", barTy).getCallee());

   //int foo(){}
   FunctionType *fooTy = llvm::Function::get(VoidTy, ArrayRef<VoidTy, Int32Ty>, false);
   Function *fooFunc   = cast<Function>(MyModule->getOrInsertFunction("foo", fooTy).getCallee());
   
   


   //After creating the function we move on to create the basic BasicBlock, for foo we would create 3 basic blocks
   auto *BB1 = BasicBlock::create(Context, "bb1", fooFunc);
   auto *BB2 = BasicBlock::create(Context, "bb2", fooFunc);
   auto *BB3 = BasicBlock::create(Context, "bb3", fooFunc);

  // Now we work on the instructions, first we invoke the IR Builder
  
  IRBuilder Builder(BB);

  Value *I1 = Builder.CreateAlloc(Int32Ty); // a
  Value *I2 = Builder.CreateAlloc(Int32Ty); // b
  Value *I3 = Builder.CreateAlloc(Int32Ty); // var
  
  Value *Arg  = fooFunc->getArg(0);
  Value *Arg1 = fooFunc->getArg(1);

  Builder.CreateStore(Arg, I1);
  Builder.CreateStore(Arg1, I2);
  

}

int main(){

    return 0;
}
