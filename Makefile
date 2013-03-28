MAKE=make
CXX=gcc-4.7
CXXFLAGS= -O2 -c -Wall -g  -D_REENTRANT -fPIC -ftree-vectorizer-verbose=4 -Wunsafe-loop-optimizations -std=c++11

LD=gcc-4.7

SRCDIR=src
OBJDIR=obj
LIBDIR=lib

LIBTARGET=lib$(MODULE).$(LIB_EXT)
LDFLAGS= -shared -o


CPP_FILES := $(wildcard src/*.cc)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := ...

obj/%.o: src/%.cpp
	 $(CXX) $(CXXFLAGS) -c -o $@ $<

orrery: $(OBJ_FILES)
	 $(CXX) $(LD_FLAGS) -o $@ $^

