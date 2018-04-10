/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:49 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!(s))
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
