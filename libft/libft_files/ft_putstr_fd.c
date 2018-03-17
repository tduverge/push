/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:53 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:53 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	if (!(s))
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
