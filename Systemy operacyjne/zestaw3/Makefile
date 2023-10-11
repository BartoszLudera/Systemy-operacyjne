DIR = `basename $(CURDIR)`

NAME1 = zad1
PLIK_IN = zad1in.txt
PLIK_OUT = zad1out.txt

EXEC1  = $(NAME1).x

OBJS1  = $(NAME1).o

CFLAGS = -Wall -std=c99 -pedantic
LFLAGS = -Wall -std=c99 -pedantic

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rsv

%.o: %.c
	$(CO) $(CFLAGS) -c $<

$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: runzad1

runzad1: $(EXEC1)
	clear
	./$(EXEC1) $(PLIK_IN) $(PLIK_OUT)
	@echo "\n=============================\n"
	@diff -s $(PLIK_IN) $(PLIK_OUT)

.PHONY: clean tar

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )