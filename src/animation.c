#include "../include/my.h"

void my_anime(hero_t *hero)
{
    hero->timer = sfClock_getElapsedTime(hero->clock);
    hero->seconds = hero->timer.microseconds / 1000000.0;

    if (hero->seconds > 0.02) {
        hero->rect.left += 24;
        if (hero->rect.left > (24 * 11))
            hero->rect.left = 0;
        sfClock_restart(hero->clock);
    }
}