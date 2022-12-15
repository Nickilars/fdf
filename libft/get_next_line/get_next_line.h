/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/15 17:11:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/uio.h> //"read",
# include <unistd.h> // "write","close","read",
# include <string.h> // "NULL"
# include <stdlib.h> // "malloc","free",

# include <fcntl.h> //"open",
# include <sys/types.h> //"open",
# include <sys/stat.h> //"open",

#include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

int		ft_strchr_gnl(const char *str);

char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *src);
char	*returnline(char **statik, int c_read);
char	*ft_strjoin_gnl(char const *str1, char const *str2);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);

void	ft_str2join(char **statik, char *buffer, int c_read);

#endif