cmake_minimum_required(VERSION 3.16)
project(it-tools-kirigami VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(ECM 5.80 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(Qt5 5.15 REQUIRED COMPONENTS Core Quick QuickControls2 Widgets)
find_package(KF5 REQUIRED COMPONENTS Kirigami2 CoreAddons)

add_executable(it-tools-kirigami
    src/main.cpp
    src/hashtool.h
    src/resources.qrc
)

target_link_libraries(it-tools-kirigami
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Widgets
    KF5::Kirigami2
    KF5::CoreAddons
)

install(TARGETS it-tools-kirigami ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
