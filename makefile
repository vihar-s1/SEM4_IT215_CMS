IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib
LIBS=-lm

_DEPS=myFunc.h
_OBJ=main.o FuncDef.o

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

../bin/main.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o*~ core $(INCDIR)/*~
