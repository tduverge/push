/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:51:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:51:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	while ((i < src_len) && (dest_len + i < size - 1) && (size != 0))
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (src_len + dest_len);
}
