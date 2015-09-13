#ifndef _XCODE_MEM_GENERATOR_HPP
#define _XCODE_MEM_GENERATOR_HPP

#include <vector>

#include "xcode_obfuscator_utils.hpp"
#include "xcode_mem_manager.hpp"

class XObfuCodeGenerator
{
private:
	XObfuMemoryManager *obfu_mem_manager_;
	ULONG obfu_memory_id_;

public:
	XObfuCodeGenerator(XObfuMemoryManager *obfu_mem_manager);
	virtual ~XObfuCodeGenerator();

	ULONG __stdcall GetCodeSize(InstCodeVec &inst_code_buffer);
	HRESULT __stdcall Generate(InstCodeVec &inst_code_buffer);
};

typedef boost::shared_ptr<XObfuCodeGenerator> XObfuCodeGeneratorSharedPtr;

#endif