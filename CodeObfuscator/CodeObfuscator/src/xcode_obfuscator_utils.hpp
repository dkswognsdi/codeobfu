#ifndef _XCODE_OBFUSCATOR_UTILS_HPP
#define _XCODE_OBFUSCATOR_UTILS_HPP

#include <Windows.h>

#include "distorm/distorm.h"
#include "boost/shared_ptr.hpp"
#include "boost/foreach.hpp"

#include <vector>

#define GetPtr(x,y) (PVOID)((ULONG_PTR)(x) + (ULONG_PTR)(y))

typedef struct _INSTCODEINFO
{
	_DInst    inst;
	BOOL    support_check;
	ULONG    index;
	UCHAR    temp;
}INSTCODEINFO, *PINSTCODEINFO;


typedef std::vector<INSTCODEINFO> InstCodeVec;
typedef std::vector<INSTCODEINFO>::iterator InstCodeVit;

namespace XCodeUtils
{
	static HRESULT __stdcall DisasmEx(LPCVOID code, SIZE_T size, _DecodeType dt, _DInst *di)
	{
		UINT dc;
		_CodeInfo ci;

		ci.code = (PUCHAR)code;
		ci.codeLen = size;
		ci.codeOffset = (_OffsetType)(ULONG_PTR)code;
		ci.dt = dt;
		ci.features = DF_NONE;

		if (distorm_decompose64(&ci, di, 1, &dc) == DECRES_INPUTERR)
			return E_FAIL;

		if (dc != 1)
			return E_FAIL;

		return S_OK;
	}
};

#endif
