TEMPLATE = app

include(../../../src/telnet/qttelnet.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp
