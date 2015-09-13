#include "xcode_analyzer.hpp"

XObfuCodeAnalyzer::XObfuCodeAnalyzer()
{
}

XObfuCodeAnalyzer::~XObfuCodeAnalyzer()
{
}

HRESULT 
__stdcall 
XObfuCodeAnalyzer::Analze(ULONG start, ULONG end)
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

InstCodeVec&
XObfuCodeAnalyzer::GetInstCodeBuffer()
{
	return inst_code_buffer_;
}