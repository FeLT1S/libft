/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 04:22:41 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/17 23:46:00 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)
#define HIGHBITS (LOWBITS << 7)

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ch = s;
	const unsigned long	*long_ch;
	const unsigned long	long_c = (unsigned char)c * LOWBITS;

	while (((unsigned long)ch & (sizeof(long) - 1)) != 0 && n != 1)
	{
		if (*ch == (unsigned char)c)
			return ((void *)ch);
		ch++;
		n--;
	}
	long_ch = (unsigned long*)ch;
	while (((((*long_ch ^ long_c) - LOWBITS) & ~(*long_ch ^ long_c) \
	& HIGHBITS) == 0) && (n > sizeof(long)))
	{
		n = n - sizeof(long);
		long_ch++;
	}
	ch = (unsigned char*)long_ch;
	while (*ch != (unsigned char)c && n-- != 1)
		ch++;
	return (*ch == (unsigned char)c ? (void *)ch : NULL);
}
