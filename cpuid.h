#ifndef CPUID_H
#define CPUID_H

#include "infdevice.h"

class cpuid
{
public:
    cpuid();
    static void view_info();
    static QString VendorID();
    static QString VendorID_name(QString vendorID);
    static unsigned long Ver_info();
};

#endif // CPUID_H
