#ifndef _XCODE_OBFUSCATOR_HPP
#define _XCODE_OBFUSCATOR_HPP

#include "xcode_obfuscator_utils.hpp"

#include "xcode_analyzer.hpp"
#include "xcode_mem_generator.hpp"
#include "xcode_mem_manager.hpp"

class XCodeObfuscator
{
private:
	XObfuCodeAnalyzerSharedPtr		analyzer_;
	XObfuMemoryManagerSharedPtr		mem_manager_;
	XObfuCodeGeneratorSharedPtr		generator_;

public:
	XCodeObfuscator();
	virtual ~XCodeObfuscator();

	ULONG GetSize(ULONG start, ULONG end);
};


#endif