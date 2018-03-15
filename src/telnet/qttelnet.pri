INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

!build_telnet_lib:DEFINES += TELNET_NO_LIB

qttelnet-uselib:!qttelnet-buildlib {
    LIBS += -L$$QTTELNET_LIBDIR -l$$QTTELNET_LIBNAME
} else {
}
QT += network

SOURCES += $$PWD/qttelnet.cpp
HEADERS += $$PWD/qttelnet.h
win32:LIBS += -lWs2_32

win32 {
    contains(TEMPLATE, lib):contains(CONFIG, shared):DEFINES += QT_QTTELNET_EXPORT
    else:qttelnet-uselib:DEFINES += QT_QTTELNET_IMPORT
}
