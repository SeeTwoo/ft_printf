#include "struct_pf.h"

void	*ft_realloc(void *, size_t);

int	pf_realloc(t_pf *pf, int offset) {
	if (pf->len + offset < pf->buf_sz)
		return (0);
	while (pf->len + offset > pf->buf_sz)
		pf->buf_sz *= 2;
	pf->buf = ft_realloc(pf->buf, pf->buf_sz);
	if (!pf->buf)
		return (-1);
	return (0);
}
