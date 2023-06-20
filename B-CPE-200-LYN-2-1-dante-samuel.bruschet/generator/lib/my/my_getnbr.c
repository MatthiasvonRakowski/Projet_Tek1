/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get a number in a char to put it in a int
*/

int my_strlen(char const *str);
int my_compute_power(int nbr, int power);
int my_str_isnum(char const *str);

int my_getnbr(char *str)
{
    int size = my_strlen(str);
    int nbr = 0;

    for (int i = 0; my_str_isnum(&str[i]); i++) {
        nbr += (str[i] + '0') * my_compute_power(10, i);
    }
    return nbr;
}
