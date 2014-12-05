#ifndef CPUID_H
#define CPUID_H

#include "infdevice.h"
#include "ui_infdevice.h"
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__rdtsc)

class cpuid
{
public:
    cpuid();
    static void view_info();
    static QString VendorID();
    static QString Brand();
    static QString VendorID_name(QString vendorID);
    static unsigned long Ver_info();
    static unsigned long Fea_info_edx();
    static unsigned long Fea_info_ecx();
    static unsigned long ext_family();
    static unsigned long socket();
    static unsigned long cache_l1_data();
    static unsigned long cache_l1_code();
    static unsigned long cache_l2();
    static unsigned long cache_l3();
};

#endif // CPUID_H
