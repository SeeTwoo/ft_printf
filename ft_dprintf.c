/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:26:56 by walter            #+#    #+#             */
/*   Updated: 2025/04/04 03:32:06 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	init(int fd, t_pfvars *pf, char const *format)
{
	pf->format = format;
	pf->ret_val = 0;
	pf->current_size = 0;
	pf->fd = fd;
}

int	ft_dprintf(int fd, char const *format, ...)
{
	t_pfvars	pf;

	va_start(pf.arg, format);
	init(fd, &pf, format);
	while (*(pf.format))
	{
		if (buffer_is_full(&pf))
			flush_buffer(&pf);
		else
			fill_buffer(&pf);
	}
	if (pf.current_size > 0)
	{
		write(fd, pf.buff, pf.current_size);
		pf.ret_val += pf.current_size;
	}
	return (pf.ret_val);
}
