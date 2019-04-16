#ifndef QDBUSFREEDESKTOPINTERFACE_H
#define QDBUSFREEDESKTOPINTERFACE_H

#include <QObject>
#include "QDBusFreedesktopInterfaceManager.h"

class QDBusFreedesktopInterface : public QDBusFreedesktopInterfaceManager::Delegate
{
public:
    explicit QDBusFreedesktopInterface(QDBusFreedesktopInterfaceManager* interfaceManager, QString interfaceName);
    virtual ~QDBusFreedesktopInterface() override;

    class Delegate
    {
    public:
        Delegate(QString propertyName);
        virtual ~Delegate();
        QString propertyName() const;
        virtual void onProperyChanged(QVariant);
        virtual void onPropertyInvalidate();
    private:
        QString m_propertyName;
    };

    QVariant getProperty(QString propertyName);
    void setProperty(QString propertyName, QVariant value);

    void addDelegate(Delegate* delegate);
    void removeDelegate(Delegate* delegate);

    // QDBusFreedesktopInterfaceManager::Delegate interface
public:
    void onPropertiesChanged(QVariantMap changed_properties, QStringList invalidated_properties) override;


private:
    QMultiMap<QString, Delegate*> m_delegates;
    QDBusFreedesktopInterfaceManager* m_interfaceManager = nullptr;
};

#endif // QDBUSFREEDESKTOPINTERFACE_H
