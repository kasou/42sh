/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midoubih <midoubih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:24:46 by midoubih          #+#    #+#             */
/*   Updated: 2014/03/26 17:24:56 by midoubih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
}

int				ft_tablen(char **tab)
{
	int			res;

	res = 0;
	while (tab[res])
		res++;
	return (res);
}