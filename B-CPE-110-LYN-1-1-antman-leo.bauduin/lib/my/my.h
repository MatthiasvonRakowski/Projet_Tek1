/*
** EPITECH PROJECT, 2022
** Pool-Day9
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
void my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
int how_many_space(char const *str, int i);
int len_str(char const *str);
int len_word(char const *str, int i);
char *return_word(char const *str, int i, int len_w);
void char_cap(char *str, int i);
void char_lower(char *str, int i);
int is_an_char(char *str, int i);
int my_getchar_nbr(char *str);
void my_put_floatn(double nbr, int n);
int my_stantard_deviation(float v1);
int my_show_word_array(char *const *tab);
void my_str_swap(char *a, char *b);
void my_put_exponent(char c, double nb, int precision);
int my_printf(const char *format, ...);
int my_putnbr_base(int nb, char *str);
int my_nbr_len(int nbr);
void my_put_unint(unsigned int nbr);
void my_round_float(double nb, int p);
int my_printablechar(char c);

#endif
