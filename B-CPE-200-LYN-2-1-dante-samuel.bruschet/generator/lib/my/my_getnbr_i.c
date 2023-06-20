/*
** EPITECH PROJECT, 2023
** my_getnbr_i
** File description:
** getnbr and the moment who stop
*/

int my_strlen(char const *str);
int my_compute_power(int nbr, int power);
int my_str_isnum(char const *str);

int my_getnbr_i(char *str, int *i)
{
    int size = my_strlen(str);
    int nbr = 0;

    for (; my_str_isnum(&str[*i]); (*i)++) {
        nbr += (str[*i] + '0') * my_compute_power(10, *i);
    }
    return nbr;
}
