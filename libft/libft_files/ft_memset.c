/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:44 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:44 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*a;
	unsigned char	nb;

	i = 0;
	a = b;
	nb = (unsigned char)c;
	while (i < len)
	{
		a[i] = nb;
		i++;
	}
	return (b);
}
