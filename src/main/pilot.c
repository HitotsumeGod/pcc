#include <stdio.h>
#include <stdlib.h>
#include <pcc.h>

int main(int argc, char *argv[]) {

	char **tokens; 
	int num_tokens;
	
	num_tokens = lexit(argv[1], &tokens);
	for (int i = 0; i < num_tokens; i++) {
		printf("%s\n", *(tokens + i));
		free(*(tokens + i));
	}
	recursive_parse(tokens);
	free(tokens);
	return 0;

}
