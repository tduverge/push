/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint_nb.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 19:21:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 19:21:51 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstprint_nb(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d ", *(int*)lst->content);
		lst = lst->next;
	}
}
