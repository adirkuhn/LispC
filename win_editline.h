static char buffer[2048];

/* Fake readline function */
char* readline(char *prompt)
{
	fputd(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char *cpy = malloc(strlen(buffer) + 1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy) - 1] = '\0';

	return cpy;
}

/* Fake add_history function */
void add_history(char * do_nothing);
