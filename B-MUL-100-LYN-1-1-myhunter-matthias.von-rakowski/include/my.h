/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/include/my
** File description:
** my.h
*/

#pragma once
#include "struct.h"

void event_manager(sfRenderWindow *window, gdata_t *data);
void update_manager(gdata_t *gdata);
gdata_t *init_gdata(gdata_t *gdata);
void draw_manager(sfRenderWindow *window, gdata_t *data);
void music_change(sfMusic **music, int chanel);
void destroy(gdata_t *data);

/*------------------------------EVENT_MANAGER------------------------------*/

void event_game(sfEvent event, sfRenderWindow *window, gdata_t *data);
void event_menu(sfRenderWindow *window, gdata_t *data);
void event_resized(gdata_t *data, float width, float height);
void change_amo(gdata_t *data);
void change_life(gdata_t *data, state_t *state);

/*------------------------------INIT_VALUE---------------------------------*/

dino_t *init_dino(dino_t *dino);
dino_fly_t *init_dino_fly(dino_fly_t *dino);
menu_bckgrnd_t *init_menu_backgrnd(menu_bckgrnd_t *backgrnd);
menu_buton_t *init_menu_buton(menu_buton_t *but);
menu_buton_t *init_life(menu_buton_t *life);
menu_buton_t *init_amo(menu_buton_t *amo);

/*------------------------------DRAW_GAME----------------------------------*/

void draw_target(sfRenderWindow *window, target_t *target);
void draw_backgrnd(sfRenderWindow *window, backgrnd_t *backgrnd);
void draw_dino_moove(sfRenderWindow *window, dino_t *dino);
void draw_dino_fly_moove(sfRenderWindow *window, dino_fly_t *dino);
void draw_menu_backgrnd(sfRenderWindow *window, menu_bckgrnd_t *bckgrnd);
void draw_menu_buton(sfRenderWindow *window, menu_buton_t *but);
void draw_life(sfRenderWindow *window, gdata_t *data);

/*------------------------------UPDATE_GAME---------------------------------*/

void dino_manager(gdata_t *data, void *temp);
dino_fly_t *create_dino_fly(dino_fly_t *dino);
void dino_fly_manager(gdata_t *data, void *temp);
dino_t *create_dino(dino_t *dino);
void move_dino (gdata_t *data);
void move_dino_fly (dino_fly_t *dino, gdata_t *data);

/*-------------------------------FREE---------------------------------------*/
void delete_dino(dino_t *dino);
void delete_dino_fly(dino_fly_t *dino);
