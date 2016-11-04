TEMPLATE = app
CONFIG += c++11
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PhoneBook.cpp \
    PhoneBookItem.cpp \
    menu.cpp

HEADERS += \
    PhoneBook.h \
    PhoneBookItem.h \
    menu.h

