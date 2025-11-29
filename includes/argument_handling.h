#ifndef ARGUMENT_HANDLING_H 
# define ARGUMENT_HANDLING_H 

#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "argument.h"
#include "e_type.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int	pf_realloc(t_pf *pf, size_t n);
int	ft_strtoi(char const *s, char const **end);

//int		char_pf(t_pf *pf, t_spec spec);
int		decimal_pf(t_pf *pf, t_spec spec, t_arg *arg);
//int		percent_pf(t_pf *pf, t_spec spec);
//int		string_pf(t_pf *pf, t_spec spec);
//int		unsigned_base_pf(t_pf *pf, t_spec spec);

static const enum e_type	g_types[256] = {
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

typedef	int	(*t_argfunc)(t_pf *pf, t_spec spec, t_arg *arg);

static const t_argfunc	g_handlers[8] = {
[CHAR] = NULL, //&character_pf,
[PTR] = NULL, //NULL, //&pointer_pf,
[INT] = decimal_pf,
[UINT] = NULL, //&unsigned_pf,
[UPHEX] = NULL, //&uphex_pf,
[LOHEX] = NULL, //&lohex_pf,
[STR] = NULL, //&string_pf
[PERCENT] = NULL
};

static const enum e_flag	g_flags[49] = {
[' '] = SPACE,
['#'] = SHARP,
['-'] = DASH,
['+'] = PLUS,
['0'] = ZERO,
};

#endif
