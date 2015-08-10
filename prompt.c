#include <stdio.h>
#include <stdlib.h> 

#ifdef _WIN32
#include <string.h>
#include "win_editline.h"
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
	
	/* Print Version and Exit Information */
	puts("Lispy Version 0.0.0.0.1");
	puts("Press CTRL+C to Exit\n");

	
	while(1) {
		/* Output prompt and get input */
		char *input  = readline("lispy> ");

		/* Add input to history */
		add_history(input);

		/* echo input to the user */
		printf("No you're a %s\n", input);

		/* Free retrived input */
		free(input);

	}
}
