/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:35:29 by shmuhamm          #+#    #+#             */
/*   Updated: 2023/09/08 16:48:53 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list, t_list *balnod, char *buf)
{
	t_list	*temp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	{
		if (balnod->content[0])
			*list = balnod;
		else
		{
			free(buf);
			free(balnod);
		}
	}
}

void	ft_ncopy(t_list *list, char *next_line)
{
	int	i;
	int	k;

	k = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				next_line[k++] = '\n';
				next_line[k] = '\0';
				return ;
			}
			next_line[k] = list->content[i];
			i++;
			k++;
		}
		list = list->next;
	}
	next_line[k] = '\0';
}

int	ft_strlen(t_list *list)
{
	int	i;
	int	k;

	if (list == NULL)
		return (0);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				k++;
				return (k);
			}
			k++;
			i++;
		}
		list = list->next;
	}
	return (k);
}

t_list	*ft_lstlast(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return (0);
	tmp = list;
	if (tmp == 0)
		return (NULL);
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}

int	ft_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		list = list->next;
	}
	return (0);
}
