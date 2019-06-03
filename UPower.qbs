import qbs

Project {
    references: [
        "QDbusFreedesktopProperty/QDbusFreedesktopProperty.qbs"
    ]
    StaticLibrary {
        Depends {name: "cpp" }
        Depends {name: "Qt.core" }
        Depends {name: "Qt.dbus" }
        Depends {name: "QDbusFreedesktopProperty" }
        files: [
            "src/UPowerDevice.cpp",
            "include/UPowerDevice.h",
            "src/UPowerDeviceManager.cpp",
            "include/UPowerDeviceManager.h",
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

