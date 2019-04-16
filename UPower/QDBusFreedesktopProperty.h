#ifndef QDBUSFREEDESKTOPPROPERTY_H
#define QDBUSFREEDESKTOPPROPERTY_H

#include <QObject>
#include "QDBusFreedesktopInterface.h"

class QDBusFreedesktopProperty : public QDBusFreedesktopInterface::Delegate
{
public:
    explicit QDBusFreedesktopProperty(QDBusFreedesktopInterface *interface, QString propertyName);
    virtual ~QDBusFreedesktopProperty() override;

    QVariant get();
    void set(QVariant value);

    // Delegate interface
public:
    void onProperyChanged(QVariant) override;
    void onPropertyInvalidate() override;

    operator QVariant() {
        return m_value;
    }

private:
    QVariant m_value;
    QDBusFreedesktopInterface *m_interface = nullptr;
};

#endif // QDBUSFREEDESKTOPPROPERTY_H
