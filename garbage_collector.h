/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:57:11 by oel-feng          #+#    #+#             */
/*   Updated: 2024/08/27 00:06:44 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBABE_COLLECTOR_H

# include <stdlib.h>

typedef enum e_call
{
	FREE,
	MALLOC
}	t_call;

typedef struct s_col
{
	void			*ptr;
	struct s_col	*next;
}	t_col;

t_col	*new_node(void *ptr);
void	clear_all(t_col **head);
t_col	*last_node(t_col **head);
void	add_back(t_col **head, t_col *new);
void	*g_malloc(size_t size, t_call call);
#endif