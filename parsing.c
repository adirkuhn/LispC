#include <stdio.h>
#include <stdlib.h> 

#ifdef _WIN32
#include <string.h>
#include "win_editline.h"
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

#include "lib/mpc/mpc.h"
#include "evaluation.h"

int main(int argc, char** argv) {
	
	/* Print Version and Exit Information */
	puts("Lispy Version 0.0.0.0.1");
	puts("Press CTRL+C to Exit\n");

	/* parsers */
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lispy = mpc_new("lispy");

	mpc_result_t r;

	/* define polish notation grammar pattern */
	mpca_lang(MPCA_LANG_DEFAULT, 
		"                                            \
		number: /-?[0-9]+/;                          \
		operator: '+' | '-' | '/' | '*';             \
		expr: <number> | '(' <operator> <expr>+ ')'; \
		lispy: /^/ <operator> <expr>+ /$/;           \
		",
		Number, Operator, Expr, Lispy);
	
	while(1) {
		/* Output prompt and get input */
		char *input  = readline("lispy> ");

		/* Add input to history */
		add_history(input);

		if (mpc_parse("<stdin>", input, Lispy, &r)) {

			long result = evaluation(r.output);
			printf("%li\n", result);

			mpc_ast_delete(r.output);
		}
		else {
			mpc_err_print(r.output);
			mpc_err_delete(r.output);
		}

		/* Free retrived input */
		free(input);
	}

	/* Undefine and Delete our Parsers */
	mpc_cleanup(4, Number, Operator, Expr, Lispy);
}
