/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:14:10 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/23 14:59:53 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_select_len_res(char *search, char *replacedby, char *str)
{
	size_t	len_str;
	size_t	len_search;
	size_t	len_replacedby;

	len_str = ft_strlen(str);
	len_search = ft_strlen(search);
	len_replacedby = ft_strlen(replacedby);
	return (len_str + (len_replacedby - len_search));
}

char			*ft_replace(char *search, char *replacedby, char *str)
{
	char	*result;
	char	*ftstrstr;
	int		i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	result = ft_strnew(ft_select_len_res(search, replacedby, str));
	ftstrstr = ft_strstr(str, search);
	i = -1;
	while (ft_strcmp(&str[++i], ftstrstr) != 0)
		result[i] = str[i];
	ft_strcat(result, replacedby);
	j = i + ft_strlen(replacedby);
	i += ft_strlen(search);
	while (str[i] != '\0')
		result[j++] = str[i++];
	return (result);
}
