/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_printf.h                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:29:43 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:29:43 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_vprintf(char const *format, va_list arg);

#endif
