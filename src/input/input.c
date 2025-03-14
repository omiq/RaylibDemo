#include "input.h"
#include "../logic/game_logic.h"
#include "../display/display.h"
#include "../include/notconio.h"
#include <time.h>
#include <raylib.h>

int dumb_wait(unsigned int delay) {

    WaitTime(delay/10000);

    return delay;
}

int kbhit(void) {
    int key;
/**    return IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D) ||
           IsKeyDown(KEY_O) || IsKeyDown(KEY_P) || IsKeyDown(KEY_F) || IsKeyDown(KEY_Q) ||
           IsKeyDown(KEY_ESCAPE);
           **/

    return GetKeyPressed() > 0;
}

unsigned char get_key(void) {

    
    // Check keys;
    if (IsKeyPressed(KEY_W) && player_y > 0) {
        player_y--;
        return 'w';
    }
    if (IsKeyPressed(KEY_A) && player_x > 0) {
        player_x--;
        return 'a';
    }
    if (IsKeyPressed(KEY_S) && player_y < MAP_HEIGHT-HUD_BOTTOM) {
        player_y++;
        return 's';
    }
    if (IsKeyPressed(KEY_D) && player_x < MAP_WIDTH) {
        player_x++;
        return 'd';
    }
    if ((IsKeyPressed(KEY_O)) && sword) {
        draw_momentary_object(player_x-1, player_y, player_x-1, player_y, '<', 150); 
        attack(10, player_x-1, player_y);
        return 'o';
    }
    if ((IsKeyPressed(KEY_P)) && sword) {
        draw_momentary_object(player_x+1, player_y, player_x+1, player_y, '>', 150); 
        attack(10, player_x+1, player_y);
        return 'p';
    }
    
    if (IsKeyPressed(KEY_F) && magic > 5) {
        magic -= 5;
        int fx = player_x + direction_x;
        int fy = player_y + direction_y;  
        char c = get_map(fx, fy);
        
        while ((c == ' ' || c == '.') && magic > 0) {             
            draw_momentary_object(fx, fy, fx, fy, 'O', 200); 
            magic -= 1;
            fx = fx + direction_x;
            fy = fy + direction_y;    
            c = get_map(fx, fy);
        }
        
        attack(10, fx, fy);
        return 'f';
    }
    if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ESCAPE)) {
        in_play = false;
        return 'Q';
    }
    
    return 0;
} 