/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/02 20:28:32 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// void	leak()
// {
// 	system("leaks pipex");
// }

int	main(int ac, char **av, char **env)
{
	int	stdin_;
	int	stdout_;
	int	infile;

	// atexit(leak);
	stdin_ = dup(0);
	stdout_ = dup(1);
	if (ac != 5)
		error_msg(-2, "Invalid Nmber of Arguments\n");
	infile = open(av[1], O_RDONLY);
	error_msg(infile, "Infile!!");
	first_child(av, env, &infile);
	second_child(av, env);
	dup2(stdin_, 0);
	dup2(stdout_, 1);
	while (wait(0) != -1)
		;
}
