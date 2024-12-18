/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:43 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/06 16:04:57 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read
# include <stdlib.h> // for malloc
# include <stdio.h> // for printf and End Of File
# include <fcntl.h> // for open txt file
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *s1, char *s2);

void	free_and_null(char **ptr);

char	*read_file(int fd, char *remainder);

char	*extract_line(char *remainder);

char	*update_remainder(char *remainder);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);
#endif