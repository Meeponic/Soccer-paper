#include "mouse.h"



Color Dark_Green = Color{20,160,133,255};

///////
extern Players players; 
extern Button button;
extern Mouse mouse;
BallPosition pos;
Lines lines;
DrawPoints draw_points(mouse);
Mouse mouse(52, 52, 3, true, players, button);
Players players(true, false, mouse, button);
Button button(true, {650, 200, 80, 40}, mouse, players);



int main () {

    std::cout << "Starting the game ", std::cout << '\n';
    InitWindow(screen_width, screen_height, "Soccer Paper");
    button.fontTtf = LoadFontEx("font/Roboto-SemiBold.ttf", 32, 0, 250);

    SetTargetFPS(60);
    
    draw_points.radius = 2;
    draw_points.radius_one_point = 4;
    mouse.radius = 3;
   
    
    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Green);

        lines.DrawLines();

        draw_points.Draw();
        draw_points.DrawOnePoint();
    
        mouse.Print();
        mouse.DrawLinePointToPoint();
        mouse.CallMouseFunctions();
        
        players.CallPlayersFunctions();
        players.Print();

        button.CallButtonFunctions();
        button.Print();

        EndDrawing();
    }                  

    CloseWindow();
    return 0;
}
