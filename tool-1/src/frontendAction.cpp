#include "clang/Frontend/FrontendAction.h"
#include "clang/Frontend/CompilerInstance.h"
#include <memory>

using namespace clang;
using namespace llvm;


namespace KClang{

  class Frontend : public clang::ASTFrontendAction{

    private:

      std::unique_ptr<Visitor>V;
    
    public:

      Frontend(std::make_unique<Visitor()>V): Frontend(V){}

      std::unique_ptr<clang::ASTConsumer>CreateASTConsumer(clang::CompilerInstance &CI, llvm::StringRef InFile) override {
        
        return std::make_unique<AnalyzerConsumer>(CI.getASTContext());

      }

  };
  

};
