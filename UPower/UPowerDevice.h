#ifndef UPOWERDEVICE_H
#define UPOWERDEVICE_H

#include "QDBusFreedesktopProperty.h"

class UPowerDevice
{
public:
    UPowerDevice(QString path);

    enum Type {
        Unknown = 0,
        LinePower = 1,
        Battery = 2,
        Ups = 3,
        Monitor = 4,
        Mouse = 5,
        Keyboard = 6,
        Pda = 7,
        Phone = 8
    };

    Type type();
    QString name();
    quint8 percentage();


private:
    QDBusFreedesktopInterfaceManager m_interfaceManager;
    QDBusFreedesktopInterface m_interface;

    QDBusFreedesktopProperty m_nativePath;
    QDBusFreedesktopProperty m_type;
    QDBusFreedesktopProperty m_timeToFull;
    QDBusFreedesktopProperty m_timeToEmpty;
    QDBusFreedesktopProperty m_percentage;
};

#endif // UPOWERDEVICE_H
