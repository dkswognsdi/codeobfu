#ifndef _XCODE_ANALYZER_HPP
#define _XCODE_ANALYZER_HPP

#include <vector>

#include "xcode_obfuscator_utils.hpp"

class XObfuCodeAnalyzer
{
	InstCodeVec inst_code_buffer_;

public:
	XObfuCodeAnalyzer();
	virtual ~XObfuCodeAnalyzer();

	HRESULT __stdcall Analze(ULONG start, ULONG end);
	InstCodeVec &GetInstCodeBuffer();
};

typedef boost::shared_ptr<XObfuCodeAnalyzer> XObfuCodeAnalyzerSharedPtr;

#endif

