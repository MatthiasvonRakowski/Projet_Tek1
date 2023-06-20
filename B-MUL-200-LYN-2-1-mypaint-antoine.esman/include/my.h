/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** MY
*/

#ifndef MY
    #define MY

///////////////
// CONSTANTS //
///////////////
    #define FPS 60

    #define INIT_WIDTH 800
    #define INIT_HEIGHT 800
    #define INIT_POS_X 0
    #define INIT_POS_Y 0
    #define INIT_RESIZE 0, 0
    #define RECTINFO_BASE_X 100
    #define RECTINFO_BASE_Y 100
    #define ROTATION_RECT 45.0
    #define BUTTON_SIZE_X 100
    #define BUTTON_SIZE_Y 50
    #define BUTTON_OUTL_SIZE 5.0
    #define BUTTON_PLACE_X 0
    #define BUTTON_PLACE_Y 0
    #define COLOR_THEME 217, 218, 219
    #define COLOR_BUTTON 109, 108, 107, 255
    #define CHAR_SIZE_BUTTON 18

    /////////////////
    // ASSETS PATH //
    /////////////////
    #define FONT "assets/fonts/upheavtt.ttf"

////////////
// MACROS //
////////////

    #define ABS(x)  x < 0 ? x * -1 : x
    #define SQUARE(x) x * x

    #define PI 3.1415926535

//////////////
// INCLUDES //
//////////////

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>

/////////////
// TYPEDEF //
/////////////

typedef sfVector2f v2f;
typedef sfVector2i v2i;
typedef sfIntRect int_rect;

////////////////
// STRUCTURES //
////////////////

    ////////////////////
    /// button_state ///
    ////////////////////

typedef enum button_state {
    NONE_BUTTON_STATE,
    RELEASED,
    HOVER,
    HOVER_WAIT,
    OPEN,
    PRESSED
} button_state_t;

    //////////////
    /// Button ///
    //////////////

typedef struct button {
    sfRectangleShape *area;
    sfBool (*is_open) (struct button *, sfMouseMoveEvent *);
    sfBool (*is_hover) (struct button *, sfMouseMoveEvent *);
    sfBool (*is_released) (struct button *, sfMouseButtonEvent *);
    sfBool (*is_pressed) (struct button *, sfMouseButtonEvent *);
    void (*action) (void *);
    button_state_t state;
} button_t;

    ////////////
    /// menu ///
    ////////////

typedef struct menu_ele {
    button_t *button;
    struct menu_ele *options;
    struct menu_ele *next;
    sfText *text;
} menu_ele_t;

    ///////////
    /// Key ///
    ///////////

typedef enum keys {
    KEYS_NONE,
    ESCAPE,
    ENTER
} keys_t;

    /////////////
    /// mouse ///
    /////////////

typedef enum mouse {
    MOUSE_NONE,
    MOUSE_LEFT_PRESSED,
    MOUSE_LEFT_RELEASED,
    MOUSE_MIDDLE_PRESSED,
    MOUSE_MIDDLE_RELEASED
} mouse_t;

    /////////////
    /// Event ///
    /////////////

typedef struct event {
    sfEvent event;
    sfVector2i pos;
    sfVector2i resize;
    keys_t key;
    mouse_t mouse_click;
    sfBool is_open;
} event_t;

    ///////////////////
    /// Paint_state ///
    ///////////////////

typedef enum paint_state {
    SELECTION,
    PENCIL_CIRCLE,
    PENCIL_RECT,
    ERASER_CIRCLE,
    ERASER_RECT,
    SHAPE_CIRCLE,
    SHAPE_RECT,
} paint_state_t;

    /////////////
    /// Paint ///
    /////////////

typedef struct paint {
    paint_state_t paint_state;
    sfRenderWindow *window;
    sfIntRect window_rect;
    sfVector2i resize;
    sfVector2i mpos;
    sfVector2i reca;
    sfVector2i recalibrate;
    sfVector2i new_recali;
    sfVector2i prev_mpos;
    sfVector2i anchor_mpos;
    sfRectangleShape *select_box;
    sfRectangleShape *sketch_rect;
    sfCircleShape *sketch_circle;
    sfView *view;
    sfFont *font;
    sfImage *image;
    sfTexture *texture;
    sfSprite *screen;
    sfBool mouse_down;
    sfBool mouse_middle_down;
    menu_ele_t *menu;
    menu_ele_t *sidebar;
    int pencil_size;
    sfColor pencil_color;
    sfBool in_menu;
    event_t evt;
    int test_value;
} paint_t;

///////////////////////
// FUNCTIONS INCLUDE //
///////////////////////

void event_manager(paint_t *p);

event_t init_event(void);
void event_button_released(menu_ele_t *ele, sfMouseButtonEvent but);
int event_button_open(menu_ele_t *ele, sfMouseMoveEvent but);
void event_button_hover(menu_ele_t *ele, sfMouseMoveEvent move);
void event_moving_fct(menu_ele_t *ele, sfMouseButtonEvent button);
void event_sidebar_hover(menu_ele_t *sidebar, sfMouseMoveEvent move);

sfBool is_open_fct (button_t* button, sfMouseMoveEvent *evt);
sfBool is_released_fct (button_t* button, sfMouseButtonEvent *evt);
sfBool is_hover_fct (button_t* button, sfMouseMoveEvent *evt);
sfBool is_pressed_fct(button_t *button, sfMouseButtonEvent *evt);
sfRenderWindow *create_window(int width, int height, char *name);

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcharcat(char *dest, const char c);
int same_colors(sfColor color1, sfColor color2);
int get_distance(sfVector2i prev_pos, sfVector2i pos);
char *my_strcat(char *dest, const char *src);

void draw_pixel(paint_t *p, int x, int y);
void draw_circle(paint_t *p, sfVector2i pos, int radius);
void draw_rect(paint_t *p, sfVector2i pos, v2f size);
void complete_drawn(paint_t *p, sfBool circle);

void eraser_circle(paint_t *p);
void eraser_rect(paint_t *p);
void pencil_rect(paint_t *p);
void pencil_circle(paint_t *p);
void selection(paint_t *p);
void shape_circle(paint_t *p);
void shape_rect(paint_t *p);

void update_manager(paint_t *p);
void update_view(paint_t *p);
void update_buttons(paint_t *p);
void update_edition(paint_t *p);

void init_edition(menu_ele_t *menu);

void init_sketch(paint_t *p);

void init_help(menu_ele_t *menu);
void donate_bt(void *bt);
void help_bt(void *bt);
void about_bt(void *bt);

void init_file(menu_ele_t *menu);
char *new_window(char *msg, sfFont *font);
void new_file_bt(void *bt);
void open_file_bt(void *bt);
void save_file_bt(void *bt);

void init_sidebar(paint_t *p);
menu_ele_t *create_slider(v2f pos);
menu_ele_t *create_menu_ele(void);
void moving_bt(void *ptr);

void draw_options(sfRenderWindow *window, menu_ele_t *ele);
void display_menu(paint_t *p);
void display_sidebar(menu_ele_t *sidebar, sfRenderWindow *window);
void display_manager(paint_t *p);
void display_edition(paint_t *p);

void print_description(void);

sfColor black_and_white(sfColor color);
sfColor colored_black_and_white(sfColor color);

#endif /* !MY */
