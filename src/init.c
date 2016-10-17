/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:09:16 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/21 21:25:12 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static char		*ft_lstjoin(t_list *list)
{
	t_list	*tmp;
	char	*str;
	char	*strtmp;

	tmp = list;
	if (!tmp)
		return (NULL);
	str = ft_strnew(tmp->content_size);
	ft_strcpy(str, tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		strtmp = str;
		str = ft_strjoin(str, tmp->content);
		free(strtmp);
		tmp = tmp->next;
	}
	return (str);
}

static t_tab	ft_createmap(t_tab nbr)
{
	size_t	l;
	int		n;
	t_tab	map;

	l = 0;
	if (!nbr[l])
		return (NULL);
	while (nbr[l])
		l++;
	map = (t_tab)malloc(sizeof(char*) * (l + 1));
	map[l] = NULL;
	l = 0;
	while (nbr[l])
	{
		n = ft_atoi(nbr[l]);
		if ((n < 1 && nbr[l + 1] != NULL) || n > 10000)
			return (NULL);
		map[l] = ft_strnew(n);
		ft_memset(map[l++], '|', n);
	}
	return (map);
}

t_board			*ft_init(t_list *lst)
{
	t_board	*board;
	char	*str;
	t_tab	nbr;
	int		i;

	board = (t_board*)malloc(sizeof(t_board*));
	board->odd = 0;
	board->array = (t_tab)malloc(sizeof(t_tab));
	str = ft_lstjoin(lst);
	nbr = ft_strsplit(str, '\n');
	board->array = ft_createmap(nbr);
	free(str);
	i = 0;
	while (nbr[i])
		free(nbr[i++]);
	if (board->array == NULL ||
		board->array[0] == NULL ||
		board->array[0][0] == '\0')
		return (NULL);
	return (board);
}
