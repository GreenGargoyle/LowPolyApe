#include "game.h"

#include <core/logger.h>

b8 game_initialise(game* game_inst)
{
    LPADEBUG("game_intialise() called.");
    return TRUE;
}

b8 game_update(game* game_inst, f32 delta_time)
{
    LPADEBUG("game_update() called.");
    return TRUE;
}

b8 game_render(game* game_inst, f32 delta_time)
{
    LPADEBUG("game_render() called.");
    return TRUE;
}

void game_on_resize(game* game_inst, u32 width, u32 height)
{
    LPADEBUG("game_on_resize() called.");
}