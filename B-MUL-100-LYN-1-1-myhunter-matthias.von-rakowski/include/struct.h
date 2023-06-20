/*
** EPITECH PROJECT, 2022
** struct
** File description:
** first file of structstruct
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#define FRICTION (float) -0.01;

typedef enum state_e {menu, game, end, dead, life} state_t;

typedef struct dino_fly_s {
    state_t state;
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f dir;
    sfVector2f scale;
    sfIntRect rec;
    sfIntRect recsp;
    float death_time;
    float death_fly;
    int indic;
    sfClock *clock_sp;
    sfClock *clock_mvt;
    sfClock *clock_new;
    int rand;
    int accel;
    struct dino_fly_s *next;
} dino_fly_t;

typedef struct dino_s {
    state_t state;
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f dir;
    sfIntRect rec;
    sfIntRect recsp[8];
    sfIntRect dead_recsp[6];
    float death_time;
    int indic;
    sfClock *clock_sp;
    sfClock *clock_mvt;
    sfClock *clock_new;
    int rand;
    int accel;
    struct dino_s *next;
} dino_t;

typedef struct target_s {
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2i mouse_pos;
    sfVector2f scale;
    sfVector2i click;
    sfVector2f cent;
} target_t;

typedef struct backgrnd_s {
    sfSprite *sp;
    sfTexture *tex;
    sfIntRect rec;
    sfVector2f scale;
} backgrnd_t;

typedef struct menu_bckgrnd_s {
    sfSprite *sp;
    sfTexture *tex;
    sfIntRect rec;
    sfVector2f scale;
} menu_bckgrnd_t;

typedef struct menu_buton_s {
    sfSprite *sp;
    sfTexture *tex;
    sfIntRect rec;
    sfVector2f scale;
    sfVector2f pos;
} menu_buton_t;

typedef struct sound_s {
    sfSound *shoot;
    sfSoundBuffer *shoot_buff;
} sound_t;

typedef struct gdata_s {
    state_t game;
    sfClock *clock;
    sfTime time;
    sfView *view;
    sfMusic *music[5];
    dino_t *dino;
    dino_fly_t *dino_fly;
    target_t *target;
    backgrnd_t *backgrnd;
    float point;
    menu_bckgrnd_t *menu_bckgrnd;
    menu_buton_t *menu_buton;
    menu_buton_t *life;
    menu_buton_t *amo;
    sound_t *shoot;
} gdata_t;
