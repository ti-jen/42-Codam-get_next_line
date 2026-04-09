/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:12:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/09 11:10:22 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
// #include "get_next_line.h"

typedef struct s_list
{
	char			*content;
	int				line;
	struct s_list	*next;
}	t_list;


void	ft_lstadd_back(t_list *lst, char * content, int line)
{
	t_list	*temp;
	t_list	*new;
	if (!lst->content)
	{
		lst->content = content;
		lst->line = line;
		return ;
	}
	temp = (lst);
	new = (t_list *)malloc(sizeof(t_list));
	new ->content = content;
	new ->line = line;
	new -> next = NULL;
	while (temp-> next)
	{
		temp = temp-> next;
	}
	temp->next = new;
}

int	ft_strstore(t_list *lst, const char *src, size_t size)
{
	char *new;
	size_t i;
	size_t p;
	size_t j;
	int l;
	l = 0;
	i = 0;
	j = 0;
	while (j + i != size)
	{
		i++;
			if (src[j + i] == '\n')
		{
			i++;
			new = malloc((i) + 1);
			new[i] = '\0';
			p = i;
			while (i > 0)
			{	
				i--;
				new[i] = src[j + i];
			}
			ft_lstadd_back(lst, new, 1);
			j = j + p;
			l++;
		}
	}
	new = malloc(i + 1);
	new[i] = '\0';
	while (i > 0)
	{
		i--;
		new[i] = src[j + i];
	}
	l++;
	ft_lstadd_back(lst, new, 0);
	return (l);
}


char	*line_malloc(t_list *lst, char *str, int n)
{
	int i = 0;
	int j = 0;

	while (1)
	{
		while (lst->content[i] != '\0')
			i++;
		j = j + i;
		i = 0;
		if (lst-> line || (!n && !lst-> next))
			break;
		if (!lst->line && !lst->next)
		{
			return(NULL);
		}
		lst = lst->next;
	}
	str = malloc(j + 1);
	return (str);
}

t_list	*ft_strmerge(t_list *lst,char *str, int n)
{
	int i = 0;
	int j = 0;
	
	while(1)
	{
		while (lst->content[i] != '\0')
		{
			str[j + i] = lst->content[i];
			i++;
		}
		j = j + i;
		i = 0;
		if (lst-> line || (!n && !lst-> next))
			break;
		lst = lst-> next;
	}
	str[j] = '\0';
	return (lst-> next);
}

char	*make_line_list(const char *src, int n)
{
	static int i = 0;
	char *line = NULL;
	static t_list	*l;

		if (i == 0)
		{
			l = (t_list *)malloc(sizeof(t_list));
			l -> content = NULL;
			l -> next = NULL;
		}
	if(n)
		i = ft_strstore(l, src, n);	
	else
	{
		line = line_malloc(l, line, n);
		ft_strmerge(l, line, n);
		return (line);
	}
	if (l->line)
	{
		line =	l -> content;
		l = l -> next;
	}
	else
	{
		line = line_malloc(l, line, n);
		if (line)
			l = ft_strmerge(l, line, n);
		return (line);
	}
	return (line);
}

// int main ()
// {
// 	printf("=%s=", make_line_list("0123456789",10));
// 	printf("=%s=", make_line_list("ABCDE\nFGHI",10));
// 	printf("=%s=", make_line_list("abcdefghjh",10));
// 	printf("=%s=", make_line_list("",0));
// }