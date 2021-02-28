FORMS += \
    addgarbage.ui \
    browser.ui \
    menuwidge.ui \
    modify.ui \
    query.ui

HEADERS += \
    addgarbage.h \
    browser.h \
    garbageinfo.h \
    menuwidge.h \
    modify.h \
    query.h

SOURCES += \
    addgarbage.cpp \
    browser.cpp \
    garbageinfo.cpp \
    main.cpp \
    menuwidge.cpp \
    modify.cpp \
    query.cpp

QT += widgets

DISTFILES += \
    garbage

RESOURCES +=

RC_FILE = logo.rc
