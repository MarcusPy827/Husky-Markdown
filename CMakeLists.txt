cmake_minimum_required(VERSION 3.16)

project(Husky-Markdown VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
add_subdirectory(libs/Null-Log-Library/src)

set(TS_FILES
        res/locales/Husky-Markdown_zh.ts
)

set(PROJECT_SOURCES
        src/main.cxx
        src/mainwindow/mainwindow.cxx
        src/mainwindow/mainwindow.hxx
        ${TS_FILES}
)

qt_add_lupdate(Husky-Markdown TS_FILES res/locales/Husky-Markdown_zh.ts SOURCES ${PROJECT_SOURCES})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Husky-Markdown
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
            res/resources.qrc
            src/file_watcher/file_watcher.hxx
            src/file_watcher/file_watcher.cxx
            src/webview_ipc/webview_ipc.hxx src/webview_ipc/webview_ipc.cxx

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Husky-Markdown APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Husky-Markdown SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Husky-Markdown
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_include_directories(Husky-Markdown PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/Null-Log-Library/src/null_log
)
target_link_libraries(Husky-Markdown PRIVATE Qt${QT_VERSION_MAJOR}::Widgets null_log_library)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Husky-Markdown)
endif()
set_target_properties(Husky-Markdown PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Husky-Markdown
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Husky-Markdown)
endif()
