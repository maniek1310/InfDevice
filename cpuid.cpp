#include "cpuid.h"
#include "infdevice.h"

cpuid::cpuid()
{
}

void cpuid::view_info()
{
    unsigned long version_info = Ver_info();
    unsigned char Family;

    Family = (version_info & 0x0F00) >> 8;

    qDebug() << Family;
}

QString cpuid::VendorID()
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

    return VendorID;
}

QString cpuid::VendorID_name(QString vendorID)
{
         if(vendorID == "AuthenticAMD") return "AMD";
    else if(vendorID == "CentaurHauls") return "Centaur";
    else if(vendorID == "CyrixInstead") return "Cyrix";
    else if(vendorID == "GenuineIntel") return "Intel";
    else if(vendorID == "TransmetaCPU") return "Transmeta";
    else if(vendorID == "GenuineTMx86") return "Transmeta";
    else if(vendorID == "Geode by NSC") return "National Semiconductor";
    else if(vendorID == "NexGenDriven") return "NexGen";
    else if(vendorID == "RiseRiseRise") return "Rise";
    else if(vendorID == "SiS SiS SiS ") return "SiS";
    else if(vendorID == "UMC UMC UMC ") return "UMC";
    else if(vendorID == "VIA VIA VIA ") return "VIA";
    else if(vendorID == "Vortex86 SoC") return "Vortex";
    else if(vendorID == "KVMKVMKVMKVM") return "KVM";
    else if(vendorID == "Microsoft Hx") return "Microsoft Hyper-V";
    else if(vendorID == "VMwareVMware") return "VMware";
    else if(vendorID == "XenVMMXenVMM") return "Xen HVM";

    return "Unknown";
}

unsigned long cpuid::Ver_info()
{
    unsigned long VersionInfo;

    __asm
    {
        mov eax, 1
        cpuid
        mov VersionInfo, eax
    }

    return VersionInfo;
}
