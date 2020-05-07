/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 00:38:47 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/07 07:11:11 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *ch_s1;
	const unsigned char *ch_s2;
	const unsigned long *long_s1;
	const unsigned long *long_s2;

	long_s1 = (const unsigned long*)s1;
	long_s2 = (const unsigned long*)s2;
	while (*long_s1 == *long_s2 && n > sizeof(long) && *s1 != '\0')
	{
		n = n - sizeof(long);
		long_s1++;
		long_s2++;
	}
	ch_s1 = (const unsigned char*)long_s1;
	ch_s2 = (const unsigned char*)long_s2;
	while (*ch_s1 == *ch_s2 && n && *s1 != '\0')
	{
		n--;
		ch_s1++;
		ch_s2++;
	}
	if (!n)
		return (0);
	return (*ch_s1 - *ch_s2);
}