#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
        unsigned score;
        // Data on all things needed for game to function
} GameData;

// Main game context
typedef struct {
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running;

        // Timing
        Uint32 last_time;
        float delta_time;

        // Game state
        GameData gameData;
        bool redraw;
} GameContext;

bool game_init(GameContext*);
void game_handle_events(GameContext*);
void game_update(GameContext*);
void game_render(GameContext*);
void game_cleanup(GameContext*);

#endif