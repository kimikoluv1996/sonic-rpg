////////////////////
//
// Project Sonic RPG
// author: Joey McMahan
//  Sonic the Hedgehog belongs to
//           SEGA
//
///////////////////////
#include <stdio.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 800        // global window width and height
#define PROJECT_TITLE "SONIC_RPG"      // global project title

bool debug = true;      // should we draw the debug display?
int velocity_y = 0;      // direction to move in the y and
int velocity_x =0;      //  x axes respecively
int move_speed_px = 5;  // # of pixels to move per frame.
float player_x = 10;    //
float player_y = 10;    // player position on the screen along the x or y axes at any given time; 10 by default
float speed = 5;        // speed multiplier

void display_debug(){
  DrawText(TextFormat("vel y: %d", velocity_y), 0, 0, 20, RED);
  DrawText(TextFormat("vel x: %d", velocity_x), 80, 0, 20, RED);
}

void handle_input_y(){
  if(IsKeyDown(KEY_W))
    velocity_y = -1;
  else if(IsKeyDown(KEY_S))
    velocity_y = 1;
  else velocity_y = 0;
}

void handle_input_x(){
  if(IsKeyDown(KEY_A))
    velocity_x = -1;
  else if(IsKeyDown(KEY_D))
    velocity_x = 1;
  else velocity_x = 0;
}

void character_move(){
  player_x += velocity_x * speed;
  player_y += velocity_y * speed;
}

void game(){

  InitWindow(WIDTH, HEIGHT, PROJECT_TITLE);
  SetTargetFPS(60);

  while(!WindowShouldClose()){

    handle_input_y();
    handle_input_x();
    character_move();
    
    BeginDrawing();

    ClearBackground(GREEN);
    DrawRectangle(player_x,player_y,50,50,BLUE);

    if(debug) { display_debug(); }
    
    EndDrawing();
  }

  CloseWindow();
}

//-----MAIN------------
int main(){
  game();
  return 0;
}
