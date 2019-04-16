#include "QDBusFreedesktopProperty.h"

QDBusFreedesktopProperty::QDBusFreedesktopProperty(QDBusFreedesktopInterface *interface, QString propertyName):
    Delegate(propertyName),
    m_interface(interface)
{
    if (m_interface) {
        m_interface->addDelegate(this);
        m_value = m_interface->getProperty(propertyName);
    }
}

QDBusFreedesktopProperty::~QDBusFreedesktopProperty()
{
    if (m_interface) {
        m_interface->removeDelegate(this);
    }
}

QVariant QDBusFreedesktopProperty::get()
{
    return m_value;
}

void QDBusFreedesktopProperty::set(QVariant value)
{
    m_interface->setProperty(propertyName(), value);
}

void QDBusFreedesktopProperty::onProperyChanged(QVariant value)
{
    m_value = value;
}

void QDBusFreedesktopProperty::onPropertyInvalidate()
{
    m_value = QVariant();
}
