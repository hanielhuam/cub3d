/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:17:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 20:58:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "libft.h"

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*before;
}					t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **dlist, t_dlist *new);
int		ft_dlstsize(t_dlist *dlist);
t_dlist	*ft_dlstlast(t_dlist *dlist);
void	ft_dlstadd_back(t_dlist **dlist, t_dlist *new);
void	ft_dlstdelone(t_dlist *element, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlist, void (*del)(void *));
void	ft_dlstiter(t_dlist *dlist, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *dlist, void *(*f)(void *), void (*del)(void *));

#endif 
