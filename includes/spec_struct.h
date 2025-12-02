#ifndef SPEC_STRUCT_H
# define SPEC_STRUCT_H

# include "e_type.h"

typedef struct s_spec	t_spec;

struct s_spec
{
	int			width;
	int			precision;
	char		flags;
	enum e_type	type;
};

#endif
