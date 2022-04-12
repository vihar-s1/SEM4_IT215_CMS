IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib
LIBS=-lm

_DEPS=
_OBJ=Main.o

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

../bin/Main.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o*~ core $(INCDIR)/*~
