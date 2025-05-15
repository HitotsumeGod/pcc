#ifndef __PCC_H__
#define __PCC_H__

typedef enum ASTType {
	VAL,
	MAIN_METHOD,
	RETURN
} ASTType;

typedef struct ASTNode {
	ASTType type;
	int *val;
	struct ASTNode *next;
} ASTNode;

extern char **lexer(char *filename);
extern ASTNode *parser(char **tokens);
extern void assembler(ASTNode *root);

#endif //__PCC_H__
