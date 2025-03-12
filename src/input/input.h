#ifndef INPUT_H
#define INPUT_H

#include "../include/globals.h"

// Input functions
unsigned char get_key(void);
int dumb_wait(unsigned int delay);
int kbhit(void);

#endif /* INPUT_H */ 