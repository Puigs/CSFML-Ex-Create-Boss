#include "../include/my.h"

void manage_event(data_t *data)
{
    while (sfRenderWindow_pollEvent(data->screen->window, \
        &data->screen->event)) {
        if (data->screen->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(data->screen->window);
    }
}

int start(data_t *data)
{
    int check = init_data(data);

    while (sfRenderWindow_isOpen(data->screen->window)) {
        //Gestion évènement
        manage_event(data);
        //Modification des valeurs
        hero_movement(data);
        //Print
        sfRenderWindow_clear(data->screen->window, sfBlack);
        sfRenderWindow_drawSprite(data->screen->window, \
        data->map->sprite, NULL);
        print_hero(data->hero, data->screen->window);
        sfRenderWindow_display(data->screen->window);
    }
    return (check);
}