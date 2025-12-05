/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_memcpy.c                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:22:15 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:22:15 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				qword_len;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n > 0 && ((uintptr_t)d % sizeof(size_t)) != 0)
	{
		*d++ = *s++;
		n--;
	}
	if (((uintptr_t)s % sizeof(size_t)) == 0)
	{
		qword_len = n / sizeof(size_t);
		while (qword_len > 0)
		{
			*(size_t *)d = *(const size_t *)s;
			d += sizeof(size_t);
			s += sizeof(size_t);
			qword_len--;
		}
		n %= sizeof(size_t);
	}
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

/*
void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	void	*ret;

	ret = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ret);
}
*/
