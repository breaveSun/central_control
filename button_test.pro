QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT += websockets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    btntwoslider.cpp \
    btntxticon.cpp \
    changespace.cpp \
    ctrllistitem.cpp \
    ctrllistpage.cpp \
    curtain.cpp \
    curtainThread.cpp \
    curtainopen.cpp \
    curtainpage.cpp \
    equipment.cpp \
    homepage.cpp \
    horizontalbtn.cpp \
    httpserver.cpp \
    icon.cpp \
    labelbtn.cpp \
    light.cpp \
    lightpage.cpp \
    logindlg.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    myscollarea.cpp \
    myslider.cpp \
    rgbslider.cpp \
    roomcard.cpp \
    serverpushthread.cpp \
    switchbutton.cpp \
    titleicon.cpp \
    verticalicontext.cpp \
    verticalicontextbk.cpp \
    verticaltxtunit.cpp \
    wsclient.cpp

HEADERS += \
    LoadQss.h \
    btntwoslider.h \
    btntxticon.h \
    changespace.h \
    common.h \
    ctrllistitem.h \
    ctrllistpage.h \
    curtain.h \
    curtainThread.h \
    curtainopen.h \
    curtainpage.h \
    equipment.h \
    homepage.h \
    horizontalbtn.h \
    httpserver.h \
    icon.h \
    labelbtn.h \
    light.h \
    lightpage.h \
    logindlg.h \
    mainpage.h \
    mainwindow.h \
    myscollarea.h \
    myslider.h \
    rgbslider.h \
    roomcard.h \
    serverpushthread.h \
    switchbutton.h \
    titleicon.h \
    verticalicontext.h \
    verticalicontextbk.h \
    verticaltxtunit.h \
    wsclient.h

FORMS += \
    btntwoslider.ui \
    btntxticon.ui \
    changespace.ui \
    ctrllistitem.ui \
    ctrllistpage.ui \
    curtainopen.ui \
    curtainpage.ui \
    homepage.ui \
    horizontalbtn.ui \
    labelbtn.ui \
    lightpage.ui \
    logindlg.ui \
    mainpage.ui \
    mainwindow.ui \
    myslider.ui \
    rgbslider.ui \
    roomcard.ui \
    titleicon.ui \
    verticalicontext.ui \
    verticalicontextbk.ui \
    verticaltxtunit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    json/CMakeLists.txt

RESOURCES += \
    resource.qrc
