/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:58 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:58 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *dest;
	char *source;

	dest = dst;
	source = (char *)src;
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return (dst);
}
