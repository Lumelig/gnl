/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:59:37 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/18 14:01:05 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s2)
		return (s1);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		free_and_null(&s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free_and_null(&s1);
	return (str);
}

char	*read_file(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_and_null(&buffer);
			free_and_null(&remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder || ft_strchr(remainder, '\n'))
			break ;
	}
	free_and_null(&buffer);
	return (remainder);
}

char	*extract_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder || !remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i])
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;
	int		j;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free_and_null(&remainder);
		return (NULL);
	}
	new_remainder = malloc(ft_strlen(remainder) - i + 1);
	if (!new_remainder)
	{
		free_and_null(&remainder);
		return (NULL);
	}
	i++;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free_and_null(&remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char *remainder;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, remainder, 0) < 0)
	{
		free_and_null(&remainder);
		return (NULL);
	}
	remainder = read_file(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}

