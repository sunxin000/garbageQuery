FORMS += \
    addgarbage.ui \
    deletegarbage.ui \
    menuwidge.ui \
    modify.ui \
    query.ui

HEADERS += \
    addgarbage.h \
    deletegarbage.h \
    garbageinfo.h \
    menuwidge.h \
    modify.h \
    query.h

SOURCES += \
    addgarbage.cpp \
    deletegarbage.cpp \
    garbageinfo.cpp \
    main.cpp \
    menuwidge.cpp \
    modify.cpp \
    query.cpp

QT += widgets

DISTFILES += \
    garbage

RESOURCES += \
    image.qrc

RC_FILE = logo.rc
