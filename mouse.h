#ifndef MOUSE_H
#define MOUSE_H
#include "lines_points_draw.h"
#include "players.h"

#define MAX_SPLINE_POINTS_BLACK_WHITE 350


class Button;
class Players;



class Mouse {

	public:
		Mouse(int selected_point_, int previous_point_, int radius_fallow_point_, bool starting_fallow_black_, Players& players_ref_,
			  Button& button_ref_);

			  
	void Print();
	void DrawLinePointToPoint();
	void CallMouseFunctions();

	int radius;
	int selected_point;
	bool turn_on_undo_button;
	bool lock_button_undo;
	bool reset_state_end_mouse;

	int counter;

	int n_selected_default;
	bool default_points;

	int n_selected_left;
	bool last_points_left;

	int n_selected_right;
	bool last_points_right;

	int n_selected_top;
	bool last_points_top;

	int n_selected_bottom;
	bool last_points_bottom;

	int n_selected_left_top;
	bool last_point_left_top;

	int n_selected_right_top;
	bool last_point_right_top;

	int n_selected_left_bottom;
	bool last_point_left_bottom;
	
	int n_selected_right_bottom;
	bool last_point_right_bottom;

	bool last_points_exit;
	
	
	private:
	
		void InitializePosArray();
		int FindIOfArray();
		bool CalculateRange();
		bool CheckOutOfRangeArray();
		int DisplayLastMoves();
		void FallowPoint();
		void Undo();
		void InsertVectorUndo();
		void SidePoints();
		void SideLastPointsSet();
		void ResetInitialize(bool reset_state);
		void InitializeArrays();
		void InitilizeConditionsArrays();


		float  x, y, x_vector, y_vector, x_vector_last_points_left, y_vector_last_points_left, 
			x_vector_last_points_right, y_vector_last_points_right, x_vector_last_points_top, y_vector_last_points_top, 
			x_vector_last_points_bottom, y_vector_last_points_bottom, x_vector_last_point_left_top, y_vector_last_point_left_top,
			x_vector_last_point_right_top, y_vector_last_point_right_top, x_vector_last_point_left_bottom, 
			y_vector_last_point_left_bottom, x_vector_last_point_right_bottom, y_vector_last_point_right_bottom, x_fallow_point, 
			y_fallow_point; 

		

		int previous_point;
		int radius_fallow_point; 
		bool starting_fallow_black; 

		Players& players_ref;
		Button& button_ref;

		int selected_previous_points_array[MAX_SPLINE_POINTS_BLACK_WHITE];	


		int condtitions_array_xy_default_selected_points[65];
		int conditions_array_xy_left_selected_points[9];
		int conditions_array_xy_right_selected_points[9];
		int conditions_array_xy_top_selected_points[4];
		int conditions_array_xy_bottom_selected_points[4];
		int conditions_array_xy_left_top_selected_point[1];
		int conditions_array_xy_right_top_selected_point[1];
		int conditions_array_xy_left_bottom_selected_point[1];
		int conditions_array_xy_right_bottom_selected_point[1];
		int conditions_array_xy_exit_selected_points[10];


		bool player_white_drawn;
		bool player_black_drawn;
		bool check_bounce_state;


		int double_click;
		int old_point;

		int i_last_moves;

		int counter_how_many_white_last_moves;
		int i_offset_white_last_moves;
		int i_offset_white_last_moves_draw;

		int counter_how_many_black_last_moves;
		int i_offset_black_last_moves;
		int i_offset_black_last_moves_draw;

		int i_player_white;
		int i_player_black;
			
		int previous_point_array[2];
		int previous_count;

		int counter_how_many_white;
		int array_counter_white[MAX_SPLINE_POINTS_BLACK_WHITE];
		int i_offset_white;
		int i_offset_white_draw;
	
		int counter_how_many_black;
		int array_counter_black[MAX_SPLINE_POINTS_BLACK_WHITE];
		int i_offset_black;
		int i_offset_black_draw;
	
		int n_previous_default;
		Vector2 insert_xy_vector_previous_point_default;
		Vector2 insert_xy_vector_selected_point_default;

		int n_previous_left;
		Vector2 insert_xy_vector_previous_point_left;
		Vector2 insert_xy_vector_selected_point_left;

		int n_previous_right;
		Vector2 insert_xy_vector_previous_point_right;
		Vector2 insert_xy_vector_selected_point_right;

	
		int n_previous_top; 
		Vector2 insert_xy_vector_previous_top;
		Vector2 insert_xy_vector_selected_top;

		int n_previous_bottom;
		Vector2 insert_xy_vector_previous_bottom;
		Vector2 insert_xy_vector_selected_bottom;


		int n_previous_left_top;
		Vector2 insert_xy_vector_previous_left_top;
		Vector2 insert_xy_vector_selected_left_top;

		int n_previous_right_top;
		Vector2 insert_xy_vector_previous_right_top;
		Vector2 insert_xy_vector_selected_right_top;


		int n_previous_left_bottom;
		Vector2 insert_xy_vector_previous_left_bottom;
		Vector2 insert_xy_vector_selected_left_bottom;

		int n_previous_right_bottom;
		Vector2 insert_xy_vector_previous_right_bottom;
		Vector2 insert_xy_vector_selected_right_bottom;

		int n_exit;

		bool last_points;

		bool set_last_points_left;
		bool set_last_points_right;
		bool set_last_points_top;
		bool set_last_points_bottom;
		bool set_last_point_left_top;
		bool set_last_point_right_top;
		bool set_last_point_left_bottom;
		bool set_last_point_right_bottom;

		


};


#endif