import qbs

Project {
    StaticLibrary {
        Depends {name: "cpp" }
        Depends {name: "Qt.core" }
        Depends {name: "Qt.dbus" }
        Depends {name: "QDbusFreedesktopProperty" }
        files: [
            "UPowerDevice.cpp",
            "UPowerDevice.h",
            "UPowerDeviceManager.cpp",
            "UPowerDeviceManager.h",
        ]
        name: "UPower"

        Export {
            Depends {
                name: "cpp"
            }
            cpp.includePaths: product.sourceDirectory
            cpp.defines: ["USING_" + product.name.toUpperCase()]
        }
    }
}

