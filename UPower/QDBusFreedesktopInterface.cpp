#include "QDBusFreedesktopInterface.h"

QDBusFreedesktopInterface::QDBusFreedesktopInterface(QDBusFreedesktopInterfaceManager *interfaceManager, QString interfaceName):
    QDBusFreedesktopInterfaceManager::Delegate(interfaceName),
    m_interfaceManager(interfaceManager)
{
    if (interfaceManager) {
        interfaceManager->addDelegate(this);
    }
}

QDBusFreedesktopInterface::~QDBusFreedesktopInterface()
{
    if (m_interfaceManager) {
        m_interfaceManager->removeDelegate(this);
    }
}

QVariant QDBusFreedesktopInterface::getProperty(QString propertyName)
{
    if (m_interfaceManager) {
        return m_interfaceManager->Get(interfaceName(), propertyName).value().variant();
    }
    return QVariant();
}

void QDBusFreedesktopInterface::setProperty(QString propertyName, QVariant value)
{
    if (m_interfaceManager) {
        m_interfaceManager->Set(interfaceName(), propertyName, value);
    }
}

void QDBusFreedesktopInterface::addDelegate(QDBusFreedesktopInterface::Delegate *delegate)
{
    m_delegates.insert(delegate->propertyName(), delegate);
}

void QDBusFreedesktopInterface::removeDelegate(QDBusFreedesktopInterface::Delegate *delegate)
{
    m_delegates.remove(delegate->propertyName(), delegate);
}

void QDBusFreedesktopInterface::onPropertiesChanged(QVariantMap changed_properties, QStringList invalidated_properties)
{
    for (auto key : changed_properties.keys()) {
        for (auto &delegate : m_delegates.values(key)) {
            delegate->onProperyChanged(changed_properties[key]);
        }
    }
    for (auto key : invalidated_properties) {
        for (auto &delegate : m_delegates.values(key)) {
            delegate->onPropertyInvalidate();
        }
    }
}

QDBusFreedesktopInterface::Delegate::Delegate(QString propertyName)
{
    m_propertyName = propertyName;
}

QDBusFreedesktopInterface::Delegate::~Delegate() {}

QString QDBusFreedesktopInterface::Delegate::propertyName() const
{
    return m_propertyName;
}

void QDBusFreedesktopInterface::Delegate::onProperyChanged(QVariant)
{

}

void QDBusFreedesktopInterface::Delegate::onPropertyInvalidate()
{

}
