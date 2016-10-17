/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:05:04 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/21 22:04:14 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			ft_select_line(t_tab array)
{
	int l;

	l = 0;
	while (array[l] && array[l][0] != '\0')
		l++;
	return (l - 1);
}

int			ft_select_nb(t_tab array, int line)
{
	char	*str;
	int		nb;
	int		len;

	str = ft_gather(array, 0);
	len = ft_strlen(array[line]);
	nb = 0;
	while (nb > 3 || nb < 1 || nb > len)
	{
		nb = 3 - (ft_strlen(str) % 4);
		if (nb > len)
			nb = (len % 4) - 1;
		if (nb <= 0)
			nb = 1;
	}
	free(str);
	return (nb);
}

t_tab		ft_remouve(t_tab array, int line, int nb)
{
	int len;
	int i;

	len = ft_strlen(array[line]);
	if (nb > 3 || nb < 1 || nb > len)
		return (NULL);
	i = 1;
	while (i <= nb)
		array[line][len - (i++)] = '\0';
	return (array);
}

int			ft_strisdigit(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (i != ft_strlen(buf))
		return (0);
	return (1);
}

int			ft_creatlist(int fd, char *file, t_board **board)
{
	char	*buf;
	t_list	*nouveau;

	if (fd != 0)
		fd = open(file, O_RDONLY);
	if (fd >= 0)
	{
		(*board)->lst = (t_list **)malloc(sizeof(t_list*));
		*((*board)->lst) = NULL;
		while (get_next_line(fd, &buf) > 0 && *buf != 0)
		{
			if (!ft_strisdigit(buf))
				return (0);
			buf[ft_strlen(buf)] = '\n';
			nouveau = ft_lstnew(buf, BUFF_SIZE + 1);
			ft_lstadd_push_back((*board)->lst, nouveau);
		}
		if (fd != 0)
			close(fd);
	}
	else
		return (0);
	return (1);
}
