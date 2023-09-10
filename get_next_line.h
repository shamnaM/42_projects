/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:35:41 by shmuhamm          #+#    #+#             */
/*   Updated: 2023/09/08 16:52:12 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <libc.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
char				*get_next_line(int fd);
t_list				*ft_lstlast(t_list *list);
int					ft_newline(t_list *list);
int					ft_strlen(t_list *list);
void				ft_ncopy(t_list *list, char *next_line);
void				clear_list(t_list **list, t_list *balnod, char *buf);
void				save_bal(t_list **list, t_list *balnod, char *buf);

#endif