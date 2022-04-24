IDIR=../include
CC=gcc
CFLAGS=-pthread -I$(IDIR)

ODIR=obj
LDIR=../lib
LIBS=-lm

_DEPS=Canteen.h FileIO.h Menu.h
_OBJ=Main.o Canteen.o Menu.o FileIO.o

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

../bin/Main.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o*~ core $(INCDIR)/*~
