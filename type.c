#include "type.h"

/* create a new number of type lval */
lval* lval_num(long x) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_NUM;
	v->num = x;

	return v;
}

/* create a new error of type lval */
lval* lval_err(char* e) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_ERR;
	v->err = malloc(strlen(e) + 1);
	strcpy(v->err, m);

	return v;
}

/* create a new symbol of type lval */
lval* lval_sym(char* s) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_SYM;
	v->sym = malloc(strlen(s) + 1);
	strcpy(v->sym, s);

	return v;
}

/* create a new Sexpr of type lval */
lval* lval_sexpr(void) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_SEXPR;
	v->count = 0;
	v->cell = NULL;

	return v;
}


/* delete a lval */
void lval_del(lval* v) {

	switch(v->type) {
		/* do nothing special for numbers */
		case LVAL_NUM:
			break;

		/* For Error or Symbol free string data */
		case LVAL_ERR:
			free(v->err);
			break;
		case LVAL_SYM:
			free(v->sym);
			break;

		/* if Sexpr then delete all elements inside */
		case LVAL_SEXPR:
			for (int i = 0; i < v->count; i++) {
				lval_del(v->cell[i]);
			}
			free(v->cell);
			break;

	}

	/* free the memory allocated for the "lval" struct itself */
	free(v);
}

/* print a lval */
void lval_print(lval v) {
	switch (v.type) {
		case LVAL_NUM:
			printf("%li", v.num);
			break;

		case LVAL_ERR:
			switch (v.err) {
				case LERR_DIV_ZERO:
					printf("Error: Division by zero!");
					break;
				case LERR_BAD_OP:
					printf("Error: Invalid operator!");
					break;
				case LERR_BAD_NUM:
					printf("Error: Invalid number!");
					break;
			}
			break;
	}
}

/* print a lval type with new line */
void lval_println(lval v) {
	lval_print(v);
	putchar('\n');
}
