/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:51:16 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:51:16 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	save;

	if (!(s))
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		save = s[i];
		s[i] = s[len - 1];
		s[len - 1] = save;
		i++;
		len--;
	}
	return (s);
}
