#ifndef LINES_POINTS_DRAW_H
#define LINES_POINTS_DRAW_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include "mouse.h"

#define MAX_SPLINE_POINTS      105
#define MAX_SPLINE_POINTS_POS  350

const int screen_width = 800;
const int screen_height = 700;


class Mouse;
class Players;

class Lines {
public:

void DrawLines();

Vector2 left_line_coordinates_start;
Vector2 left_line_coordinates_end;

Vector2 right_line_coordinates_start;
Vector2 right_line_coordinates_end;

Vector2  top_left_short_line_coordinates_start;
Vector2  top_left_short_line_coordinates_end;

Vector2  top_right_short_line_coordinates_start;
Vector2  top_right_short_line_coordinates_end;

Vector2 goal_top_left_line_coordinates_start;
Vector2 goal_top_left_line_coordinates_end;

Vector2 goal_top_right_left_line_coordinates_start;
Vector2 goal_top_right_left_line_coordinates_end;

Vector2 goal_top_line_coordinates_start;
Vector2 goal_top_line_coordinates_end;

Vector2  bottom_left_short_line_coordinates_start;
Vector2  bottom_left_short_line_coordinates_end;

Vector2  bottom_right_short_line_coordinates_start;
Vector2  bottom_right_short_line_coordinates_end;

Vector2 goal_bottom_left_line_coordinates_start;
Vector2 goal_bottom_left_line_coordinates_end;

Vector2 goal_bottom_right_line_coordinates_start;
Vector2 goal_bottom_right_line_coordinates_end;

Vector2 goal_bottom_line_coordinates_start;
Vector2 goal_bottom_line_coordinates_end;

};


typedef struct{

Vector2 position; 
std::vector<Vector2> conditions_array_xy = {{50,50}, {0,50}, {50,0}, {-50,-50}, {0,-50}, {-50,0}, {-50,50}, {50,-50}};
std::vector<Vector2> conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84 = {{50,0}, {50,-50}, {50,50}};
std::vector<Vector2> conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92 = {{-50,0}, {-50,-50}, {-50,50}};
std::vector<Vector2> conditions_array_xy_points_top_4_5_9_10 = {{-50,50}, {0,50}, {50,50}};
std::vector<Vector2> conditions_array_xy_points_bottom_94_95_99_100 = {{-50,-50}, {0,-50}, {50,-50}};
std::vector<Vector2> conditions_array_xy_point_left_top_6 = {{-50,50}, {0,50}, {50,50}, {50,0},{50,-50}};
std::vector<Vector2> conditions_array_xy_point_right_top_8 = {{50,50}, {0,50}, {-50,50}, {-50,0}, {-50,-50}};
std::vector<Vector2> conditions_array_xy_point_left_bottom_96 = {{-50,-50}, {0,-50}, {50,-50}, {50,0},{50,50}};
std::vector<Vector2> conditions_array_xy_point_right_bottom_98 = {{50,-50}, {0,-50}, {-50,-50},{-50,0}, {-50,50}};
std::vector<Vector2> conditions_array_xy_points_exit_0_1_2_3_11_93_101_102_103_104 = {};

}Points;


static Points array_xy[MAX_SPLINE_POINTS] = {
                               {350,50},{400,50},{450,50},
{200,100},{250,100},{300,100},{350,100},{400,100},{450,100},{500,100},{550,100},{600,100},
{200,150},{250,150},{300,150},{350,150},{400,150},{450,150},{500,150},{550,150},{600,150},
{200,200},{250,200},{300,200},{350,200},{400,200},{450,200},{500,200},{550,200},{600,200},
{200,250},{250,250},{300,250},{350,250},{400,250},{450,250},{500,250},{550,250},{600,250},
{200,300},{250,300},{300,300},{350,300},{400,300},{450,300},{500,300},{550,300},{600,300},
{200,350},{250,350},{300,350},{350,350},{400,350},{450,350},{500,350},{550,350},{600,350},
{200,400},{250,400},{300,400},{350,400},{400,400},{450,400},{500,400},{550,400},{600,400},
{200,450},{250,450},{300,450},{350,450},{400,450},{450,450},{500,450},{550,450},{600,450},
{200,500},{250,500},{300,500},{350,500},{400,500},{450,500},{500,500},{550,500},{600,500},
{200,550},{250,550},{300,550},{350,550},{400,550},{450,550},{500,550},{550,550},{600,550},
{200,600},{250,600},{300,600},{350,600},{400,600},{450,600},{500,600},{550,600},{600,600},
                              {350,650},{400,650},{450,650}
};


typedef struct  {

    Vector2 position;
        
    } BallPosition;
        
extern BallPosition pos_array[MAX_SPLINE_POINTS_POS]; 


class DrawPoints {

    public:

        DrawPoints(Mouse& mouse_ref_);

        void Draw ();
        void DrawOnePoint();

        int radius, radius_one_point;

        private:
        Mouse& mouse_ref;
        float x, y, x_one_point, y_one_point;
    
};
    
class Button {

    public:
        Button (bool button_reset_state_, Rectangle button_coordinates_, Mouse& mouse_ref_, Players& players_ref_);

   
        void Print();
        void CallButtonFunctions();
        Font fontTtf;
        bool button_undo_state;
        bool button_reset_state;
        
       
    private:

        void DrawUndoButton();
        void ButtonUndoHover();
        void ButtonUndoClick();
        void DrawText();
        void DrawPlayersRec();
        
        void DrawResetButton();
        void ButtonResetHover();
        void ButtonResetClick();
        void ResetInitialize(bool reset_state);


        Rectangle button_undo_coordinates;
        Mouse& mouse_ref;
        Players& players_ref;

        Vector2 button_undo_text_position;
        Vector2 player_white_text_position;
        Vector2 player_black_text_position;

        bool button_undo_hover;
        bool button_undo_click;

        Rectangle player_rec_coordinates;
        const char* player_white = "Player White win";
        const char* player_black = "Player Black win";
        Vector2 player_win_text_position;

        Rectangle button_reset_coordinates;
        bool button_reset_hover;
        bool button_reset_click;
        Vector2 button_reset_text_position;


};


        


#endif