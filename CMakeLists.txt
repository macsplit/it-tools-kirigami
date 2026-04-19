cmake_minimum_required(VERSION 3.16)
project(tools VERSION 0.1.0 LANGUAGES CXX)

set(APP_ID app.pastetools.Tools)

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

file(GLOB YAML_CPP_SOURCES CONFIGURE_DEPENDS
    third_party/yaml-cpp/src/*.cpp
)

add_executable(tools
    src/main.cpp
    src/hashtool.h
    src/basetool.h
    src/conversiontool.h
    src/qrcodetool.h
    src/urltool.h
    src/networktool.h
    src/timetool.h
    src/mathtool.h
    src/idtool.h
    src/texttool.h
    src/crontool.h
    src/mimetool.h
    src/toolmanager.h
    src/qrcodegen.cpp
    src/resources.qrc
    ${YAML_CPP_SOURCES}
)

set_target_properties(tools PROPERTIES OUTPUT_NAME ${APP_ID})

target_link_libraries(tools
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Widgets
    Qt5::Xml
    KF5::Kirigami2
    KF5::CoreAddons
    crypt
)

target_include_directories(tools PRIVATE
    src
    third_party/yaml-cpp/include
    third_party/tomlplusplus
)

target_compile_definitions(tools PRIVATE YAML_CPP_STATIC_DEFINE)

install(TARGETS tools ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

# Install the .desktop file
install(FILES ${APP_ID}.desktop DESTINATION ${KDE_INSTALL_APPDIR})

# Install AppStream metadata
install(FILES ${APP_ID}.metainfo.xml DESTINATION ${KDE_INSTALL_METAINFODIR})

# Install the application icon
install(FILES src/icon.svg DESTINATION ${KDE_INSTALL_ICONDIR}/hicolor/scalable/apps RENAME ${APP_ID}.svg)

include(CTest)

if(BUILD_TESTING)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Test Qml)

    add_executable(tools_tests
        tests/tools_test.cpp
        src/hashtool.h
        src/basetool.h
        src/conversiontool.h
        src/qrcodetool.h
        src/urltool.h
        src/networktool.h
        src/timetool.h
        src/mathtool.h
        src/idtool.h
        src/texttool.h
        src/crontool.h
        src/mimetool.h
        src/toolmanager.h
        src/qrcodegen.cpp
        src/resources.qrc
        ${YAML_CPP_SOURCES}
    )

    target_include_directories(tools_tests PRIVATE
        src
        third_party/yaml-cpp/include
        third_party/tomlplusplus
    )
    target_compile_definitions(tools_tests PRIVATE TOOLS_TEST_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
    target_compile_definitions(tools_tests PRIVATE YAML_CPP_STATIC_DEFINE)

    target_link_libraries(tools_tests
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Widgets
        Qt5::Xml
        Qt5::Test
        KF5::Kirigami2
        KF5::CoreAddons
        crypt
    )

    add_test(NAME tools_tests COMMAND tools_tests)
    set_tests_properties(tools_tests PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
endif()
