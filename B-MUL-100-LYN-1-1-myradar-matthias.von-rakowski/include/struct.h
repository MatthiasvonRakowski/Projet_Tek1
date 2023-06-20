/*
** EPITECH PROJECT, 2022
** struct
** File description:
** all struct and include
*/

#pragma once

#include <SFML/Graphics/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <fcntl.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>

typedef struct tower_s {
    sfVector2f pos;
    float radius;
    struct tower_s *next;
} tower_t;

typedef struct plane_s {
    sfFloatRect rect;
    int level;
    double angle;
    sfFloatRect box;
    float dist;
    float speed;
    int protect;
    sfVector2f mvt_s;
    int dead;
    int delay;
    struct plane_s *next;
} plane_t;

typedef struct list_plane_s {
    int level;
    sfFloatRect area;
    int nb_plane;
    plane_t *plane;
    struct list_plane_s *inside;
    struct list_plane_s *next;
} list_plane_t;

typedef struct draw_s {
    int hitbox;
    int entities;
    sfTexture *tex_plane;
    sfSprite *sp_plane;
    sfTexture *tex_tower;
    sfSprite *sp_tower;
    sfTexture *tex_bckgrnd;
    sfSprite *sp_bckgrnd;
    sfCircleShape *shape_circ;
    sfRectangleShape *shape_rect;
} draw_t;

typedef struct norme_s {
    sfClock *clock;
    double timer;
    sfEvent event;
    double delta_t;
    int time_speed;
    sfRenderWindow *window;
    sfVideoMode mode;
} norme_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
    char *str_timer;
    char *str_time_speed;
} text_t;

typedef struct grid_s {
    int level;
    int nb_plane;
    sfFloatRect box;
    plane_t *plane;
    struct grid_s *next;
    struct grid_s *inside;
} grid_t;

typedef struct data_s {
    norme_t norme;
    draw_t *draw;
    text_t *text;
    list_plane_t *list_plane;
    tower_t *tower;
    grid_t *grid;
} data_t;
