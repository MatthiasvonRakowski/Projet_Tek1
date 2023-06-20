/*
** EPITECH PROJECT, 2023
** src/init_draw_text
** File description:
** init draw an text
*/

#include "../include/my.h"

void init_sf(draw_t *draw)
{
    sfRectangleShape_setSize(draw->shape_rect, (sfVector2f) {20, 20});
    sfRectangleShape_setOutlineThickness(draw->shape_rect, 1.0);
    sfRectangleShape_setOutlineColor(draw->shape_rect, sfGreen);
    sfRectangleShape_setFillColor(draw->shape_rect, sfTransparent);
    sfCircleShape_setFillColor(draw->shape_circ, sfTransparent);
    sfCircleShape_setOutlineThickness(draw->shape_circ, 1.0);
    sfCircleShape_setOutlineColor(draw->shape_circ, sfBlue);
    sfSprite_setTexture(draw->sp_plane, draw->tex_plane, sfTrue);
    sfSprite_setTexture(draw->sp_bckgrnd, draw->tex_bckgrnd, sfTrue);
    sfSprite_setTexture(draw->sp_tower, draw->tex_tower, sfTrue);
    sfSprite_setScale(draw->sp_plane, (sfVector2f) {0.0701, 0.0746});
    sfSprite_setScale(draw->sp_tower, (sfVector2f) {0.1, 0.1});
}

draw_t *init_draw(void)
{
    draw_t *draw = malloc(sizeof(draw_t));

    draw->hitbox = 0;
    draw->entities = 0;
    draw->sp_plane = sfSprite_create();
    draw->sp_bckgrnd = sfSprite_create();
    draw->sp_tower = sfSprite_create();
    draw->tex_plane = sfTexture_createFromFile("./asset/plane.png", NULL);
    draw->tex_tower = sfTexture_createFromFile("./asset/tower.png", NULL);
    draw->tex_bckgrnd = sfTexture_createFromFile("./asset/bckgrnd.jpg", NULL);
    draw->shape_circ = sfCircleShape_create();
    draw->shape_rect = sfRectangleShape_create();
    init_sf(draw);
    return draw;
}

text_t *init_text(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile("./asset/font.ttf");
    text->text = sfText_create();
    text->str_timer = malloc(sizeof(char));
    text->str_time_speed = malloc(sizeof(char));
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 45);
    sfText_setColor(text->text, sfWhite);
    return text;
}
