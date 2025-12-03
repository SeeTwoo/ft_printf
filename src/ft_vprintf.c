/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_vprintf.c                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);

int		argument_handling(t_pf *pf);
int		regular_string(t_pf *pf);

static int	init(t_pf *pf, char const *format)
{
	pf->buf_sz = 256;
	pf->buf = ft_malloc(sizeof(char) * pf->buf_sz);
	if (!pf->buf)
		return (1);
	pf->format = format;
	pf->len = 0;
	return (0);
}

int	ft_vprintf(char const *format, va_list arg)
{
	t_pf	pf;
	int		ret;

	if (!format)
		return (-1);
	va_copy(pf.arg, arg);
	if (init(&pf, format) == 1)
		return (-1);
	while (*(pf.format))
	{
		if (*(pf.format) == '%' && argument_handling(&pf) == -1)
			return (ft_free(pf.buf), -1);
		else if (regular_string(&pf) == -1)
			return (ft_free(pf.buf), -1);
	}
	ret = write(1, pf.buf, pf.len);
	ft_free(pf.buf);
	va_end(pf.arg);
	return (ret);
}
