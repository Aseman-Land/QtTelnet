INCLUDEPATH += $$PWD
DEPENDEPATH += $$PWD

!build_telnet_lib:DEFINES += TELNET_NO_LIB

QT += network

SOURCES += \
    $$PWD/qtelnet.cpp
HEADERS += \
    $$PWD/qtelnet.h \
    $$PWD/qtelnet_p.h \
    $$PWD/qtelnetglobal.h

win32 {
    LIBS += -lWs2_32
    contains(TEMPLATE, lib):contains(CONFIG, shared):DEFINES += QT_QTTELNET_EXPORT
    else:qttelnet-uselib:DEFINES += QT_QTTELNET_IMPORT
}
