#include "lines_points_draw.h"



void Lines::DrawLines(){

    left_line_coordinates_start = {200, 100}; // left line start
    left_line_coordinates_end = {200, 600};  // left line end

    right_line_coordinates_start = {600, 100};  // right line start
    right_line_coordinates_end = {600, 600};  // right line end

    top_left_short_line_coordinates_start = {200, 100}; // top left short line start
    top_left_short_line_coordinates_end = {350, 100}; // top left short line end

    top_right_short_line_coordinates_start = {450, 100}; //top right short line start
    top_right_short_line_coordinates_end = {600, 100}; //top right short line end

    goal_top_left_line_coordinates_start = {350, 100};  // goal top left line start
    goal_top_left_line_coordinates_end = {350, 50}; // goal top left line end

    goal_top_right_left_line_coordinates_start = {450, 100}; // goal top right line start  
    goal_top_right_left_line_coordinates_end = {450, 50}; // goal top right line stop

    goal_top_line_coordinates_start = {350, 50}; // goal top line start
    goal_top_line_coordinates_end = {450, 50}; // goal top line end

    bottom_left_short_line_coordinates_start = {200, 600}; // bottom left short line start  
    bottom_left_short_line_coordinates_end = {350, 600}; // bottom left short line end
    
    bottom_right_short_line_coordinates_start = {450, 600}; // bottom right short line start
    bottom_right_short_line_coordinates_end = {600, 600}; // bottom right short line end

    goal_bottom_left_line_coordinates_start = {350, 600}; // goal bottom left line start
    goal_bottom_left_line_coordinates_end = {350, 650}; // goal bottom left line end

    goal_bottom_right_line_coordinates_start = {450, 600}; // goal bottom right line start
    goal_bottom_right_line_coordinates_end = {450,650}; // goal bottom right line stop

    goal_bottom_line_coordinates_start = {350, 650}; // goal bottom line start
    goal_bottom_line_coordinates_end = {450, 650}; // goal bottom line stop

    // left line
    DrawLineEx(left_line_coordinates_start, left_line_coordinates_end, 2, WHITE); 
    // right line
    DrawLineEx(right_line_coordinates_start, right_line_coordinates_end, 2, WHITE); 
    // top left short line 
    DrawLineEx( top_left_short_line_coordinates_start, top_left_short_line_coordinates_end, 2, WHITE); 
    // top right short line 
    DrawLineEx( top_right_short_line_coordinates_start, top_right_short_line_coordinates_end, 2, WHITE);
    // goal top left line
    DrawLineEx(goal_top_left_line_coordinates_start, goal_top_left_line_coordinates_end, 2, WHITE); 
    // goal top right line
    DrawLineEx(goal_top_right_left_line_coordinates_start, goal_top_right_left_line_coordinates_end, 2, WHITE); 
    // goal top line
    DrawLineEx(goal_top_line_coordinates_start, goal_top_line_coordinates_end, 2, WHITE); 
    // bottom left short line 
    DrawLineEx( bottom_left_short_line_coordinates_start, bottom_left_short_line_coordinates_end, 2, WHITE); 
    // bottom right short line 
    DrawLineEx( bottom_right_short_line_coordinates_start, bottom_right_short_line_coordinates_end, 2, WHITE);  
    // goal bottom left line
    DrawLineEx(goal_bottom_left_line_coordinates_start, goal_bottom_left_line_coordinates_end, 2, WHITE); 
    // goal bottom right line
    DrawLineEx(goal_bottom_right_line_coordinates_start, goal_bottom_right_line_coordinates_end, 2, WHITE); 
    // goal bottom line
    DrawLineEx(goal_bottom_line_coordinates_start, goal_bottom_line_coordinates_end, 2, WHITE); 

}


BallPosition pos_array[MAX_SPLINE_POINTS_POS]; 


DrawPoints::DrawPoints(Mouse& mouse_ref_): mouse_ref(mouse_ref_) {};


void DrawPoints::Draw(){

    for (int i = 0; i<MAX_SPLINE_POINTS; i++){

        if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9 ||
            i == 10 || i == 11 || i == 12 || i == 20 || i == 21 || i == 29 || i == 30 || i == 38 || i == 39 ||
            i == 47 || i == 48 || i == 56 || i == 57 || i == 65 || i == 66 || i == 74 || i == 75 || i == 83 ||
            i == 84 || i == 92 || i == 93 || i == 94 || i == 95 || i == 96 || i == 98 || i == 99 || i == 100 ||
            i == 101 || i == 102 || i == 103 || i == 104 ){

            x = array_xy[i].position.x; 
            y = array_xy[i].position.y; 

        }

        else{

            x = array_xy[i].position.x; 
            y = array_xy[i].position.y; 
            DrawCircle(x, y, radius, WHITE);

        }
    }
}

void DrawPoints::DrawOnePoint(){
    
    if (mouse_ref.counter == 0){
    x_one_point = array_xy[52].position.x;
    y_one_point = array_xy[52].position.y; 
    DrawCircle(x_one_point, y_one_point, radius_one_point, WHITE);
    }

}



