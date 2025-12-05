/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:07:46 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/25 13:36:45 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#define HIMAGIC 0x8080808080808080UL
#define LOMAGIC 0x0101010101010101UL

size_t const	*ft_swar(size_t const *p)
{
	size_t	word;

	while (1)
	{
		word = *p;
		if (((word - LOMAGIC) & ~word & HIMAGIC) != 0)
			return (p);
		p++;
	}
}

size_t	ft_strlen(char const *s)
{
	unsigned char const	*p;
	size_t				i;

	p = (unsigned char const *)s;
	while ((uintptr_t)p & (sizeof(uintptr_t) - 1))
	{
		if (*p == '\0')
			return (p - (unsigned char const *)s);
		p++;
	}
	p = (unsigned char const *)ft_swar((size_t const *)p);
	i = 0;
	while (i < sizeof(size_t))
	{
		if (p[i] == '\0')
			return (p + i - (const unsigned char *)s);
		i++;
	}
	return (0);
}
