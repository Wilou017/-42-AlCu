/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:44:31 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/21 20:23:56 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# define BUFF_SIZE 4096
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_board
{
	t_tab		array;
	t_tab		tmp;
	int			line;
	int			nb;
	int			odd;
	t_list		**lst;
}				t_board;

typedef struct	s_info
{
	char		*info;
	int			fd;
}				t_info;

void			ft_lose_win(int i);
void			ft_print(int i);
int				ft_get_int(int stream);
t_board			*ft_init(t_list *lst);
int				ft_error(void);
int				ft_select_line(t_tab array);
int				ft_select_nb(t_tab array, int line);
t_tab			ft_remouve(t_tab array, int line, int nb);
int				ft_creatlist(int fd, char *file, t_board **board);
int				get_next_line(int const fd, char **line);

#endif
