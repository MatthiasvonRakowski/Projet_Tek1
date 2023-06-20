/*
** EPITECH PROJECT, 2022
** evt.event_handler.c
** File description:
** handle evt.events
*/

#include "my.h"

static int key_released(sfKeyCode key_code)
{
    switch (key_code) {
        case (sfKeyEscape): return ESCAPE;
        case (sfKeyEnter): return ENTER;
        default: return KEYS_NONE;
    };
}

static int mouse_pressed(menu_ele_t *slider, sfMouseButtonEvent button)
{
    switch (button.button) {
        case sfMouseLeft: event_moving_fct(slider, button);
            return MOUSE_LEFT_PRESSED;
        case sfMouseMiddle: return MOUSE_MIDDLE_PRESSED;
        default: return MOUSE_NONE;
    };
}

static int mouse_released(menu_ele_t *menu, sfMouseButtonEvent button)
{
    switch (button.button) {
        case sfMouseLeft: event_button_released(menu, button);
            return MOUSE_LEFT_RELEASED;
        case sfMouseMiddle: return MOUSE_MIDDLE_RELEASED;
        default: return MOUSE_NONE;
    };
}

event_t event_manager_secondpart(event_t evt, paint_t *p)
{
    if (evt.event.type == sfEvtMouseButtonReleased) {
        p->sidebar->options->button->state = NONE_BUTTON_STATE;
        evt.mouse_click = mouse_released(p->menu,
            evt.event.mouseButton);
        evt.pos = (v2i) {evt.event.mouseMove.x, evt.event.mouseMove.y};
    }
    if (evt.event.type == sfEvtKeyReleased)
        evt.key = key_released(evt.event.key.code);
    if (evt.event.type == sfEvtResized)
        evt.resize = (v2i) {evt.event.size.width, evt.event.size.height};
    return evt;
}

void event_manager(paint_t *p)
{
    event_t evt = init_event();

    while (sfRenderWindow_pollEvent(p->window, &evt.event)) {
        if (evt.event.type == sfEvtClosed)
            evt.is_open = sfFalse;
        if (evt.event.type == sfEvtMouseMoved) {
            event_button_hover(p->menu, evt.event.mouseMove);
            event_sidebar_hover(p->sidebar, evt.event.mouseMove);
            event_button_open(p->menu, evt.event.mouseMove);
            evt.pos = (v2i) {evt.event.mouseMove.x, evt.event.mouseMove.y};
        }
        if (evt.event.type == sfEvtMouseButtonPressed) {
            evt.pos = (v2i) {evt.event.mouseMove.x, evt.event.mouseMove.y};
            evt.mouse_click = mouse_pressed(p->sidebar,
                evt.event.mouseButton);
        }
        evt = event_manager_secondpart(evt, p);
    }
    p->evt = evt;
}
