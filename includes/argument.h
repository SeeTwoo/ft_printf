/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   argument.h                                          :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:28:53 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:28:53 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H

# include <stdint.h>
# include <stddef.h>

# include "e_type.h"

union u_arg
{
	int			nbr;
	uintptr_t	ptr;
	char		c;
	char		*str;
	uint32_t	unbr;
};

typedef struct s_arg	t_arg;

struct s_arg
{
	union u_arg	val;
	char		*raw;
	size_t		len;
	char		*prefix;
	size_t		prefix_len;
	size_t		zeroes;
	size_t		padding;
	size_t		full_len;
	char		buf[16];
};

#endif
