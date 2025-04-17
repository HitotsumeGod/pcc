#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pcc.h>

#define NEXT_TOK *(toks + (i++))

void parse_as_ast(char **toks, size_t tok_size) {

	char **toprint, **dummy;
	int n, m;
	bool in_main_function, in_function_args;
	
	n = 0
	m = 2;
	if ((toprint = malloc(sizeof(char *) * b)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	in_main_function = in_function_args = false;
	for (int i = 0; i < tok_size; i++) {
		if (n > m) {
			m *= 2;
			if ((dummy = realloc(toprint, sizeof(char *) * m)) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			toprint = dummy;
		}
		if (!in_main_function) {
			while (strcmp("main", NEXT_TOK) == 1) 
				*(toprint + (n++)) = strdup(NEXT_TOK);
			*(toprint + (n++)) = strdup(NEXT_TOK);
			if (strcmp("void", *(toks + (++i))) == 0)
				if (strcmp(")", NEXT_TOK) == 0)
					if (strcmp("{", NEXT_TOK) == 0)
						in_main_function = true;
		} else {
			
		}
		if (!in_main_function) {
			fprintf(stderr, "%s\n", "No main function defined.");
			exit(EXIT_FAILURE);
		}
			
	}

}