Button::Button(bool button_reset_state_, Rectangle button_coordinates_, Mouse& mouse_ref_, Players& players_ref_): 
                button_reset_state(button_reset_state_), button_undo_coordinates(button_coordinates_),
                mouse_ref(mouse_ref_), players_ref(players_ref_){}


void Button::CallButtonFunctions(){
    DrawUndoButton();
    ButtonUndoHover();
    ButtonUndoClick();
    DrawText();
    DrawPlayersRec();
    ResetInitialize(button_reset_state);

}

void Button::Print(){

}

void Button::ResetInitialize(bool reset_state){

    if  (reset_state == true){

        button_undo_state = false;
        button_undo_hover = false;
        button_undo_click = false;
        button_reset_hover = false;
        button_reset_click = false;

    if (players_ref.reset_state_end_players == true && mouse_ref.reset_state_end_mouse == true){
        button_reset_state = false;
        players_ref.reset_state_end_players = false;
        mouse_ref.reset_state_end_mouse = false;

        }
    }
}

void Button::DrawUndoButton(){

    // Rectangle x top left 650,  y top left 200, width 80,  height 40
    DrawRectangleRec(button_undo_coordinates, (mouse_ref.turn_on_undo_button == true) ? GREEN :LIGHTGRAY);

    if (button_undo_hover)
    DrawRectangleLinesEx(button_undo_coordinates, 3, (button_undo_click == true) ? BLUE : SKYBLUE);

    button_undo_text_position.x = button_undo_coordinates.x + (button_undo_coordinates.width - MeasureTextEx(fontTtf, "Undo", 25, 2).x)/2;
    button_undo_text_position.y = button_undo_coordinates.y + (button_undo_coordinates.height - 25)/2;
    DrawTextEx(fontTtf, "Undo", button_undo_text_position, 25, 2, BLACK);
    
} 


void Button::ButtonUndoHover(){

    if (CheckCollisionPointRec(GetMousePosition(), button_undo_coordinates))
        button_undo_hover = true;
    
    else button_undo_hover = false;

}

void Button::ButtonUndoClick(){


    if (CheckCollisionPointRec(GetMousePosition(), button_undo_coordinates)){
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) && mouse_ref.turn_on_undo_button == true && 
            mouse_ref.lock_button_undo == false){

            button_undo_click = true;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))

                button_undo_state = true;
                   
        } 

        else
            button_undo_click = false;
        }

    else 
        button_undo_click  = false;

        
}

void Button::DrawText(){

    player_white_text_position.x = 350 + (100 - MeasureTextEx(fontTtf, "White", 25, 2).x)/2;
    player_white_text_position.y = 655;
    DrawTextEx(fontTtf, "White", player_white_text_position, 25, 2, WHITE);
    player_black_text_position.x = 350 + (100 - MeasureTextEx(fontTtf, "Black", 25, 2).x)/2;
    player_black_text_position.y = 25;
    DrawTextEx(fontTtf, "Black", player_black_text_position, 25, 2, BLACK);

}


void Button::DrawPlayersRec(){

    if (players_ref.player_win_turn_on_window == true){

        player_rec_coordinates = {0, 200, 200, 100};
        DrawRectangleRec(player_rec_coordinates, LIGHTGRAY);
        player_win_text_position.x = player_rec_coordinates.x + ((player_rec_coordinates.width - MeasureTextEx(fontTtf, (players_ref.which_player_win == true) ? player_white : player_black, 25, 2).x)/2);
        player_win_text_position.y = player_rec_coordinates.y + 10;
        DrawTextEx(fontTtf, (players_ref.which_player_win == true) ? player_white : player_black, player_win_text_position, 25, 2, BLACK);
       
        DrawResetButton();
        ButtonResetHover();
        ButtonResetClick();

        }     
         
    }


void Button::DrawResetButton(){

    button_reset_coordinates = {50, 242.5, 100, 40};
    DrawRectangleRec(button_reset_coordinates, GREEN);

    if (button_reset_hover)
    DrawRectangleLinesEx(button_reset_coordinates, 3, (button_reset_click == true) ? BLUE : SKYBLUE);

    button_reset_text_position.x = button_reset_coordinates.x + (button_reset_coordinates.width - MeasureTextEx(fontTtf, "Reset", 25, 2 ).x)/2;
    button_reset_text_position.y = button_reset_coordinates.y + (button_reset_coordinates.height - 25)/2;
    DrawTextEx(fontTtf, "Reset", button_reset_text_position, 25, 2, BLACK);

}


void Button::ButtonResetHover(){

    if (CheckCollisionPointRec(GetMousePosition(), button_reset_coordinates))
        button_reset_hover = true;
    
    else button_reset_hover = false;

}
    
void Button::ButtonResetClick(){

    if (CheckCollisionPointRec(GetMousePosition(), button_reset_coordinates)){
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            button_reset_click = true;

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        
                button_reset_state = true;
            }
    
            else 
                button_reset_click = false;
        }

        else button_reset_click = false;
    }
}