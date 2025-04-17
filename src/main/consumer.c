#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcc.h>

#define DEPTH 4
#define CHILDREN 2
#define NEXT_TOK *(toks + (r++))

TreeNode *recursive_parse(char **toks, TreeNode *p, int r) {
	
	TreeNode *cnode;
	char ret;
	
	if (is_digit((ret = *NEXT_TOK)))
		if (strcmp("return", (char *) p -> val))
			return mktnode(&ret, p, 0);	
	}
		
}

bool is_digit(char d) {

	for (int i = 48; i <= 57; i++)
		if (d == i)
			return true;
	return false;

}
