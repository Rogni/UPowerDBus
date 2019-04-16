#include "QDBusFreedesktopInterfaceManager.h"

void QDBusFreedesktopInterfaceManager::addDelegate(QDBusFreedesktopInterfaceManager::Delegate *delegate)
{
    m_delegates.insert(delegate->interfaceName(), delegate);
}

void QDBusFreedesktopInterfaceManager::removeDelegate(QDBusFreedesktopInterfaceManager::Delegate *delegate)
{
    m_delegates.remove(delegate->interfaceName(), delegate);
}

QDBusFreedesktopInterfaceManager::QDBusFreedesktopInterfaceManager(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
    connect(this, &QDBusFreedesktopInterfaceManager::PropertiesChanged, this, &QDBusFreedesktopInterfaceManager::onPropertiesChanged);
}

QDBusFreedesktopInterfaceManager::~QDBusFreedesktopInterfaceManager()
{
}

void QDBusFreedesktopInterfaceManager::onPropertiesChanged(const QString &interface_name, QVariantMap changed_properties, QStringList invalidated_properties)
{
    if (!m_delegates.contains(interface_name)) return;

    for (auto &pair : m_delegates.values(interface_name)) {
        pair->onPropertiesChanged(changed_properties, invalidated_properties);
    }
}


QDBusFreedesktopInterfaceManager::Delegate::Delegate(QString interfaceName)
{
    m_interfaceName = interfaceName;
}

QDBusFreedesktopInterfaceManager::Delegate::~Delegate() {}

QString QDBusFreedesktopInterfaceManager::Delegate::interfaceName() const
{
    return m_interfaceName;
}

void QDBusFreedesktopInterfaceManager::Delegate::onPropertiesChanged(QVariantMap, QStringList) {}
