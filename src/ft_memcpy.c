#include <string.h>
#include <emmintrin.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	size_t	j;
	__m128i	vect;

	i = 0;
	j = i + 16;
	while (j < n)
	{
		vect = _mm_loadu_si128((__m128i*)src + i);
		_mm_storeu_si128((__m128i*)dest + i, vect);
		i = j;
		j += 16;
	}
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

int	main(void) {
	char	src[] = "hello";
	char	dest[6];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("dest : %s\n", dest);
	return (0);
}
