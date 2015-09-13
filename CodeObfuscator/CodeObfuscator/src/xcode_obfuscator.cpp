#include "xcode_obfuscator.hpp"
#include "boost/make_shared.hpp"

XCodeObfuscator::XCodeObfuscator()
{
	analyzer_		= boost::make_shared<XObfuCodeAnalyzer>();
	mem_manager_	= boost::make_shared<XObfuMemoryManager>();
	generator_		= boost::make_shared<XObfuCodeGenerator>(mem_manager_.get());
}

XCodeObfuscator::~XCodeObfuscator()
{
}

ULONG
XCodeObfuscator::GetSize(ULONG start, ULONG end)
{
	HRESULT status = analyzer_->Analze(start, end);
	if (!SUCCEEDED(status))
		return -1;

	return generator_->GetCodeSize(analyzer_->GetInstCodeBuffer());
}