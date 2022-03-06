QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beeline.cpp \
    circl.cpp \
    ellipse.cpp \
    hyperbolav.cpp \
    hyperkanon.cpp \
    hyperravno.cpp \
    linegen.cpp \
    lineseg.cpp \
    lineslope.cpp \
    main.cpp \
    mainwindow.cpp \
    parabalav.cpp \
    parabkanon.cpp \
    qcustomplot.cpp \
    vsegrafiki.cpp

HEADERS += \
    beeline.h \
    circl.h \
    ellipse.h \
    hyperbolav.h \
    hyperkanon.h \
    hyperravno.h \
    linegen.h \
    lineseg.h \
    lineslope.h \
    mainwindow.h \
    parabalav.h \
    parabkanon.h \
    qcustomplot.h \
    vsegrafiki.h

FORMS += \
    beeline.ui \
    circl.ui \
    ellipse.ui \
    hyperbolav.ui \
    hyperkanon.ui \
    hyperravno.ui \
    linegen.ui \
    lineseg.ui \
    lineslope.ui \
    mainwindow.ui \
    parabalav.ui \
    parabkanon.ui \
    vsegrafiki.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
