#include <stdio.h>
#include <Windows.h>

#include "boost/shared_ptr.hpp"
#include "xcode_obfuscator.hpp"

#pragma comment(lib, "distorm/distorm.lib")

int main()
{
	ULONG module_base_address = (ULONG)(GetModuleHandleW(NULL));
	if (!module_base_address)
		printf("GetModuleHandle Failed %08X", GetLastError());

	XCodeObfuscator obfuscator_;

	printf("%08X \r\n", obfuscator_.GetSize(module_base_address, module_base_address + 0x40));

	getchar();
	return 0;
}