/*
Basic C lexer program, for eventual use in my pcc compiler. Given the name of a file, it tokenizes said file
(using whitespace as a delimiter) and spits the tokens back out.
To use, do <program-name> <filename>
Ex: ./lexer jdeyos.txt
Copyright 2025 Petis God Naylis
*/

#include <stdio.h>
#include <stdlib.h>

#define NULLT '\0'

void lexandprint(char *fname) {

	FILE *srcf;
	char **toks, **tdummy, *dummy;
	int c, n, m, x, z, temp;

	n = x = 0;		//CHARACTER COUNTER; TOKEN COUNTER
	m = z = 2;		//MALLOC COUNTER, TOKARRAY SIZE COUNTER		
	if ((srcf = fopen(fname, "r")) == NULL) {
		perror("fopen err");
		return EXIT_FAILURE;
	}
	if ((toks = malloc(sizeof(char *) * z)) == NULL) {
		perror("malloc err");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < z; i++)
		if ((*(toks + i) = malloc(sizeof(char) * m)) == NULL) {
			perror("malloc err");
			return EXIT_FAILURE;	
		}
	while ((c = fgetc(srcf)) != EOF) {
		if (x == z) {
			z *= 2;
			//printf("z is : %d\n", z);
			if ((tdummy = realloc(toks, sizeof(char *) * z)) == NULL) {
				perror("realloc err");
				return EXIT_FAILURE;
			}
			toks = tdummy;
			for (int i = z / 2; i < z; i++ ) {
				//printf("m is : %d\n", m);
				if ((*(toks + i) = malloc(sizeof(char) * m)) == NULL) {
					perror("malloc err");
					return EXIT_FAILURE;	
				}
			}
		}
		if (n == m) {
			m *= 2;
			if ((dummy = realloc(*(toks + x), m)) == NULL) {
				perror("realloc err");
				return EXIT_FAILURE;
			}
			*(toks + x) = dummy;
		}
		if (c == ' ' || c == '\n') {
			*(*(toks + x) + n) = NULLT;
			x++;
			n = 0;
			m = 2;
		} else {
			/*printf("%d\t%d\t", x, n);
			printf("\n");*/
			*(*(toks + x) + n) = c;
			n++;
		}
	}
	if (fclose(srcf) == -1) {
		perror("fclose err");
		return EXIT_FAILURE;
	}
	for (int i = 0; i <= x; i++) {
		if (i != x)
			printf("%s\n", *(toks + i));
		free(*(toks + i));
	}
	free(toks);
}
