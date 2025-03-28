QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS +=img/1.ico
SOURCES += \
    add.cpp \
    add_score.cpp \
    admin.cpp \
    c_add.cpp \
    main.cpp \
    mainwindow.cpp \
    students.cpp \
    teacher.cpp

HEADERS += \
    add.h \
    add_score.h \
    admin.h \
    c_add.h \
    mainwindow.h \
    students.h \
    teacher.h

FORMS += \
    add.ui \
    add_score.ui \
    admin.ui \
    c_add.ui \
    mainwindow.ui \
    students.ui \
    teacher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
