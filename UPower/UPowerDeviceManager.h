#ifndef UPOWERDEVICEMANAGER_H
#define UPOWERDEVICEMANAGER_H

#include <QtDBus/QtDBus>
#include "QDBusFreedesktopProperty.h"

class UPowerDeviceManager: public QDBusAbstractInterface
{
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.UPower"; }

    UPowerDeviceManager(QObject *parent = nullptr);


    bool onBattery();

public Q_SLOTS:
    /*QDBusObjectPath*/
    inline QDBusPendingReply<QList<QDBusObjectPath>> EnumerateDevices()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("EnumerateDevices"), argumentList);
    }

Q_SIGNALS:

private:
    QDBusFreedesktopInterfaceManager m_interfaceManager;
    QDBusFreedesktopInterface m_interface;

    QDBusFreedesktopProperty m_onBattery;

};

#endif // UPOWERDEVICEMANAGER_H
