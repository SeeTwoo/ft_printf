/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_string.h                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:29:51 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:29:51 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

void	*ft_memset(void *p, int c, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
size_t	ft_strlen(char const *s);

#endif
