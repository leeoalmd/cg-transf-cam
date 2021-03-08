TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += models

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += \
        bib/Camera.cpp \
        bib/CameraDistante.cpp \
        bib/CameraJogo.cpp \
        bib/Desenha.cpp \
        bib/Vetor3D.cpp \
        bib/model3ds.cpp \
        gui_glut/extra.cpp \
        gui_glut/gui.cpp \
        main.cpp \
        models/bar.cpp \
        models/freezer.cpp \
        models/objeto.cpp \
        models/oculos.cpp \
        models/sanfona.cpp \
        models/sinuca.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/Vetor3D.h \
    bib/model3ds.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    models/bar.h \
    models/freezer.h \
    models/objeto.h \
    models/oculos.h \
    models/sanfona.h \
    models/sinuca.h
