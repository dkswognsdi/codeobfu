#include "xcode_mem_generator.hpp"

XObfuCodeGenerator::XObfuCodeGenerator(XObfuMemoryManager *obfu_mem_manager)
:obfu_mem_manager_(obfu_mem_manager), obfu_memory_id_(0)
{
}

XObfuCodeGenerator::~XObfuCodeGenerator()
{
}


ULONG 
__stdcall 
XObfuCodeGenerator::GetCodeSize(InstCodeVec &inst_code_buffer)
{
	ULONG result = 0;
	InstCodeVit    it = inst_code_buffer.begin();
	InstCodeVit    end = inst_code_buffer.end();

	for (; it != end; ++it)
	{
		INSTCODEINFO inst_code_info = (*it);
		if (inst_code_info.support_check == FALSE)
			result += 10;
		else
			result += 100;
	}

	return result;
}
HRESULT 
__stdcall 
XObfuCodeGenerator::Generate(InstCodeVec &inst_code_buffer)
{
	ULONG code_size = GetCodeSize(inst_code_buffer);
	if (code_size >= (4096 * 100)) //100MB
		return E_FAIL;

	HRESULT status = obfu_mem_manager_->Append(code_size, obfu_memory_id_);
	if (!SUCCEEDED(status))
		return status;

	obfu_memory_id_++;

	return S_OK;
}