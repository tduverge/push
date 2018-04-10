/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:37 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:37 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	if (!(res = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
