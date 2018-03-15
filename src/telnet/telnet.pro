TARGET = QtTelnet

#QMAKE_DOCS = $$PWD/doc/qttelnet.qdocconf

load(qt_module)
QT -= gui

CONFIG += build_telnet_lib
include(qttelnet.pri)
