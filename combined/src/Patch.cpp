#include "PatchAPI.hpp"


DWORD returnAddr = 0;


/// Patch addresses
CONST DWORD addr_MyAsmPatch = 0x413ACA;
CONST DWORD addr_MyRawPatch = 0x404072;


/// Executable functions
CONST DWORD func_SomeFunction1 = 0x59F1B0;
CONST DWORD func_SomeFunction2 = 0x51E960;
CONST DWORD func_SomeFunction3 = 0x4DC6C0;


/// Executable variables
CONST DWORD addr_SomeVar1 = 0x633E04;

DWORD* CONST var_SomeVar2 = (DWORD*) 0x16D2768;


/// DLL variables
DWORD exeProcId = 0;
DWORD someVar3 = 0;


/// Injected functions

__declspec(naked) void MyAsmPatch(void)
{
  __asm
  {
    pop returnAddr

    PUSHAD
    PUSHFD

    CALL [func_SomeFunction1]
  }

  *var_SomeVar2 = 1;

  if ( *(DWORD*) addr_SomeVar1 == 0 )
  {
    __asm
    {
      CALL [func_SomeFunction2]
    }

    *(DWORD*) addr_SomeVar1 = 1;
    someVar3 = 1;
  }

  __asm
  {
    POPFD
    POPAD

    CALL [func_SomeFunction3]

    push returnAddr
    ret
  }
}


void PatchInit()
{
  InjectCode(addr_MyAsmPatch, MyAsmPatch, 0);

  {
    BYTE patch[] = { 0x90, 0x90 };
    WriteBytesASM(addr_MyRawPatch, patch, 2);
  }

  exeProcId = GetCurrentProcessId();
}
