#include "include/my.h"

void do_free(data_t *data)
{
    free(data->screen);
    free(data->hero);
    free(data->map);
    free(data->boss);
    free(data);
}

int launch(data_t *data)
{
    int check = 0;

     if (data == NULL) {
        data = malloc(sizeof(data_t));

        if (data == NULL)
            return (84);
        data->screen = malloc(sizeof(screen_t));
        if (data->screen == NULL)
            return (84);
        
        sfVideoMode video_mode = {1920, 1080, 32};
        data->screen->window = sfRenderWindow_create(video_mode, \
        "~", sfClose, NULL);
        sfRenderWindow_setPosition(data->screen->window, (sfVector2i){0, 0});
    } else
        return (84);
    sfRenderWindow_setFramerateLimit(data->screen->window, 50);
    data->a = 1;
    check = start(data);
    if (check == 0)
        do_free(data);
    return (check);
}

int main(void)
{
    int check = launch(NULL);
    if (check != 0)
        return (84);
    return (0);
}