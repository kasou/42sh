#include "minishell.h"

int		ft_echo(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		aff_str(argv[i]);
		aff_c(' ');
	}
	aff_c('\n');
	return (0);
}
