#include <QCoreApplication>
#include <UPowerDeviceManager.h>
#include <UPowerDevice.h>
#include <QDebug>

int main (int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    UPowerDeviceManager power;

    auto devices = power.EnumerateDevices();
    auto v = devices.value();
    qDebug() <<v.count() << power.onBattery();
    for (auto p : v) {
        qDebug() << p.path();
        UPowerDevice device(p.path());
        qDebug() << device.name();
        qDebug() << device.type();
    }

    UPowerDevice device("/org/freedesktop/UPower/devices/DisplayDevice");
    qDebug() << device.name();
    qDebug() << device.type();

    return app.exec();
}
