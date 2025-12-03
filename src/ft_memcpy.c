/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_memcpy.c                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <emmintrin.h>
#include <stdio.h>

/*
void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	__m128i	vect;
	void	*ret;

	ret = dest;
	while (n >= 16)
	{
		vect = _mm_loadu_si128((__m128i *)src);
		_mm_storeu_si128((__m128i *)dest, vect);
		n -= 16;
		dest += 16;
		src += 16;
	}
	while (n-- > 0)
		*((char *)dest++) = *((char *)src++);
	return (ret);
}
*/

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	void	*ret;

	ret = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ret);
}
