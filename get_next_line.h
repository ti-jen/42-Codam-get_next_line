/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:37:57 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/15 17:42:45 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_list
{
	char			*content;
	int				lenght;
	struct s_list	*next;
}	t_list;

char *get_next_line(int fd); 
int ft_is_line(char *lst, size_t size);
int ft_line_lenght(t_list * l, bool end);
t_list *ft_make_line(char *str, t_list *l, bool end);
t_list	*ft_lstadd_back(t_list *lst, char * content, int size);
char	*extract_line(t_list **l, int end);