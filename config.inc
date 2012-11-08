# for gcc compiler on linux
# copy to make.def
CC          = gcc
CPP         = g++-4.7
CLINKER     = $(CPP)
OPTFLAGS    = -std=c++11  -D__APPLE__ -m64 -I./include -ftree-vectorizer-verbose=4
LIBS        = -lm

CFLAGS	  = $(OPTFLAGS)

OBJ=so
EXE=
RM=rm
