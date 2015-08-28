#include "type.h"

/* create a new number of type lval */
lval lval_num(long x) {
	lval v;
	v.type = LVAL_NUM;
	v.num = x;

	return v;
}

/* create a new error of type lval */
lval lval_err(int x) {
	lval v;
	v.type = LVAL_ERR;
	v.err = x;

	return v;
}

/* print a lval */
void lval_print(lval v) {
	switch (v.type) {
		case LVAL_NUM:
			prinf("%li", v.num);
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