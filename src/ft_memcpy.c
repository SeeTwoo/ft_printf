#include <string.h>
#include <emmintrin.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
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

/*
int	main(void) {
	char	src[] = "hello";
	char	lg_src[] = "this is the base 16 0123456789abcdef";
	char	dest[64];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("dest : %s\n", dest);
	ft_memcpy(dest, lg_src, strlen(lg_src) + 1);
	printf("dest : %s\n", dest);
	return (0);
}
*/
