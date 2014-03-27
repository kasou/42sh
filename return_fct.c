/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 20:55:53 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 19:40:45 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			apply_return(t_historic **historic)
{
	int			prompt;
	t_node		*tree;
	t_token		*comlist;

	tree = NULL;
	comlist = NULL;
	write(1, "\n", 1);
	if ((*historic)->copy->size)
	{
		(*historic)->historic = add_to_historic((*historic)->historic,
												(*historic)->copy->line);
		read_comline(&comlist, (*historic)->copy->line);
		organize_com(&tree, &comlist, 1, 0);
		read_tree(tree, 0, 1);
		prompt = display_prompt();
		clear_tree(&tree);
		del_comlist(comlist);
		del_copy((*historic)->copy);
		(*historic)->prompt = prompt;
		(*historic)->copy = copy_historic((*historic)->historic, prompt);
	}
	else
		display_prompt();
}
