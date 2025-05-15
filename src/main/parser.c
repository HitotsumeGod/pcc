#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include "pcc.h"

ASTNode *parser(char **toks) {

	ASTNode *root, *cnode;
	int n;

	n = 0;
	if ((root = malloc(sizeof(ASTNode))) == NULL) {
		errno = MALLOC_ERR;
		return NULL;
	}
	while (*(toks + n)) {
		if (n = 0) {
			root -> type = MAIN_METHOD;
			val = NULL;
			if ((cnode = (root -> next = malloc(sizeof(ASTNode)))) == NULL) {
				errno = MALLOC_ERR;
				return NULL;
			}
			n = 5;										//PREPARE NEXT TOKEN
			continue;
		}
		if (strcmp(*(toks + (n++)), "return") == 0) {
			cnode -> type = RETURN;
			val = &atoi(*(toks + n));
		}
		n++;
	}
	cnode = root;
	while (cnode) {
		
	}

}
