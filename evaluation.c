#include "lib/mpc/mpc.h"
#include "evaluation.h"

lval evaluation(mpc_ast_t* t) {

	/* If tagged as number return it directly */
	if (strstr(t->tag, "number")) {
		/* check for conversions errors */
		errno = 0;
		long x = strtol(t->contents, NULL, 10);

		return errno != ERANGE
			? lval_num(x)
			: lval_err(LERR_BAD_NUM);
	}

	/* The operator is always the second child */
	char* op = t->children[1]->contents;

	/* store the third child in x */
	lval x = evaluation(t->children[2]);

	/* Iterate the remaining children and combine */
	int i = 3;
	while (strstr(t->children[i]->tag, "expr")) {
		x = evaluation_op(x, op, evaluation(t->children[i]));
		i++;
	}

	return x;
}

lval evaluation_op(lval x, char *op, lval y) {

	/* verify if lval are errors */
	if (x.type == LVAL_ERR) { return x; }
	if (y.type == LVAL_ERR) { return y; }

	/* parse operator */
	if (strcmp(op, "+") == 0) { return lval_num(x.num + y.num); }
	if (strcmp(op, "-") == 0) { return lval_num(x.num - y.num); }
	if (strcmp(op, "*") == 0) { return lval_num(x.num * y.num); }
	if (strcmp(op, "/") == 0) {
		/*verify if divisor are 0*/
		return y.num == 0
			? lval_err(LERR_DIV_ZERO)
			: lval_num(x.num / y.num);
	}
	if (strcmp(op, "%") == 0) {
		/* verify if divisor are 0 */
		return y.num == 0
			? lval_err(LERR_DIV_ZERO)
			: lval_num(x.num % y.num);
	}

	return lval_err(LERR_BAD_OP);
}