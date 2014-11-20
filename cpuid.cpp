#include "cpuid.h"

cpuid::cpuid()
{
}

cpuid::VendorID()
{
    char VendorID[13];

    __asm
    {
        mov eax, 0
        cpuid
        mov dword ptr [VendorID], ebx
        mov dword ptr [VendorID+4], edx
        mov dword ptr [VendorID+8], ecx
        mov byte ptr [VendorID+12], 0
    }

    qDebug() << VendorID;

    return VendorID;
}
