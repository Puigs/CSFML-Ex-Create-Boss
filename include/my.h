#ifndef __MY_H__
#define __MY_H__

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Vertex.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
//Si vous voyez ce message c'est que j'ai eu flemme de trier mes includes (sorry not sorry)

typedef struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
} screen_t;

typedef struct boss_s {

} boss_t;

typedef struct map_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} map_t;

typedef struct hero_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime timer;
    float seconds;
    sfClock *clock2;
    sfTime timer2;
    float seconds2;
    int pv;
    int if_attack;
    sfText *text;
    sfFont *fonte;
    sfText *text2;
}hero_t;

typedef struct data_s {
    screen_t *screen;
    hero_t *hero;
    map_t *map;
    boss_t *boss;
} data_t;

//Launch
int start(data_t *data);
int init_data(data_t *data);

//Hero
void create_hero(hero_t *hero);
void print_hero(hero_t *hero, sfRenderWindow *window);

//Hero movement
void hero_movement(data_t *data);
void call_hmovement(data_t *data);

//animation
void my_anime(hero_t *hero);
void make_attack(hero_t *hero);

#endif /* __MY_H__ */
