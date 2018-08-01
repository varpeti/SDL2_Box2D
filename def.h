#ifndef _DEF_H_
#define _DEF_H_

#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>

#define uint unsigned int
#define uint32 unsigned long

#define print(str) std::cout << str << "\n";
#define printerror(err) std::cout << "Error "<< __FILE__ << " " << __LINE__ << ": " << err << "\n";
#define printerror2(e1,e2) std::cout << "Error "<< __FILE__ << " " << __LINE__ << ": " << e1 << e2 << "\n";

#define TITLE "SDL Window"
#define XX 640
#define YY 480
#define SDL_WINDOW_FLAGS 0

#endif