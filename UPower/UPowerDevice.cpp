#include "UPowerDevice.h"
#include <QDebug>

UPowerDevice::UPowerDevice(QString path):
    m_interfaceManager("org.freedesktop.UPower",
                       path,
                       QDBusConnection::systemBus()),
    m_interface(&m_interfaceManager, "org.freedesktop.UPower.Device"),
    m_nativePath(&m_interface, "NativePath"),
    m_type(&m_interface, "Type"),
    m_timeToFull(&m_interface, "TimeToFull"),
    m_timeToEmpty(&m_interface, "TimeToEmpty"),
    m_percentage(&m_interface, "Percentage")
{

}

UPowerDevice::Type UPowerDevice::type()
{
    return static_cast<Type>(m_type.get().toUInt());
}

QString UPowerDevice::name()
{
    return m_nativePath.get().toString();
}

double UPowerDevice::percentage()
{
    return  m_percentage.get().toDouble();
}

quint32 UPowerDevice::timeToFull()
{
    return static_cast<quint32>( m_timeToFull.get().toInt() / 60 );
}

quint32 UPowerDevice::timeToEmpty()
{
    return static_cast<quint32>( m_timeToEmpty.get().toInt() / 60 );
}
