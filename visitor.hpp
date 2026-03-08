#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/SourceManager.h"
#include "clang/AST/decl.h"
#include "clang/AST/Expr.h"



namespace KClang{

	class CallVisitor: public clang::RecursiveAASTVisitor<CallVisitor>{

		private:
			clang::ASTContext *Context;
		public:
			CallVisitor(clang::ASTContext *Context): Context(Context){} 


	};
}


