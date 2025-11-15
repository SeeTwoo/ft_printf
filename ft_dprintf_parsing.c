#include "libft.h"

void	parse_specifier(t_pfvars *pf)
{
	if ((pf->format)[1] == 's')
		pfstr(va_arg(pf->arg, char *), pf);
	if ((pf->format)[1] == 'd')
		pfnbr(va_arg(pf->arg, int), pf);
	pf->format += 2;
}
