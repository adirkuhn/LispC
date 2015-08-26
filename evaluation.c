#include "lib/mpc/mpc.h"
#include "evaluation.h"

long evaluation(mpc_ast_t* t) {

	/* If tagged as number return it directly */
	if (strstr(t->tag, "number")) {
		return atoi(t->contents);
	}

	/* The operator is always the second child */
	char* op = t->children[1]->contents;

	/* store the third child in x */
	long x = evaluation(t->children[2]);

	/* Iterate the remaining children and combine */
	int i = 3;
	while (strstr(t->children[i]->tag, "expr")) {
		x = evaluation_op(x, op, evaluation(t->children[i]));
		i++;
	}

	return x;
}

long evaluation_op(long x, char *op, long y) {
	if (strcmp(op, "+") == 0) { return x + y;}
	if (strcmp(op, "-") == 0) { return x - y;}
	if (strcmp(op, "*") == 0) { return x * y;}
	if (strcmp(op, "/") == 0) { return x / y;}

	return 0;
}