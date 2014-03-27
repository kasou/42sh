/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:25:23 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 17:39:37 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	or_proc(t_node *tree, int fd_in, int fd_out)
{
	extern t_id		g_pid;

	//printf("on rentre\n");
	ft_putstr_fd("on rentre",2);
	read_tree(tree->left, fd_in, fd_out);
	if (WIFSIGNALED(g_pid.id) || g_pid.built == 0)
	{
		ft_putstr_fd("on  execute droite 1",2);
		//printf("on execute droite 1\n");
		read_tree(tree->right, fd_in, fd_out);
	}
	else if (g_pid.father != 0)
	{
		if (WIFEXITED(g_pid.id) && WEXITSTATUS(g_pid.id) > 0)
		{
			ft_putstr_fd("on execute droite 2",2);

			//printf("on execute droite 2\n");
			read_tree(tree->right, fd_in, fd_out);

		}
			
	}
	g_pid.father = 0;
	g_pid.id = 0;
	g_pid.built = -1;	
}
