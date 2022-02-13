/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:15:14 by atchougo          #+#    #+#             */
/*   Updated: 2022/02/13 21:57:54 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void ft_puthexa_up(void * n, int * r)
// {
//     char * hexa;
//     int number;

//     number = (int)n;
//     hexa = "0123456789ABCDEF";
//     if (number < 0)
//     {
//         number = -number;
//         ft_putchar_printf((void *)'-', r);
//     }
//     if (number > 15)
//         ft_puthexa_up((void *)(number / 16), r);
//     ft_putchar_printf((void *)hexa[number % 16], r); 
// }

// void ft_puthexa_low(void * n, int * r)
// {
//     char * hexa;
//     int number;

//     number = (int)n;
//     hexa = "0123456789abcdef";
//     if (number < 0)
//     {
//         number = -number;
//         ft_putchar_printf((void *)'-', r);
//     }
//     if (number > 15)
//         ft_puthexa_low((void *)(number / 16), r);
//     ft_putchar_printf((void *)hexa[number % 16], r); 
// }

// void ft_putnbr_u(void * n, int * r)
// {
//     char * decimal;
//     unsigned int number;

//     number = (unsigned int)n;
//     decimal = "0123456789";
//     if (number > 9)
//         ft_putnbr_u((void *)(number / 10), r);
//     ft_putchar_printf((void *)decimal[number % 10], r); 
// }

// void ft_putadr(void * p, int * r)
// {
//     unsigned long nb;
//     char * hexa;

//     nb = (unsigned long)p;
//     hexa = "0123456789abcdef";
//     if (nb > 15)
//         ft_putadr((void *)(nb / 16), r);
//     ft_putchar_printf((void *)hexa[nb % 16], r); 
// }

// void	ft_putnbr_printf(void *n, int *r)
// {
//     char * decimal;
//     int number;

//     number = (int)n;
//     decimal = "0123456789";
//     if (number < 0)
//     {
//         number = -number;
//         ft_putchar_printf((void *)'-', r);
//     }
//     if (number > 9)
//         ft_putnbr_printf((void *)(number / 10), r);
//     ft_putchar_printf((void *)decimal[number % 10], r); 
// }

void ft_puthexa_up(int n, int * r)
{
    char * hexa;
    int number;

    number = n;
    hexa = "0123456789ABCDEF";
    if (number < 0)
    {
        number = -number;
        ft_putchar_printf('-', r);
    }
    if (number > 15)
        ft_puthexa_up((number / 16), r);
    ft_putchar_printf(hexa[number % 16], r); 
}

void ft_puthexa_low(int n, int * r)
{
    char * hexa;
    int number;

    number = n;
    hexa = "0123456789abcdef";
    if (number < 0)
    {
        number = -number;
        ft_putchar_printf('-', r);
    }
    if (number > 15)
        ft_puthexa_low((number / 16), r);
    ft_putchar_printf(hexa[number % 16], r); 
}

void ft_putnbr_u(unsigned int n, int * r)
{
    char * decimal;
    unsigned int number;

    number = n;
    decimal = "0123456789";
    if (number > 9)
        ft_putnbr_u((number / 10), r);
    ft_putchar_printf(decimal[number % 10], r); 
}

void ft_putadr(unsigned long p, int *r)
{
    unsigned long nb;
    char *hexa;

    nb = p;
    hexa = "0123456789abcdef";
    if (nb > 15)
        ft_putadr((nb / 16), r);
    ft_putchar_printf(hexa[nb % 16], r); 
}

void	ft_putnbr_printf(int n, int *r)
{
    char *decimal;
    int number;

    number = n;
    decimal = "0123456789";
    if (number < 0)
    {
        number = -number;
        ft_putchar_printf('-', r);
    }
    if (number > 9)
        ft_putnbr_printf((number / 10), r);
    ft_putchar_printf(decimal[number % 10], r); 
}
