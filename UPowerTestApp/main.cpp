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
    qDebug() << "OnBattery: " << power.onBattery();
    for (auto p : v) {
        qDebug() << p.path();
        UPowerDevice device(p.path());
        qDebug() << "Name: " << device.name();
        qDebug() << "Type: " << device.type();
        qDebug() << "Time to full: " << device.timeToFull();
        qDebug() << "Time to empty: " << device.timeToEmpty();
    }

    UPowerDevice device("/org/freedesktop/UPower/devices/DisplayDevice");
    qDebug() << device.name();
    qDebug() << device.type();

    return app.exec();
}
