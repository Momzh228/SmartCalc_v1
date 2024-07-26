QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    credit_calc.cpp \
    graph.cpp \
    mainwindow.cpp \
    ../s21_calc.c \
    ../s21_stack.c \
    ../s21_credit_calc.c \
    ../s21_calc_X.c \
    qcustomplot.cpp


HEADERS += mainwindow.h \
    credit_calc.h \
    graph.h \
    qcustomplot.h \
    stack.h \
    s21_calc.h

FORMS += \
    credit_calc.ui \
    graph.ui \
    mainwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
