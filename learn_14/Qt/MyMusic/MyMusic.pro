QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 导入三方库,注意：SDL2要先导入SDL2main然后再SDL2，不然会报错
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/SDL2/lib/x64/ -lSDL2main -lSDL2  \
                                                -L$$PWD/thirdparty/SDL2_mixer/lib/x64/  -lSDL2_mixer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/SDL2/lib/x64/ -lSDL2d -lSDL2maind \
                                                   -L$$PWD/thirdparty/SDL2_mixer/lib/x64/ -lSDL2_mixerd
else:unix: LIBS += -L$$PWD/thirdparty/SDL2/lib/x64/ -lSDL2 -lSDL2main \
                    -L$$PWD/thirdparty/SDL2_mixer/lib/x64/ -lSDL2_mixer

INCLUDEPATH += $$PWD/thirdparty/SDL2/lib/x64 \
                $$PWD/thirdparty/SDL2/include \
                $$PWD/thirdparty/SDL2_mixer/include
DEPENDPATH += $$PWD/thirdparty/SDL2/lib/x64 \
                $$PWD/thirdparty/SDL2_mixer/lib/x64



SOURCES += \
    animbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    musicbox.cpp \
    musicboxlist.cpp \
    musicinfoitem.cpp \
    musiclistpage.cpp \
    resmgr.cpp

HEADERS += \
    animbutton.h \
    mainwindow.h \
    musicbox.h \
    musicboxlist.h \
    musicinfoitem.h \
    musiclistpage.h \
    resmgr.h

FORMS += \
    animbutton.ui \
    mainwindow.ui \
    musicbox.ui \
    musicboxlist.ui \
    musicinfoitem.ui \
    musiclistpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


