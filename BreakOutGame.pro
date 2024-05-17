QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    block.cpp \
    gameover.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelbase.cpp \
    levelmanager.cpp \
    main.cpp \
    player.cpp

HEADERS += \
    ball.h \
    block.h \
    gameover.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelbase.h \
    levelmanager.h \
    player.h

FORMS += \
    gameover.ui \
    levelmanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imags.qrc
