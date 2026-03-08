#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/SourceManager.h"
#include "clang/AST/decl.h"
#include "clang/AST/Expr.h"


using namespace clang;
using namespace llvm;

/*
Traverse the AST, check if node == CallExpr
1)if yes then check the callee, ask for the location from SourceLocation and update the llvm::denseMap
2) move ahead
*/

namespace KClang{


  class FunctionInfo{
      
    public:

      llvm::StringRef name;
      llvm::StringRef file;
      uint16_t line;
      uint16_t column;

  };

	class CallVisitor: public clang::RecursiveAASTVisitor<CallVisitor>{

		private:

			clang::ASTContext *Context;

      llvm::DenseMap<const clang::FunctionDecl*, FunctionInfo>HMap;

    public:

			CallVisitor(clang::ASTContext *Context): Context(Context){} 
      
      bool VisitCallExpr(clang::CallExpr *S){
        
        if(const clang::FunctionDecl *FD = S->getDirectCallee()){

          llvm::StringRef name = FD->getNameAsString();

          llvm::StringRef FullQualifiedName = getQualifiedNameAsString();

          clang::SourceLocation loc = FD->getLocation();

          clang::SourceManager &Full_loc = Context->getSourceManager();

          clang::PresumeLoc PLoc = FD->PresumeLoc(loc);

          if(PLoc.isValid()){
            
            llvm::StringRef &file = PLoc.getFileName();
            uint16_t line = PLoc.getLine();
            uint16_t col = PLoc.getColumn();

          }
          
          auto it = HMap.find(FD);
          
          if(it == HMap.end()){

            FunctionInfo *info;
            info->name = name;
            info->file = file;
            info->line = line;
            info->col  = col;

            HMap.insert(info);

          }else{

            ++HMap[FD];
          }

          return true;

        }

	};
}


