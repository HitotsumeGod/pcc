CC=gcc
SRC=src/main
DEPS=src/headers
SRS=$(SRC)/lexer.c

pilot: $(SRS)
	$(CC) -o $@ $^ -I $(DEPS) -g
clean: pilot
	rm -f $^
