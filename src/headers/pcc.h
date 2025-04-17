#ifndef __PCC_H__
#define __PCC_H__

#include <stddef.h>
#include <stdbool.h>
#include <ptrees.h>

char *pcc_keywords[9] = {"int", "char", "float", "bool", "long", "double", "main", "void", "0"};
char pcc_keychars[5] = {'(', ')', '{', '}', ';'};


extern size_t lexit(char *fname, char ***buf);
extern TreeNode *recursive_parse(char **toks, TreeNode *parent, int r);
bool is_digit(char digit);

#endif //__PCC_H__
