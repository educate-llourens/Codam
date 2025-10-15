/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:44:18 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/18 17:06:10 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_c(int c);
int	ft_print_di(int nbr);
int	ft_print_p(void *nbr);
int	ft_print_str(char *str);
int	ft_print_u(unsigned int nb);
int	ft_print_xx(unsigned long int nb, char specifier);
int	ft_printf(const char *str, ...);

#endif
