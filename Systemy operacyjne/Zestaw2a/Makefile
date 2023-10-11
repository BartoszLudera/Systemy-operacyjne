DIR = `basename $(CURDIR)`

NAME1 = cwiczenie2a

EXEC1  = $(NAME1).x

OBJS1  = $(NAME1).o

CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LFLAGS = -Wall -std=c99 -pedantic -O

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rsv

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) 

$(EXEC1): $(OBJS1) 
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run2

run2: $(EXEC1) 
	clear
	./$(EXEC1) 

.PHONY: clean tar

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )