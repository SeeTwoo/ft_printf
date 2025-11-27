#ifndef ARGUMENT_HANDLING_H 
# define ARGUMENT_HANDLING_H 

#include "argument.h"
#include "flags.h"

//int		char_pf(t_pf *pf, t_spec spec);
int		decimal_pf(t_pf *pf, t_spec spec, t_arg *arg);
//int		percent_pf(t_pf *pf, t_spec spec);
//int		string_pf(t_pf *pf, t_spec spec);
//int		unsigned_base_pf(t_pf *pf, t_spec spec);

static const enum e_kind	g_types[256] = {
[0 ...'%' - 1] = NULL,
['%'] = PERCENT,
['X'] = UPHEX,
['c'] = CHAR,
['d'] = INT,
['i'] = INT,
['p'] = PTR,
['s'] = STR,
['u'] = UINT,
['x'] = LOHEX,
};

typedef	int	(*t_argfunc)(t_pf *pf, t_spec spec);

static const t_argfunc	g_handlers[7] {
[CHAR] = NULL, //&character_pf,
[PTR] = NULL, //NULL, //&pointer_pf,
[INT] = &decimal_pf,
[UINT] = NULL, //&unsigned_pf,
[UPHEX] = NULL, //&uphex_pf,
[LOHEX] = NULL, //&lohex_pf,
[STR] = NULL, //&string_pf
}

static const enum e_flag	g_flags[49] {
[' '] = SPACE,
['#'] = SHAPR,
['-'] = DASH,
['+'] = PLUS,
['0'] = ZERO,
}

#endif
