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
    qDebug () << "<><><><><><><><><><>";
    qDebug () << m_nativePath.get();
    qDebug () << m_type.get();
    qDebug () << m_timeToFull.get();
    qDebug () << m_timeToEmpty.get();
    qDebug () << m_percentage.get();
    qDebug () << "====================";
}

UPowerDevice::Type UPowerDevice::type()
{
    return static_cast<Type>(m_type.get().toUInt());
}

QString UPowerDevice::name()
{
    return m_nativePath.get().toString();
}
