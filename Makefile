CC=gcc
SRC=src/main
DEPS=src/headers -I /usr/local/include
LIBPATH=/usr/local/lib
SRS=$(SRC)/lexer.c $(SRC)/consumer.c $(SRC)/pilot.c

pilot: $(SRS)
	$(CC) -o $@ $^ -L $(LIBPATH) -lptrees -I $(DEPS) -g
clean: pilot
	rm -f $^
