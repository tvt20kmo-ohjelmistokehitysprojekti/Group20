QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    amount.cpp \
    balance.cpp \
    database.cpp \
    dblogin.cpp \
    login.cpp \
    logout.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    selectaccount.cpp \
    statement.cpp \
    transfer.cpp \
    transferok.cpp \
    withdrawal.cpp \
    withdrawalok.cpp

HEADERS += \
    amount.h \
    balance.h \
    database.h \
    dblogin.h \
    login.h \
    logout.h \
    mainmenu.h \
    mainwindow.h \
    selectaccount.h \
    statement.h \
    transfer.h \
    transferok.h \
    withdrawal.h \
    withdrawalok.h

FORMS += \
    amount.ui \
    balance.ui \
    dblogin.ui \
    login.ui \
    logout.ui \
    mainmenu.ui \
    mainwindow.ui \
    selectaccount.ui \
    statement.ui \
    transfer.ui \
    transferok.ui \
    withdrawal.ui \
    withdrawalok.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
