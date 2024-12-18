/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:59:30 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/06 16:05:34 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	char			*cs;

	cs = (char *)s;
	cc = (char)c;
	while (*cs)
	{
		if (*cs == cc)
			return (cs);
		cs++;
	}
	if (cc == '\0')
		return (cs);
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}