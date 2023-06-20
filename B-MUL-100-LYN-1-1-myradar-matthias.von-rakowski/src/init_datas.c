/*
** EPITECH PROJECT, 2023
** src/init_datas
** File description:
** second big init
*/

#include "../include/my.h"
#include <SFML/Graphics/Rect.h>

list_plane_t *init_first_list_plane(void)
{
    list_plane_t *element = malloc(sizeof(list_plane_t));

    element->area = (sfFloatRect) {-20, -20, MAP_WIDTH + 40, MAP_WIDTH + 40};
    element->nb_plane = 0;
    element->level = 0;
    element->plane = NULL;
    element->inside = NULL;
    element->next = NULL;
    return element;
}

double find_angle(double dist, int arr[6])
{
    int calc_co = arr[2] - arr[0];
    int calc_si = arr[3] - arr[1];
    double co = acos(calc_co / dist);

    if (calc_si < 0)
        return (- co);
    return co;
}

plane_t *add_plane(char *buff, plane_t *list)
{
    plane_t *element = malloc(sizeof(plane_t));
    int arr_info[6];

    if (!(my_getline_in_array(buff, arr_info, 6)))
        return NULL;
    element->dist = sqrt(pow(arr_info[2] - arr_info[0], 2) + pow(arr_info[3] -
    arr_info[1], 2));
    element->angle = find_angle(element->dist, arr_info) * 180 /
    M_PI;
    element->protect = 1;
    element->speed = arr_info[4];
    element->mvt_s = (sfVector2f) {arr_info[4] * (arr_info[2] - arr_info[0]) /
    element->dist, arr_info[4]  * (arr_info[3] - arr_info[1]) / element->dist};
    element->delay = arr_info[5];
    element->rect = (sfFloatRect) {arr_info[0], arr_info[1], 20, 20};
    element->dead = 0;
    element->next = list;
    return element;
}

list_plane_t *init_plane(char *buff, list_plane_t *list_plane)
{
    list_plane->nb_plane++;
    list_plane->plane = add_plane(buff, list_plane->plane);
    return list_plane;
}

tower_t *init_tower(char *buff, tower_t *tower)
{
    tower_t *element = malloc(sizeof(tower_t));
    int arr_info[3];

    if (!(my_getline_in_array(buff, arr_info, 3)))
        return NULL;
    element->pos = (sfVector2f) {arr_info[0], arr_info[1]};
    element->radius = ((float) arr_info[2]);
    element->next = tower;
    return element;
}
