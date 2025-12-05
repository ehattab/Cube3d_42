/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:53:59 by toroman           #+#    #+#             */
/*   Updated: 2025/11/18 15:13:54 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strchrr(const char *s, int c);
char	*ft_strdupp(const char *s);
char	*ft_strjoinn(char const *s1, char const *s2);
size_t	ft_strlenn(const char *s);
char	*get_next_line(int fd);

#endif
