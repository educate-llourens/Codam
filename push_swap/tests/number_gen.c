/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number_gen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 13:06:02 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/11 13:06:03 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
    srand(time(NULL));

    int count = 0;
    while (count < 500) {
        long long num = ((long long)rand() * (int)INT_MAX + rand()) % ((long long)INT_MAX - INT_MIN + 1) + INT_MIN;
                printf("%lld", num);
        if (count < 499) {
            printf(" ");
        }
        count++;
    }

    return 0;
}