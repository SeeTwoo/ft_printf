#ifndef ARGUMENT_STRUCTS_H
# define ARGUMENT_STRUCTS_H

typedef struct s_nbr
{
	long	n;
	long	abs;
	int		pair;
	int		len;
	int		padding;
	char	padding_char;
	char	*padding_start;
	char	*number_start;
	char	*temp;
	int		full_len;
	char	pairs_literal[200];
}	t_nbr;

typedef struct s_str
{
	char	*s;
	size_t	s_len;
	size_t	padding;
	size_t	full_len;
}	t_str;

typedef struct s_arg
{
	size_t	full_len;
	size_t	padding_len;
	char	*padding_start;
	char	*arg_start;
}

#endif
