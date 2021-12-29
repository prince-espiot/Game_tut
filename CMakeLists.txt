cmake_minimum_required(VERSION 3.5)

project(Game_tut VERSION 0.1 LANGUAGES CXX)

include_directories("src")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia REQUIRED)

# find_package( Qt6Multimedia REQUIRED )
# find_package( Qt6MultimediaWidgets REQUIRED )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        myrect.h
        myrect.cpp
        bullet.h
        bullet.cpp
        enemy.h
        enemy.cpp
        score.h
        score.cpp
        health.h
        health.cpp

)
set(QT_USE_QTMULTIMEDIA TRUE)
set(QT_USE_QTMULTIMEDIAWIDGETS TRUE)

qt_add_resources(RESOURCES_DIR resources.qrc)
# qt6_use_modules (${EXECUTABLE_NAME} Multimedia MultimediaWidgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Game_tut
        MANUAL_FINALIZATION
        ${RESOURCES_DIR}
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Game_tut APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Game_tut SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Game_tut
            ${PROJECT_SOURCES}


        )
    endif()
endif()

target_link_libraries(Game_tut PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)

set_target_properties(Game_tut PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Game_tut)
endif()
