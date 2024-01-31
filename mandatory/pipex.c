/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/31 18:03:53 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char  **env)
{
	int stdin_;
	int stdout_;

	stdin_ = dup(0);
	stdout_ = dup(1);
	if (ac != 5)
		return (print_msg("Invalid Nmber of Arguments\n"));
	first_child(av, env);
	second_child(av, env);
	dup2(stdin_, 0);
	dup2(stdout_, 1);
	while (wait(0) != -1)
		;
}
