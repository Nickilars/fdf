/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/15 17:07:59 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*--------- 3. strlcpy -----------*/
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen((char *)src);
	if (!dstsize)
		return (src_len);
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize < src_len)
		dst[dstsize - 1] = 0;
	else if (dstsize != 0)
		dst[i] = 0;
	return (src_len);
}

/*--------- 3. strjoin -----------*/
char	*ft_strjoin_gnl(char const *str1, char const *str2)
{
	size_t		len_max;
	size_t		i;
	size_t		j;
	char		*new_str;

	if (!str1 || !str2)
		return (NULL);
	len_max = (ft_strlen((char *)str1) + ft_strlen((char *)str2));
	new_str = malloc((len_max + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return ((char *)new_str);
}

/*--------- 4. substr -----------*/
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	if (start > ft_strlen((char *)str))
		return (ft_strdup_gnl(""));
	if (len > (ft_strlen((char *)str + start)))
		len = (ft_strlen((char *)str + start));
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*---------------- 5. strdup ------------------*/
char	*ft_strdup_gnl(const char *src)
{
	int		i;
	int		len;
	char	*dst;

	if (!src)
		return (NULL);
	len = ft_strlen((char *)src) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	i = ft_strlcpy_gnl(dst, src, len);
	if (i == len)
		return (dst);
	return (NULL);
}
