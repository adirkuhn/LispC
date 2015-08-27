/* lval struct */
typedef struct {
	int type;
	long num;
	int err;
} lval;

/* enumeration for lval types */
enum { LVAL_NUM, LVAL_ERR };

/* enumeration for possibles errors */
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

/* create a new number of type lval */
lval lval_num(long x);

/* create a new error of type lval */
lval lval_err(int x);

/* print a lval */
void lval_print(lval v);

/* print a lval type with new line */
void lval_println(lval v);