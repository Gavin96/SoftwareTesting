#-------------------------------------------------
#
# Project created by QtCreator 2010-06-02T08:59:18
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = chat
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    chat.cpp

HEADERS  += widget.h \
    tcpclient.h \
    tcpserver.h \
    chat.h

FORMS    += widget.ui \
    tcpclient.ui \
    tcpserver.ui \
    chat.ui
QT += network

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += icon.rc
