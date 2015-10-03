#include "xcode_analyzer.hpp"

XObfuCodeAnalyzer::XObfuCodeAnalyzer(XObfuMemoryManager *obfu_mem_manager)
:obfu_mem_manager_(obfu_mem_manager)
{
}

XObfuCodeAnalyzer::~XObfuCodeAnalyzer()
{
}

HRESULT 
__stdcall 
XObfuCodeAnalyzer::Analyze(ULONG start, ULONG end)
{
	PVOID ptr = (PVOID)(start);
	ULONG counter = 0;

	while ((ULONG)(ptr) <= end)
	{
		_DInst di;
		HRESULT s = XCodeUtils::DisasmEx(ptr, 64, Decode32Bits, &di);
		if (SUCCEEDED(s))
		{
			INSTCODEINFO instinfo;

			instinfo.inst = di;
			instinfo.support_check = TRUE;
			instinfo.index = counter;

			inst_code_buffer_.push_back(instinfo);
			ptr = GetPtr(ptr, di.size);
		}
		else
		{
			INSTCODEINFO instinfo;

			instinfo.temp = *(PUCHAR)(ptr);
			instinfo.support_check = FALSE;
			instinfo.index = counter;

			inst_code_buffer_.push_back(instinfo);
			ptr = GetPtr(ptr, 1);
		}
		counter++;
	}
	return S_OK;
}

BOOL 
XObfuCodeAnalyzer::IsSupportCode(const INSTCODEINFO &instcode_info)
{
	return instcode_info.support_check;
}

HRESULT
__stdcall
XObfuCodeAnalyzer::Analyze(const InstCodeVec & inst_code_vec)
{
	BOOST_FOREACH(const INSTCODEINFO &inst, inst_code_vec)
	{
		if (IsSupportCode(inst))
		{

		}
		else
		{

		}
	}
}

InstCodeVec&
XObfuCodeAnalyzer::GetInstCodeBuffer()
{
	return inst_code_buffer_;
}