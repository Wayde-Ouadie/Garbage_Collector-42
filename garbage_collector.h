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

typedef enum e_mode
{
	FREE,
	MALLOC
}	t_mode;

typedef struct s_memory
{
	void			*ptr;
	struct s_memory		*next;
}	t_memory;

void	*g_malloc(size_t size, t_mode mode);
#endif
