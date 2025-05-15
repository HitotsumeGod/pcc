/*
Basic C lexer program, for eventual use in my pcc compiler. Given the name of a file, it tokenizes said file
(using whitespace as a delimiter) and spits the tokens back out.
To use, do <program-name> <filename>
Ex: ./lexer jdeyos.txt
Copyright 2025 Petis God Naylis
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pcc.h"

#define NULLT '\0'

char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
char keychars[5] = {'(', ')', '{', '}', ';'};
char *keywords[9] = {"int", "char", "float", "bool", "long", "double", "main", "void", "return"};

char **lexer(char *fname) {

	FILE *f;
	char **toks, **tdummy, *keybuf, *dummy;
	int t, m, b, n, c;
	bool iskeychar;

	t = n = 0;
	m = b = 2;
	if ((f = fopen(fname, "r")) == NULL) {
		perror("fopen err");
		exit(EXIT_FAILURE);
	}
	if ((toks = malloc(sizeof(char *) * m)) == NULL || (keybuf = malloc(sizeof(char) * b)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(f)) != EOF) {
		if (t == m) {
			m *= 2;
			if ((tdummy = realloc(toks, sizeof(char *) * m)) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			toks = tdummy;
		}
		if (n == b - 2) {
			b *= 2;
			if ((dummy = realloc(keybuf, sizeof(char) * b)) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			keybuf = dummy;
		}
		iskeychar = false;
		for (int i = 0; i < sizeof keychars; i++)
			if (c == keychars[i]) {
				*keybuf = c;
				*(keybuf + 1) = NULLT;
				*(toks + (t++)) = strdup(keybuf);
				n = 0;
				iskeychar = true;
			}
		for (int i = 0; i < sizeof numbers; i++)
			if (c == numbers[i]) {
				*keybuf = c;
				*(keybuf + 1) = NULLT;
				*(toks + (t++)) = strdup(keybuf);
				n = 0;
				iskeychar = true;
			}
		if (!iskeychar && c != ' ' && c != '\n' && c != '\t') {
			*(keybuf + (n++)) = c;
			*(keybuf + n) = NULLT;
			for (int i = 0; i < 9; i++) {
				if (strcmp(keybuf, keywords[i]) == 0) {
					*(toks + (t++)) = strdup(keybuf);
					n = 0;
				}
			}
		}
	}
	free(keybuf);
	if (fclose(f) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < t; i++) 
		printf("%s\n", *(toks + i));
	return toks;

}
