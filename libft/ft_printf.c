/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:05:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/04 00:53:47 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf(char *str, void *var)
{
	char *result;
	char *s1;
	void **args;

	if (str)
	{
		args = &var;
		s1 = ft_strdup(str);
		result = s1;
		if (ft_strstr(s1, "%s"))
			result = ft_replace("%s", (char*)var, result);
		if (ft_strstr(s1, "%d"))
			result = ft_replace("%d", ft_itoa(*((int *)args)), result);
		ft_putstr(result);
		if (ft_strcmp(s1, result))
			free(s1);
		free(result);
	}
}

/*int				ft_printf(char const *s, ...)
{
	int			i;
	int			len;
	va_list		ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += ft_chooseprint(ap, s[i + 1]);
			i++;
		}
		else if (s[i] != '%')
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}*/