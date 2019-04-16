#include "UPowerDeviceManager.h"


UPowerDeviceManager::UPowerDeviceManager(QObject *parent):
    QDBusAbstractInterface("org.freedesktop.UPower", "/org/freedesktop/UPower",  staticInterfaceName(), QDBusConnection::systemBus(), parent)
{

}
