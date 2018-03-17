/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:57 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:57 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s11;
	unsigned char *s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (*s11 == *s22 && *s11 != '\0')
	{
		s11++;
		s22++;
	}
	return (*s11 - *s22);
}
