/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 21:19:15 by wtrembla          #+#    #+#             */
/*   Updated: 2014/03/27 19:10:07 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*check_pwd(void)
{
	t_env	*env;
	int		i;

	i = 0;
	env = init_env(environ);
	while (ft_strncmp("PWD=", env->environ[i], 4) && env->environ[i])
		i++;
	if (!env->environ[i])
		return (NULL);
	return (env->environ[i] + 4);
}

static char		*check_user(void)
{
	t_env	*env;
	int		i;

	i = 0;
	env = init_env(environ);
	while (ft_strncmp("USER", env->environ[i], 4) && env->environ[i])
		i++;
	if (!env->environ[i])
		return ("guest");
	return (env->environ[i] + 5);
}

int				display_prompt(void)
{
	char	*pwd;
	char	*user;

	pwd = check_pwd();
	user = check_user();
	ft_putstr("$ ");
	ft_putstr(user);
	ft_putstr(" ~");
	ft_putstr(pwd);
	ft_putstr(" > ");
	return ((int)(ft_strlen(user) + ft_strlen(pwd) + 7));
}
