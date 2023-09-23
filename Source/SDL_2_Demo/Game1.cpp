#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LTexture.cpp"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// Method definitions.
bool init();
bool loadMedia();
void close();
void draw();
void update();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Walking animation
const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
LTexture gSpriteSheetTexture;
int frame = 0;

//Starts up SDL and creates window
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

//Loads media
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("images/foo.png", gRenderer))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 64;
		gSpriteClips[0].h = 205;

		gSpriteClips[1].x = 64;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 205;

		gSpriteClips[2].x = 128;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 64;
		gSpriteClips[2].h = 205;

		gSpriteClips[3].x = 192;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 205;
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	//Free loaded images
	gSpriteSheetTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Current animation frame
			//int frame = 0;
			frame = 0;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				////Clear screen
				//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//SDL_RenderClear(gRenderer);

				////Render current frame
				//SDL_Rect* currentClip = &gSpriteClips[frame / 4];
				//gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, gRenderer, currentClip);

				////Update screen
				//SDL_RenderPresent(gRenderer);

				draw();

				////Go to next frame
				//++frame;

				////Cycle animation
				//if (frame / 4 >= WALKING_ANIMATION_FRAMES)
				//{
				//	frame = 0;
				//}

				update();
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

void draw()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Render current frame
	SDL_Rect* currentClip = &gSpriteClips[frame / 4];
	gSpriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, gRenderer, currentClip);

	//Update screen
	SDL_RenderPresent(gRenderer);
}

void update()
{
	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= WALKING_ANIMATION_FRAMES)
	{
		frame = 0;
	}
}
