#ifndef UPOWERDEVICE_H
#define UPOWERDEVICE_H

#include <QDBusFreedesktopProperty.h>

class UPowerDevice
{
public:
    UPowerDevice(QString path);

    enum Type {
        UnknownType = 0,
        LinePower = 1,
        Battery = 2,
        Ups = 3,
        Monitor = 4,
        Mouse = 5,
        Keyboard = 6,
        Pda = 7,
        Phone = 8
    };

    enum State {
        UnknownState = 0,
        Charging = 1,
        Discharging = 2,
        Empty = 3,
        FullyCharged = 4,
        PendingCharge = 5,
        PendingDischarge = 6
    };

    Type type();
    State state();
    QString name();
    double percentage();
    quint32 timeToFull(); // in minutes
    quint32 timeToEmpty(); // in minutes

private:
    QDBusFreedesktopInterfaceManager m_interfaceManager;
    QDBusFreedesktopInterface m_interface;

    QDBusFreedesktopProperty m_nativePath;
    QDBusFreedesktopProperty m_type;
    QDBusFreedesktopProperty m_timeToFull;
    QDBusFreedesktopProperty m_timeToEmpty;
    QDBusFreedesktopProperty m_percentage;
    QDBusFreedesktopProperty m_state;
};

#endif // UPOWERDEVICE_H
