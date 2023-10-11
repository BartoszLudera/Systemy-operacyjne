Cflags = -O2
CO=gcc
DIR=$(notdir $(CURDIR))

zad2_1.x: zad2_1.c processes.h
	$(CO) $(Cflags) -o $@ $^

zad1.x: zad1.c processes.h
	$(CO) $(Cflags) -o $@ $^

.PHONY: all runzad2_1 runzad1 clean tar

all: zad2_1.x zad1.x 

runzad2_1: zad2_1.x
	./zad2_1.x $(argument)

runzad1: zad1.x
	./zad1.x

runProcesses: processes.c
	./processes.x
	
clean: 
	rm -f *.o *~ *.a *.x a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR))


	
