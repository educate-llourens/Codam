/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 15:30:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 17:47:52 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
	Iterates the list ’lst’ and applies the function’f’ on the content of 
	each node. Creates a newlist resulting of the successive applications 
	of the function ’f’. The ’del’ function is used todelete the content 
	of a node if needed.
*/

static void	clear_list(t_list *new_list, void (*del)(void *));

t_list	*ft_lstmap(t_list *list,
					void *(*function)(void *),
					void (*del)(void *))
{
	t_list	*new_node;
	t_list	*head;
	t_list	*last_node;
	void	*new_content;

	if (!list || !function || !del)
		return (NULL);
	head = NULL;
	while (list)
	{
		new_content = function(list->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (del(new_content), clear_list(head, del), NULL);
		if (!head)
			head = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		list = list->next;
	}
	return (head);
}

static void	clear_list(t_list *new_list,
						void (*del)(void *))
{
	t_list	*temp;

	if (!new_list || !del)
		return ;
	while (new_list)
	{
		temp = new_list->next;
		ft_lstdelone(new_list, del);
		new_list = temp;
	}
}
