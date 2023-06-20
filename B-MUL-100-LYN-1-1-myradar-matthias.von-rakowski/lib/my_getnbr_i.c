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
    int nbr = 0;

    for (int j = 0; str[*i] <= '9' && str[*i] >= '0'; (*i)++, j++) {
        nbr *= 10;
        nbr += (str[*i] - '0');
    }
    return nbr;
}
