/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:12:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/16 12:57:32 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"

int	ft_memadd(char *dest, const char *src, size_t n, char in)
{
	int	i;

	i = 0;
	while (src[i] != in)
	{
		dest[n + i] = src[i];
		i++;
	}
	return (i);
}

t_list	*ft_lstadd_back(t_list *lst, char *content, int size)
{
	t_list	*temp;
	t_list	*new;
	char	*str;

	if (size <= 0)
		return (lst);
	temp = (lst);
	new = (t_list *)malloc(sizeof(t_list));
	new ->lenght = size;
	str = malloc(size + 1);
	str[size] = '\0';
	while (size--)
		str[size] = content[size];
	new ->content = str;
	new -> next = NULL;
	if (!temp)
		lst = new;
	else
	{
		while (temp-> next)
			temp = temp-> next;
		temp->next = new;
	}
	return (lst);
}

int	ft_line_lenght(t_list *l, bool notend)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = l;
	if (!l)
		return (0);
	while (temp->next)
	{
		i = i + temp->lenght;
		temp = temp->next;
	}
	if (!temp->lenght)
		return (0);
	while (j < temp->lenght && temp->content[j] != '\n')
		j++;
	if (j >= temp->lenght && notend)
		return (0);
	if (temp->content[j] == '\n')
		j++;
	i = i + j;
	return (i);
}

t_list	*ft_split_line(char *str, size_t n, t_list *l)
{
	int		i;
	char	*dest;

	i = 0;
	i = ft_memadd(str, l->content, n, '\n');
	str[i + n] = '\n';
	i++;
	str[i + n] = '\0';
	l->lenght = l->lenght - i;
	if (l->lenght <= 0)
	{
		free(l->content);
		free(l);
		l = NULL;
		return (l);
	}
	dest = malloc(l->lenght + 1);
	i = ft_memadd(dest, &l->content[i], 0, '\0');
	dest[i] = '\0';
	free (l->content);
	l->content = dest;
	return (l);
}

char	*extract_line(t_list **l, int end)
{
	char	*str;
	int		i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	lst = *l;
	str = malloc(ft_line_lenght(lst, end) + 1);
	while (lst)
	{
		if (!lst -> next && end)
			break ;
		i = i + ft_memadd(str, lst->content, i, '\0');
		temp = lst;
		lst = lst->next;
		free(temp->content);
		free(temp);
	}
	if (!end)
	{
		str[i] = '\0';
	}
	else
		*l = ft_split_line(str, i, lst);
	return (str);
}
