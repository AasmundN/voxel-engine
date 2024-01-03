#include "app.h"
#include "block.h"

#include <SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 60

int main(int argc, char *argv[]) {
  /*
   * Create app instance
   */
  App app = {NULL, NULL, RUNNING, WINDOW_WIDTH, WINDOW_HEIGHT, 10, 0, 0};

  initSDL(&app, WINDOW_WIDTH, WINDOW_HEIGHT);

  /*
   * App loop
   */
  while (app.state == RUNNING) {
    float frameStart = SDL_GetTicks();

    handleEvents(&app);

    app.angleX += 1;
    app.angleY += 2.3;

    clearFrame(&app);

    drawFrame(&app);

    // wait for next frame
    float frameTime = SDL_GetTicks() - frameStart;
    if (1000 / FPS > frameTime) {
      SDL_Delay(1000 / FPS - frameTime);
    }
  }

  cleanup(&app);

  return 0;
}
