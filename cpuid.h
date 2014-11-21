#ifndef CPUID_H
#define CPUID_H

#include "infdevice.h"
#include "ui_infdevice.h"

class cpuid
{
public:
    cpuid();
    static void view_info();
    static QString VendorID();
    static QString VendorID_name(QString vendorID);
    static unsigned long Ver_info();
    static unsigned long Fea_info_edx();
    static unsigned long Fea_info_ecx();
    static QString Brand();
};

#endif // CPUID_H
