#-------------------------------------------------
#
# Project created by QtCreator 2012-09-21T10:06:28
#
#-------------------------------------------------

QT       += core gui

TARGET = db36
TEMPLATE = app

# Дополнительные пути поиска заголовчных фалов
INCLUDEPATH = ../include

# Относительный путь рабочего каталога репозитория
OUTPUT = ../..

# Относительный путь каталога для хранения временных файлов
TEMP = $${OUTPUT}/temp/db36

debug {
  DEFINES += _DEBUG
  DESTDIR = $${OUTPUT}/debug
  OBJECTS_DIR = $${TEMP}/debug
} else {
  DESTDIR = $${OUTPUT}/release
  OBJECTS_DIR = $${TEMP}/release
}

win32 {
} else {
  INCLUDEPATH += /usr/include/postgresql\
                 /usr/include/postgresql/libpq\
                 /usr/include/libxml2\
                 /usr/include
  LIBS +=	-lxml2 -lpq
}

RCC_DIR = ./res

RESOURCES = ./res/resource.qrc

# Путь для сохранения временных файлов Qt
MOC_DIR = $${OBJECTS_DIR}

SOURCES += main.cpp\
        mainwindow.cpp \
    querydialog.cpp \
    progressbar.cpp

HEADERS  += mainwindow.h \
    querydialog.h \
    progressbar.h

FORMS    += mainwindow.ui \
    querydialog.ui \
    progressbar.ui
