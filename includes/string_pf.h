#ifndef STRING_PF_H
# define STRING_PF_H

typedef struct s_str
{
	char	*s;
	size_t	s_len;
	char	*s_start;
	size_t	padding;
	char	*padding_start;
	size_t	full_len;
}	t_str;

#endif
