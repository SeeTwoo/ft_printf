#ifndef STRING_PF_H
# define STRING_PF_H

typedef struct s_str
{
	char	*s;
	size_t	s_len;
	size_t	padding;
	size_t	full_len;
}	t_str;

#endif
