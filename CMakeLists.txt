cmake_minimum_required(VERSION 3.16)
project(tools VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(ECM 5.80 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

# Enable exceptions which are required by qrcodegen
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

find_package(Qt5 5.15 REQUIRED COMPONENTS Core Quick QuickControls2 Widgets Xml)
find_package(KF5 REQUIRED COMPONENTS Kirigami2 CoreAddons)

add_executable(tools
    src/main.cpp
    src/hashtool.h
    src/basetool.h
    src/conversiontool.h
    src/qrcodetool.h
    src/urltool.h
    src/networktool.h
    src/qrcodegen.cpp
    src/resources.qrc
)

target_link_libraries(tools
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Widgets
    Qt5::Xml
    KF5::Kirigami2
    KF5::CoreAddons
)

install(TARGETS tools ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

# Install the .desktop file
install(FILES org.kde.tools.desktop DESTINATION ${KDE_INSTALL_APPDIR})

# Install the application icon
install(FILES src/icon.svg DESTINATION ${KDE_INSTALL_ICONDIR}/hicolor/scalable/apps RENAME org.kde.tools.svg)
