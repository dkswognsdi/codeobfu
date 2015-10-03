#ifndef _XCODE_MEM_MANAGER_HPP
#define _XCODE_MEM_MANAGER_HPP

#include <vector>

#include "xcode_obfuscator_utils.hpp"

class XObfuMemoryManager
{
private:
	typedef struct _CODEMANAGERINFO
	{
		PVOID ptr;
		ULONG size;
		ULONG id;
	}CODEMANAGERINFO, *PCODEMANAGERINFO;

private:
	typedef std::vector<CODEMANAGERINFO> CodeManagerInfoVec;
	typedef std::vector<CODEMANAGERINFO>::iterator CodeManagerInfoVit;

	CodeManagerInfoVec code_info_vec_;

private:
	VOID Cleanup();

public:
	XObfuMemoryManager();
	virtual ~XObfuMemoryManager();

	BOOL __stdcall Append(ULONG size, ULONG id);

	BOOL __stdcall Delete(ULONG id);

	PVOID GetMemory(ULONG id);
	ULONG GetSize(ULONG id);
};

typedef boost::shared_ptr<XObfuMemoryManager> XObfuMemoryManagerSharedPtr;

#endif
