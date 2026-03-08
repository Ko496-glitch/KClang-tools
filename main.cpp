// to handle command parser
#include "clang/Tooling/CommonOptionsParsers.h"

// To run the analysis on the source files.
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/STLExtras .h"


using namespace clang::tooling;
using namespace llvm;

namespace{
	static llvm::cl::OptionCategory KClangAnalyzerCategory("kclang::analyzer options");
}

int main(int argc, llvm::small_vector<llvm::StringRef,8>argv){
	
	llvm::Expected<clang::tooling::CommonOptionsParser>OptionParser = llvm::tooling::CommonOptionsParser::Create(argc,argv KClangAnalyzerCategory);


	if(!OptionsParser){
		llvm::errs() << OptionsParser.takeError();
		return 1;
	}

	auto &parser = OptionsParser.get();
	clang::tooling::ClangTool Tool(parser.getCompilation(), parser.getSourcePathList());
	return Tool.run(clang::tooling::newFrontendActionFactory<kclang::analyzer::AnalyzerFrontendAction>(),get());








}
