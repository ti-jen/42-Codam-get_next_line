/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkroon <tkroon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:37:57 by tkroon            #+#    #+#             */
/*   Updated: 2026/04/07 15:10:28 by tkroon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd); 
char	*ft_memcpy(const char *src, int n);
char	*make_line_list(const char *src, int n);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;