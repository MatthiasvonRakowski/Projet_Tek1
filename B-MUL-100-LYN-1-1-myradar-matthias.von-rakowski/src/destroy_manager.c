/*
** EPITECH PROJECT, 2022
** destroy_manager
** File description:
** :wq
*/

#include "../include/my.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Window.h>

void destroy_norme(norme_t *norme)
{
    sfClock_destroy(norme->clock);
    sfRenderWindow_destroy(norme->window);
}

void destroy_text(text_t *text)
{
    free(text->str_time_speed);
    free(text->str_timer);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
}

void destroy_manager(data_t *data)
{
    destroy_tower(data->tower);
    destroy_list_plane(data->list_plane);
    destroy_draw(data->draw);
    destroy_norme(&data->norme);
    destroy_text(data->text);
    free(data);
}
