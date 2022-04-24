IDIR=../include
CC=gcc
CFLAGS=-pthread -I$(IDIR)

ODIR=obj
LDIR=../lib

_DEPS=Canteen.h FileIO.h Menu.h
_OBJ=Main.o Canteen.o Menu.o FileIO.o
_LIBS=-L

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

LIBFLAG=$(patsubst %,$(_LIBS)%,$(LDIR))
LIB = $(patsubst %,$(LDIR)/%, lib_file.a)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.a: $(OBJ)
	ar rs $@ $^

../bin/Main.out: $(OBJ) $(LIB)
	gcc -o $@ $^ $(CFLAGS) $(LIBFLAG) -lm
	
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o*~ core $(INCDIR)/*~
