#ifndef _XCODE_ANALYZER_HPP
#define _XCODE_ANALYZER_HPP

#include <vector>

#include "xcode_obfuscator_utils.hpp"
#include "xcode_mem_manager.hpp"

class XObfuCodeAnalyzer
{
private:
	XObfuMemoryManager *obfu_mem_manager_;
	InstCodeVec inst_code_buffer_;

public:
	XObfuCodeAnalyzer(XObfuMemoryManager *obfu_mem_manager);
	virtual ~XObfuCodeAnalyzer();

private:
	BOOL IsSupportCode(_In_ const INSTCODEINFO &instcode_info);

public:
	HRESULT __stdcall Analyze(_In_ ULONG start, _In_ ULONG end);			//instcodebuffer generator
	HRESULT __stdcall Analyze(_In_ const InstCodeVec &inst_code_vec); //instcodebuffer analyze

public:
	InstCodeVec &GetInstCodeBuffer();
};

typedef boost::shared_ptr<XObfuCodeAnalyzer> XObfuCodeAnalyzerSharedPtr;

#endif

