/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:05:22 by oel-feng          #+#    #+#             */
/*   Updated: 2024/08/27 00:05:25 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

static t_memory	*create_node(void *ptr)
{
	t_memory	*new;

	new = malloc(sizeof(t_memory));
	if (!new)
		return (NULL);
	new->address = ptr;
	new->next = NULL;
	return (new);
}

static t_memory	*find_last(t_memory **head)
{
	t_memory	*current;

	current = *head;
	if (!head || !*head)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

static void	lst_add_back(t_memory **head, t_memory *new)
{
	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
		find_last(head)->next = new;
}

static void	free_memory(t_memory **head)
{
	t_memory	*current;
	t_memory	*next;

	current = *head;
	if (!head || !*head)
		return ;
	while (current)
	{
		next = current->next;
		if (current->address)
		{
			free(current->address);
			current->address = NULL;
		}
		free(current);
		current = next;
	}
	*head = NULL;
}

void	*grb_coll(size_t size, t_mode mode)
{
	static t_memory	*memory_list;
	t_memory		*tracker;
	void			*ptr;

	if (mode == MALLOC)
	{
		ptr = malloc(size);
		if (!ptr)
		{
			fprintf(stderr, "Error: Memory allocation failed.\n");
			grb_coll(0, FREE);
			exit(EXIT_FAILURE);
		}
		tracker = create_node(ptr);
		if (!tracker)
		{
			free(ptr);
			fprintf(stderr, "Error: Memory allocation failed.\n");
			grb_coll(0, FREE);
			exit(EXIT_FAILURE);
		}
		lst_add_back(&memory_list, tracker);
		return (ptr);
	}
	else if (mode == FREE)
		free_memory(&memory_list);
	return (NULL);
}

