QT -= gui

DESTDIR += bin
CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        dialogwindow.cpp \
        main.cpp \
        window.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    dialogwindow.h \
    window.h

QT += widgets

OBJECTS_DIR = tmp
RCC_DIR = $$OBJECTS_DIR
MOC_DIR = $$OBJECTS_DIR
UI_DIR  = $$OBJECTS_DIR
