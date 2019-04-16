#ifndef UPOWERDEVICEMANAGER_H
#define UPOWERDEVICEMANAGER_H

#include <QtDBus/QtDBus>

class UPowerDeviceManager: public QDBusAbstractInterface
{
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.UPower"; }

    UPowerDeviceManager(QObject *parent = nullptr);


public Q_SLOTS:
    /*QDBusObjectPath*/
    inline QDBusPendingReply<QList<QDBusObjectPath>> EnumerateDevices()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("EnumerateDevices"), argumentList);
    }

Q_SIGNALS:

};

#endif // UPOWERDEVICEMANAGER_H
