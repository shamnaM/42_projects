/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmuhamm <shmuhamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:35:14 by shmuhamm          #+#    #+#             */
/*   Updated: 2023/09/10 12:03:32 by shmuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freenod(t_list **list)
{
	char	*buf;
	t_list	*lastnode;
	t_list	*balnod;
	int		i;
	int		k;

	k = 0;
	i = 0;
	buf = malloc(BUFFER_SIZE + 1);
	balnod = malloc(sizeof(t_list));
	if (buf == NULL || balnod == NULL)
		return ;
	lastnode = ft_lstlast(*list);
	while (lastnode->content[i] && lastnode->content[i] != '\n')
		i++;
	while (lastnode->content[i] != '\0' && lastnode->content[i++])
		buf[k++] = lastnode->content[i];
	buf[k] = '\0';
	balnod->content = buf;
	balnod->next = NULL;
	clear_list(list, balnod, buf);
}

char	*ft_getline(t_list *list)
{
	int		len_newline;
	char	*next_line;

	if (list == NULL)
		return (NULL);
	len_newline = ft_strlen(list);
	next_line = malloc(len_newline + 2);
	if (!next_line)
		return (NULL);
	ft_ncopy(list, next_line);
	return (next_line);
}

void	add_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*lastnode;

	if (list == NULL)
		return ;
	lastnode = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (lastnode == NULL)
		*list = new_node;
	else
		lastnode->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	ft_read(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		buf[char_read] = '\0';
		if (char_read == 0)
		{
			free(buf);
			return ;
		}
		add_list(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	t_list			*temp;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &next_line, 0) < 0)
	{
		while (list)
		{
			temp = (list)->next;
			free((list)->content);
			free(list);
			list = temp;
		}
		list = NULL;
		return ((NULL));
	}
	ft_read(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_getline(list);
	ft_freenod(&list);
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	// line = get_next_line(fd);
}
