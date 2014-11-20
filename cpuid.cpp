#include "cpuid.h"

cpuid::cpuid()
{
}

void cpuid::view_info()
{
    unsigned long version_info = Ver_info();
    unsigned char Family;
    unsigned char fpu;

    fpu = (version_info & 0x1);

    Family = (version_info & 0x0F00) >> 8;

    qDebug() << Family;

    qDebug() << Brand();

    qDebug() << "FPU : " << fpu;

    //InfDevice::ui->pushButton->setText("fsdf");
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

unsigned long cpuid::Fea_info()
{
    unsigned long FeatureInfo;

    __asm
    {
        mov eax, 1
        cpuid
        mov FeatureInfo, edx
    }

    return FeatureInfo;
}

QString cpuid::Brand()
{
    char Parts[48];

    long unsigned Check;

    __asm
    {
        mov EAX, 0x80000000
        cpuid
        mov Check, EAX
    }

    if(Check < 0x8000000)
        return "Unknown";

    __asm
    {
        // Pierwsza część nazwy procesora
        mov EAX, 0x80000002
        cpuid

        // Pobieranie wszystkich bajtów z EAX
        mov Parts[0], al
        mov Parts[1], ah
        shr EAX, 16
        mov Parts[2], al
        mov Parts[3], ah
        // Pobieranie wszystkich bajtów z EBX
        mov Parts[4], bl
        mov Parts[5], bh
        shr EBX, 16
        mov Parts[6], bl
        mov Parts[7], bh
        // Pobieranie wszystkich bajtów z ECX
        mov Parts[8], cl
        mov Parts[9], ch
        shr ECX, 16
        mov Parts[10], cl
        mov Parts[11], ch
        // Pobieranie wszystkich bajtów z EDX
        mov Parts[12], dl
        mov Parts[13], dh
        shr EDX, 16
        mov Parts[14], dl
        mov Parts[15], dh

        // Druga część nazwy procesora
        mov EAX, 0x80000003
        CPUID

        // Pobieranie wszystkich bajtów z EAX
        mov Parts[16], al
        mov Parts[17], ah
        shr EAX, 16
        mov Parts[18], al
        mov Parts[19], ah
        // Pobieranie wszystkich bajtów z EBX
        mov Parts[20], bl
        mov Parts[21], bh
        shr EBX, 16
        mov Parts[22], bl
        mov Parts[23], bh
        // Pobieranie wszystkich bajtów z ECX
        mov Parts[24], cl
        mov Parts[25], ch
        shr ECX, 16
        mov Parts[26], cl
        mov Parts[27], ch
        // Pobieranie wszystkich bajtów z EDX
        mov Parts[28], dl
        mov Parts[29], dh
        shr EDX, 16
        mov Parts[30], dl
        mov Parts[31], dh

        // Trzecia część nazwy procesora
        mov EAX, 0x80000004
        CPUID

        // Pobieranie wszystkich bajtów z EAX
        mov Parts[32], al
        mov Parts[33], ah
        shr EAX, 16
        mov Parts[34], al
        mov Parts[35], ah
        // Pobieranie wszystkich bajtów z EBX
        mov Parts[36], bl
        mov Parts[37], bh
        shr EBX, 16
        mov Parts[38], bl
        mov Parts[39], bh
        // Pobieranie wszystkich bajtów z ECX
        mov Parts[40], cl
        mov Parts[41], ch
        shr ECX, 16
        mov Parts[42], cl
        mov Parts[43], ch
        // Pobieranie wszystkich bajtów z EDX
        mov Parts[44], dl
        mov Parts[45], dh
        shr EDX, 16
        mov Parts[46], dl
        mov Parts[47], dh
    }

    return Parts;
}
