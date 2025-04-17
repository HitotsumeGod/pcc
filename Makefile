CC=gcc
SRC=src/main
DEPS=src/headers
SRS=$(SRC)/lexer.c $(SRC)/pilot.c

pilot: $(SRS)
	$(CC) -o $@ $^ -I $(DEPS) -g
clean: pilot
	rm -f $^
