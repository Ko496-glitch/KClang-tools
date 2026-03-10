#include "clang/Tooling/tools.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "KClang::visitor.cpp"
#include "KClang::consumer.cpp"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/dense_map.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"

using namespace clang;
namespace llvm;

namespace KClang{

  
  class KDiagnostic{

    private: 
      llvm::IntrusiveRefCntPtr<clang::DiagnosticOptions>DO;
      llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs>DI;
      std::unique_ptr<clang::DiagnosticEngine>DE;
      std::unique_ptr
  
    public:

  };


}
