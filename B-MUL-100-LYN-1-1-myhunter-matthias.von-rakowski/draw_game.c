/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/draw_game
** File description:
** draw all game sprites
*/

#include "include/my.h"

void draw_dino_fly_moove(sfRenderWindow *window, dino_fly_t *dino)
{
    dino_fly_t *temp = dino;

    while (dino) {
        sfSprite_setTexture(dino->sp, dino->tex, sfTrue);
        sfSprite_setPosition(dino->sp, dino->pos);
        sfSprite_setScale(dino->sp, dino->scale);
        sfSprite_setTextureRect(dino->sp, dino->rec);
        sfRenderWindow_drawSprite(window, dino->sp, NULL);
        dino = dino->next;
    }
    dino = temp;
}

void draw_dino_moove(sfRenderWindow *window, dino_t *dino)
{
    dino_t *temp = dino;

    while (dino) {
        sfSprite_setTexture(dino->sp, dino->tex, sfTrue);
        if (dino->dir.x == -1)
            sfSprite_setScale(dino->sp, dino->dir);
        sfSprite_setPosition(dino->sp, dino->pos);
        sfSprite_setTextureRect(dino->sp, dino->rec);
        sfRenderWindow_drawSprite(window, dino->sp, NULL);
        dino = dino->next;
    }
    dino = temp;
}

void draw_backgrnd(sfRenderWindow *window, backgrnd_t *backgrnd)
{
    sfSprite_setTexture(backgrnd->sp, backgrnd->tex, sfTrue);
    sfSprite_setTextureRect(backgrnd->sp, backgrnd->rec);
    sfSprite_setScale(backgrnd->sp, backgrnd->scale);
    sfRenderWindow_drawSprite(window, backgrnd->sp, NULL);
}

void draw_target(sfRenderWindow *window, target_t *target)
{
    sfSprite_setTexture(target->sp, target->tex, sfTrue);
    target->mouse_pos = sfMouse_getPositionRenderWindow(window);
    target->pos.x = target->mouse_pos.x + 0.0;
    target->pos.y = target->mouse_pos.y + 0.0;
    sfSprite_setScale(target->sp, target->scale);
    sfSprite_setPosition(target->sp, target->pos);
    sfSprite_setOrigin(target->sp, target->cent);
    sfRenderWindow_drawSprite(window, target->sp, NULL);
}
