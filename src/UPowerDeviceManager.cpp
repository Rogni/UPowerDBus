#include <UPowerDeviceManager.h>

const QString UPOWER_INTERFACE_NAME = "org.freedesktop.UPower";
const QString UPOWER_INTERFACE_PATH = "/org/freedesktop/UPower";

UPowerDeviceManager::UPowerDeviceManager(QObject *parent):
    QDBusAbstractInterface(UPOWER_INTERFACE_NAME,
                           UPOWER_INTERFACE_PATH,
                           staticInterfaceName(),
                           QDBusConnection::systemBus(),
                           parent),
    m_interfaceManager(UPOWER_INTERFACE_NAME,
                       UPOWER_INTERFACE_PATH,
                       QDBusConnection::systemBus()),
    m_interface(&m_interfaceManager, UPOWER_INTERFACE_NAME),
    m_onBattery(&m_interface, "OnBattery")
{

}

bool UPowerDeviceManager::onBattery()
{
    return m_onBattery.get().toBool();
}
