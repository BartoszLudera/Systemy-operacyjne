Cflags = -O2 -Wall -std=c99
CO=gcc
DIR=$(notdir $(CURDIR))

zad1.x: zad1.c processes.h
	$(CO) $(Cflags) -o $@ $^

zad2.x: zad2.c processes.h
	$(CO) $(Cflags) -o $@ $^

zad3.x: zad3.c processes.h
	$(CO) $(Cflags) -o $@ $^

zad4.x: zad4.c processes.h
	$(CO) $(Cflags) -o $@ $^

zad5.x: zad5.c processes.h
	$(CO) $(Cflags) -o $@ $^

.PHONY: all runzad1 runzad2 runzad3 runzad4 runzad5 clean tar

all: zad1.x zad2.x zad3.x zad4.x zad5.x

runzad1: zad1.x
	./zad1.x

runzad2: zad2.x
	./zad2.x

runzad3: zad3.x
	./zad3.x

runzad4: zad4.x
	./zad5.x

runzad5: zad5.x
	./zad5.x
	
clean: 
	rm -f *.o *~ *.a *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR))


	