#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:33:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A7-92417
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client_ui.cpp \
    edit_book.cpp \
    export_edits.cpp \
    new_book.cpp \
    new_season.cpp \
    signup.cpp \
    Book.cpp \
    Client.cpp \
    client_socket.cpp \
    Edit.cpp \
    Machine.cpp \
    methods.cpp \
    tools.cpp \
    UI.cpp \
    Visitor.cpp \
    users_requests.cpp \
    users_grant.cpp \
    change_name.cpp \
    edit_writer.cpp \
    publish.cpp \
    back_version.cpp \
    book_content.cpp \
    version_content_change.cpp \
    latest_version.cpp

HEADERS  += mainwindow.h \
    client_ui.h \
    edit_book.h \
    export_edits.h \
    new_book.h \
    new_season.h \
    signup.h \
    available_books.h \
    Book.h \
    Client.h \
    client_socket.h \
    Edit.h \
    Machine.h \
    methods.h \
    network_exception.h \
    tools.h \
    UI.h \
    Visitor.h \
    users_requests.h \
    users_grant.h \
    change_name.h \
    edit_writer.h \
    publish.h \
    back_version.h \
    book_content.h \
    version_content_change.h \
    latest_version.h

FORMS    += mainwindow.ui \
    client_ui.ui \
    edit_book.ui \
    export_edits.ui \
    new_book.ui \
    new_season.ui \
    signup.ui \
    users_requests.ui \
    users_grant.ui \
    change_name.ui \
    edit_writer.ui \
    publish.ui \
    back_version.ui \
    book_content.ui \
    version_content_change.ui \
    latest_version.ui

DISTFILES += \
    A7-92417.pro.user \
    client \
    Makefile
