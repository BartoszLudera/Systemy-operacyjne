DIR = `basename $(CURDIR)`

NAME1 = zad1
NAME2 = zad2
NAME3 = zad3
NAME4 = zad3a

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x
EXEC4  = $(NAME4).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o
OBJS4  = $(NAME4).o

CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rsv

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC3): $(OBJS3) $(LIBS3) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC4): $(OBJS4) $(LIBS4) 
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: runzad1 runzad2 runzad3

runzad1: $(EXEC1)
	#clear
	./$(EXEC1) $(o) $(s)

runzad2: $(EXEC2) $(EXEC1)
	clear
	./$(EXEC2) $(o) $(s) $(EXEC1)

runzad3: $(EXEC3) $(EXEC1) $(EXEC4)
	clear
	./$(EXEC3) $(o) $(s) $(EXEC4) $(EXEC1)

.PHONY: clean tar

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
