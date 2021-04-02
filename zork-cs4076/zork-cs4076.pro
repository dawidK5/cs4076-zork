QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# CONFIG -= qt
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Item.cpp \
    Room.cpp \
    ZorkUL.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    popout.cpp

HEADERS += \
    Item.h \
    Room.h \
    ZorkUL.h \
    dialog.h \
    mainwindow.h \
    popout.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    popout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    mapwithgrid.png

RESOURCES += \
    resFile.qrc
