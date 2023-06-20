/*
** EPITECH PROJECT, 2022
** init
** File description:
** initialisation of the struct
*/

#include "include/my.h"

target_t *init_target(target_t *target)
{
    target = malloc(sizeof(target_t));
    target->scale.x = 0.1;
    target->scale.y = 0.1;
    target->click.y = 0;
    target->click.x = 0;
    target->cent.x = 250;
    target->cent.y = 250;
    target->sp = sfSprite_create();
    target->tex = sfTexture_createFromFile("./pic/red_target.png", NULL);
    return target;
}

backgrnd_t *init_backgrnd(backgrnd_t *backgrnd)
{
    backgrnd = malloc(sizeof(backgrnd_t));
    backgrnd->rec.top = 0;
    backgrnd->rec.left = 0;
    backgrnd->rec.width = 1600;
    backgrnd->rec.height = 850;
    backgrnd->scale.x = 0.5;
    backgrnd->scale.y = 0.71;
    backgrnd->sp = sfSprite_create();
    backgrnd->tex = sfTexture_createFromFile("./pic/backgrnd.jpg", NULL);
    return backgrnd;
}

sound_t *init_shoot(sound_t *shoot)
{
    shoot = malloc(sizeof(sound_t));
    shoot->shoot = sfSound_create();
    shoot->shoot_buff = sfSoundBuffer_createFromFile("./sound/shoot.ogg");
    sfSound_setBuffer(shoot->shoot, shoot->shoot_buff);
    return shoot;
}

void init_music(sfMusic **music)
{
    music[0] = sfMusic_createFromFile("./sound/menu_music.ogg");
    music[1] = sfMusic_createFromFile("./sound/level_1.ogg");
    music[2] = sfMusic_createFromFile("./sound/dead.ogg");
    music[3] = sfMusic_createFromFile("./sound/dead.ogg");
    sfMusic_play(music[0]);
}

gdata_t *init_gdata(gdata_t *data)
{
    data = malloc(sizeof(gdata_t));
    data->game = menu;
    data->view = sfView_createFromRect((sfFloatRect) {0, 0, 800, 600});
    data->dino = NULL;
    data->dino_fly = NULL;
    data->target = init_target(data->target);
    data->backgrnd = init_backgrnd(data->backgrnd);
    data->menu_bckgrnd = init_menu_backgrnd(data->menu_bckgrnd);
    data->menu_buton = init_menu_buton(data->menu_buton);
    data->shoot = init_shoot(data->shoot);
    init_music(data->music);
    data->life = init_life(data->life);
    data->amo = init_amo(data->amo);
    init_menu_backgrnd(data->menu_bckgrnd);
    data->point = 0;
    return data;
}
