#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "core/lpamemory.h"
#include "game_types.h"

// Externally-defined function to create a game.
extern b8 create_game(game* out_game);

/**
 * The main entry point of the application.
 */
int main(void) 
{
    initialise_memory();

    // Request the game instance from the application.
    game game_inst;
    if (!create_game(&game_inst))
    {
        LPAFATAL("Could not create game.");
        return -1;
    }

    // Ensure the function pointers (from game_types.h) exist.
    if (!game_inst.render || !game_inst.update || !game_inst.initialise || !game_inst.on_resize)
    {
        LPAFATAL("The game's function pointers must be assigned.");
        return -2;
    }

    // Initialise.
    if (!application_create(&game_inst))
    {
        LPAINFO("Application failed to create.");
        return 1;
    }

    // Begin the game loop.
    if(!application_run())
    {
        LPAINFO("Application did not shutdown gracefully.");
        return 2;
    }
    
    shutdown_memory();
    
    return 0;
}