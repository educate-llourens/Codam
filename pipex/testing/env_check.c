/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 17:24:44 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/03 17:46:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    char **env = environ;
    while (*env) 
	{
        printf("%s\n", *env);
        env++;
    }
    return 0;
}