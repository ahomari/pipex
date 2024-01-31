/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:14:45 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/31 18:33:04 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char  **env)
{
	int	i;
	int stdin_;
	int stdout_;

	stdin_ = dup(0);
	stdout_ = dup(1);
	i = 0;
	if (ac >= 5)
	{
		while (i < ac - 1)
		{
			first_child(av, env);
			second_child(av, env);
			while (wait(0) != -1)
				;
			i++;
		}
		dup2(stdin_, 0);
		dup2(stdout_, 1);
	}
	else
		return (print_msg("Invalid Nmber of Arguments\n"));
}
