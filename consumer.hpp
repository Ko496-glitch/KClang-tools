#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/decl.h"
#include "clang/AST/ASTConsumer.h"
#include "visitor.hpp"



using namespace clang;
using namespace llvm;


/*

  Consumer just store visitor and feed ASTContext to it.

  ASTContext contains 1) All AST nodes
                      2) Source location and Source Manager
                      3) Memory allocator
  this is enough for us to make it work :)


 */

namespace KClang{

  class Consumer: public clang::ASTConsumer{

    private:

      CallVisitor Visitor;

    public:

      Consumer(clang::ASTContext *Context): Visitor(Context){}

      void HandleTranslationUnit(clang::ASTContext *Context){
          
          Visitor.TraverseDecl(Context.getTranslatinUnitDecl);

      }

  };
  
  
}
