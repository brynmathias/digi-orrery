include config.inc

EXES=orrery$(EXE)

all: $(EXES)
	
planet$(EXE):
		$(CPP) $(OPTFLAGS) src/planet.cc -o lib/planet.$(OBJ)

orrery$(EXE):
		$(CPP) $(OPTFLAGS) -o orrary -L./lib/ src/orrery.cc 

clean:
	$(RM) orrary lib/*.$(OBJ)