#include "type.h"

lval evaluation(mpc_ast_t* t);
lval evaluation_op(lval x, char* op, lval y);