import qbs

Project {
    StaticLibrary {
        Depends {name: "cpp" }
        Depends {name: "Qt.core" }
        Depends {name: "Qt.dbus" }
        files: [
            "UPowerDevice.cpp",
            "UPowerDevice.h",
            "UPowerDeviceManager.cpp",
            "UPowerDeviceManager.h",
        ]
        name: "UPower"


        Group {
            name: "QDBusProperty"
            files: [
                "QDBusFreedesktopInterface.cpp",
                "QDBusFreedesktopInterface.h",
                "QDBusFreedesktopInterfaceManager.cpp",
                "QDBusFreedesktopInterfaceManager.h",
                "QDBusFreedesktopProperty.cpp",
                "QDBusFreedesktopProperty.h",
            ]
        }

        Export {
            Depends {
                name: "cpp"
            }
            cpp.includePaths: product.sourceDirectory
            cpp.defines: ["USING_" + product.name.toUpperCase()]

        }
    }
}

