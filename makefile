CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./includes/
SRCDIR = ./src/


SOURCES = $(SRCDIR)*.c

all: caverns

caverns: 
	$(CC) $(SOURCES) $(CFLAGS) -o $@

clean:
	rm -f caverns
	
run: 
	./caverns