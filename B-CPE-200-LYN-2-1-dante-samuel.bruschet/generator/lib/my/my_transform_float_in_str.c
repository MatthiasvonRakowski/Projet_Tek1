/*
** EPITECH PROJECT, 2023
** lib/my_transform_float_in_str
** File description:
** transform a float in str
*/

#include <stdlib.h>

char *my_int_in_str(int nbr);
char *my_strcat(char *dest, char *src);
int my_compute_power(int nbr, int power);

char *my_transform_float_in_str(double db_nbr, int nb_after_comma)
{
    int nbr = db_nbr;
    char *intenger = my_int_in_str(nbr);
    char *temp;
    char *result;

    if (!(nb_after_comma))
        return intenger;
    temp = my_strcat(intenger, ".");
    free(intenger);
    db_nbr -= nbr;
    nbr = db_nbr * my_compute_power(10, nb_after_comma);
    intenger = my_int_in_str(nbr);
    result = my_strcat(temp, intenger);
    free(intenger);
    free(temp);
    return result;
}
