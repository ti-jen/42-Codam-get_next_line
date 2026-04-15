/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:12:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/15 10:26:56 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif


int ft_memadd(char *dest , const char *src, size_t n)
{
	int i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return(i);
}

char	*ft_memcpy(char *src, size_t n)
{
	char			*str;
	
	str = malloc(n + 1);
	str[n] = '\0';
	while (n > 0)
	{
		n--;
		str[n] = src[n];
	}
	return (str);
}

t_list	*ft_lstadd_back(t_list *lst, char * content, int size)
{
	t_list	*temp;
	t_list	*new;
	if (size <= 0)
		return (lst);
	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		lst ->content = ft_memcpy(content, size);
		lst	->lenght = size;
		lst -> next = NULL;
		return (lst);
	}
	temp = (lst);
	new = (t_list *)malloc(sizeof(t_list));
	new ->content = ft_memcpy(content, size);
	new ->lenght = size;
	new -> next = NULL;
	while (temp-> next)
	{
		temp = temp-> next;
	}
	temp->next = new;
	
	return (lst);
}

int ft_is_line(char *lst, size_t size)
{
	size_t i = 0;
	if (!size || !lst)
		return(0);
	while(lst[i] != '\n')
	{
		i++;
		if (i >= size)
			return(0);
	}
	return(i + 1);
}

int ft_line_lenght(t_list * l, bool end)
{
	t_list *temp;
	int i = 0;
	
	temp = l;
	while(temp->next)
	{
		i = i + temp->lenght;
		temp = temp->next;
	}
	if(!end)
		i = i + ft_is_line(temp->content, temp->lenght);
	else
		i = i + temp->lenght;
	return (i);
}

t_list *ft_split_line(char *str, size_t n, t_list *l)
{
	int i;
	int j;
	char *dest;
	
	i = 0;
	j = 0;
	while (l->content[i] != '\n')
	{
		str[i + n] = l->content[i];
		i++;
	}
	str[i + n] = '\n';
	i++;
	str[i + n] = '\0';
	l->lenght = l->lenght - i;
	if (l->lenght <= 0)
	{
		free(l->content);
		free(l);
		l = NULL;
		return(l);
	}
	dest = malloc((l->lenght) + 1);
	while (l->content[i + j] != '\0')
	{
		dest[j] = l->content[i + j];
		j++;
	}
	dest[j] = '\0';
	free (l->content);
	l->content = dest;
	return(l);
}


t_list *ft_make_line(char *str, t_list *l, bool end)
{
	int i;
	t_list *temp;

	i = 0;
	while(l->next)
	{
		i = i + ft_memadd(str, l->content, i);
		temp = l;
		l = l->next;
		free(temp->content);
		free(temp);
	}
	if	(end)
	{
		ft_memadd(str, l->content, i);
		str[i + l->lenght] = '\0';
		free(l->content);
		free(l);
	}
	else
		l = ft_split_line(str, i, l);
	return(l);
}