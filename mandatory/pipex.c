/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/24 12:21:57 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_index(char **env)
{
	int i;
	
	i = 0;
	while (env[i])
	{
		if (ft_strcmp("PATH", env[i] , 4) == 0)
			return(i);
		i++;
	}
	return(-1);
}


int main(int ac, char **av, char  **env)
{
	int index;
	int i;
	char **str;
	char *ptr;
	
	index = ft_index(env);
	i = 0;
	// if (ac != 5)
	// 	return(1);
	str = ft_split(env[i] + 5, ':');
	
	while (str[i])
	{
		ptr = ft_strjoin(str[i], av[2]);
		access(ptr, X_OK);

		i++;
		
	}
	
}