/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:38 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:38 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = dst;
	source = (unsigned char *)src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		if (*source == (unsigned char)c)
			return (dest);
		source++;
		n--;
	}
	return (NULL);
}
