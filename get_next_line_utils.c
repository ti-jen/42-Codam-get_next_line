/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:12:55 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/13 12:57:40 by tkroon           ###   ########.fr       */
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
	while (j + i < size)
	{
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
		i++;
	}
	if(j >= size)
		return (l);
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

int	line_size(t_list *lst, int n)
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
			return(0);
		}
		lst = lst->next;
	}
	return (j);
}

char	*ft_strmerge(t_list *lst, int n)
{
	int i = 0;
	int j = 0;
	char *str;
	t_list *temp;

	str = malloc(line_size(lst, n) + 1);
	while(1)
	{
		while (lst->content[i] != '\0')
		{
			str[j + i] = lst->content[i];
			i++;
		}
		j = j + i;
		i = 0;
		temp = lst;
		lst = lst-> next;
		if (temp-> line || (!n && !temp-> next))
		{
			free(temp->content);
			free(temp);
			break;
		}
		free(temp->content);
		free(temp);
	}
	str[j] = '\0';
	return (str);
}

char	*make_line_list(const char *src, int n)
{
	static int i = 0;
	static t_list	*l;
		if (i == 0)
		{
			l = (t_list *)malloc(sizeof(t_list));
			l -> content = NULL;
			l -> next = NULL;
		}
	if(n)
	{
		i = ft_strstore(l, src, n);	
	}
	else
	{
		i = 0;
		return (ft_strmerge(l, n));
	}
	if (line_size(l, n))
	{
		i = 0;
		return (ft_strmerge(l, n));
	}
	return(NULL);
}

int main ()
{
	char *line;
	
	
	line = make_line_list("0123456789",10);
	line = make_line_list("\n987654321",10);
	line = make_line_list("09\n0123456",10);
	line = make_line_list("78901\n9876",10);
	line = make_line_list("5432109\n01",10);
	line = make_line_list("23456789",8);
	line = make_line_list("",0);
	// printf("=%s=", make_line_list("0",1));
	// printf("=%s=", make_line_list("",0));
	// // printf("=%s=", make_line_list("\n",1));
	// // printf("=%s=", make_line_list("0123456789\n",11));
	// // printf("=%s=", make_line_list("\n",1));
	// // printf("=%s=", make_line_list("9876543210\n",11));
}