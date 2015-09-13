#include "xcode_mem_manager.hpp"

XObfuMemoryManager::XObfuMemoryManager()
{
}

XObfuMemoryManager::~XObfuMemoryManager()
{
	Cleanup();
}

VOID
XObfuMemoryManager::Cleanup()
{
	CodeManagerInfoVit it = code_info_vec_.begin();
	CodeManagerInfoVit end = code_info_vec_.end();

	for (; it != end; ++it)
	{
		CODEMANAGERINFO cm_info = (*it);
		if (cm_info.ptr)
			VirtualFree(cm_info.ptr, cm_info.size, MEM_DECOMMIT | MEM_RELEASE);
	}
}

BOOL 
__stdcall 
XObfuMemoryManager::Append(ULONG size, ULONG id)
{
	PVOID ptr = VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!ptr)
		return FALSE;

	CODEMANAGERINFO info;
	info.ptr = ptr;
	info.size = size;
	info.id = id;

	code_info_vec_.push_back(info);
	return TRUE;
}

BOOL 
__stdcall 
XObfuMemoryManager::Delete(ULONG id)
{
	CodeManagerInfoVit it = code_info_vec_.begin();
	CodeManagerInfoVit end = code_info_vec_.end();

	for (; it != end; ++it)
	{
		CODEMANAGERINFO cm_info = (*it);
		if (cm_info.ptr && cm_info.id == id)
		{
			VirtualFree(cm_info.ptr, cm_info.size, MEM_DECOMMIT | MEM_RELEASE);
			code_info_vec_.erase(it);
			return TRUE;
		}
	}
	return FALSE;
}