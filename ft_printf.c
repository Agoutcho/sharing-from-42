/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 07:49:01 by atchougo          #+#    #+#             */
/*   Updated: 2022/02/20 17:50:10 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_ok(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void	ft_putchar_printf(char c, int *r)
{
	write(1, &c, 1);
	*r += 1;
}

static void	ft_putstr(char *c, int *r)
{
	while (*c)
	{
		write(1, c, 1);
		*r += 1;
		c++;
	}
}

static void	ft_print_it(const char s, va_list p, int *r)
{
    static void	(*f_int[9])(int, int *) = {NULL, NULL,
		ft_putnbr_printf, NULL, ft_puthexa_up, NULL, NULL,
		ft_putnbr_printf, ft_puthexa_low};
    void *temp;

	if (!(s == '%'))
    	temp = va_arg(p, void *);
    	if (s == '%')
		ft_putchar_printf('%', r);
    else if (s % 14 == 1)
        ft_putchar_printf((char)temp, r);
    else if (s % 14 == 3 && temp != NULL)
        ft_putstr((char *)temp, r);
    else if (s % 14 == 3 && temp == NULL)
        ft_putstr("(null)", r);
    else if (s % 14 == 5)
        ft_putnbr_u((unsigned int)temp, r);
    else if (s % 14 > 1 && s % 14 < 9)
        f_int[s % 14]((int)temp, r);
	else if (s % 14 == 0)
    {
		ft_putstr("0x", r);
	    ft_putadr((unsigned long)temp, r);
    }
}
/*
//c : 1 char ok
//s : 3 char ok 
//p : 0 u long 
//d : 2 int
//i : 7 int
//u : 5 u int ok
//x : 8 int 
//X : 4 int 
//% : 9
*/

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	ptr;
	
	va_start(ptr, s);
	result = 0;
	while (*s)
	{
		if (!(*s == '%'))
            ft_putchar_printf(*(char *)s, &result);
		else if (*s++ == '%' && ft_is_ok(*s--))
			ft_print_it(*++s, ptr, &result);
		s++;
	}
	va_end(ptr);
	return (result);
}

//  int main()
//  {
// //     int u = 9;
//     // ft_printf("c : %c \nx : %x \nX : %X",'T', 95, 95);
//     // printf   ("printf    %%p : %p\n", &u);
//     // ft_printf("ft_printf %%p : %p\n", &u);
//     //  printf   ("printf    %%c : %c\n", 0);
//     //  ft_printf("ft_printf %%c : %c\n", 0);
//     //  printf("%d\n",printf   ("printf    %%c : %c\n", 0));
//     //  ft_printf("%d\n",ft_printf   ("printf    %%c : %c\n", 0));
// //     printf   ("printf    %%d : %d\n", 745);
// //     ft_printf("ft_printf %%d : %d\n", 745);
// //     printf   ("printf    %%s : %s\n", NULL);
// //     ft_printf("ft_printf %%s : %s\n", NULL);
// //     printf   ("printf    %%X : %X\n", 967);
// //     ft_printf("ft_printf %%X : %X\n", 967);
// //     printf   ("printf    %%u : %u\n", -12);
// //     ft_printf("ft_printf %%u : %u\n", -12);
// //     printf   ("printf    %%i : %i\n", -12);
// //     ft_printf("ft_printf %%i : %i\n", -12);
//  printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//  printf("\n");
//  ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);


//     // printf   ("printf    %%x : %x\n", 14);
//     // ft_printf("ft_printf %%x : %x\n", 14);
// 	//printf ("'x' %% 14 = %d\n'X' %% 14 = %d\n",('x' % 14), ('X' % 14));

// //     //ft_printf("ft_printf %%p : %p\n",&u);
// //     //ft_printf("ceci est un test avec : %c et %y\n\n",'1');
//  }
