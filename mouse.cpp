#include"Mouse.h"



 Mouse::Mouse(int selected_point_, int previous_point_, int radius_fallow_point_, bool starting_fallow_black_, Players& players_ref_,
              Button& button_ref_): selected_point(selected_point_), previous_point(previous_point_),
            radius_fallow_point(radius_fallow_point_), starting_fallow_black(starting_fallow_black_), players_ref(players_ref_), 
            button_ref(button_ref_), selected_previous_points_array{52}, previous_point_array{52,52} {

}


void Mouse::InitializePosArray() {

    for(int i = 2; i<MAX_SPLINE_POINTS_POS; i++){
        pos_array[0].position = array_xy[previous_point].position;
        pos_array[1].position = array_xy[selected_point].position;
        pos_array[i].position = {(Vector2){0, 0}};

          
    }

}

void Mouse::CallMouseFunctions(){

    DisplayLastMoves();
    FallowPoint();
    Undo();
    SidePoints();
    SideLastPointsSet();
    ResetInitialize(button_ref.button_reset_state);

}


void Mouse::Print(){

    std::cout << selected_point << "  ";  
    std::cout << previous_point << "    "; 

    std::cout << players_ref.player_white << "  ";
    std::cout << players_ref.player_black << "   ";

    std::cout << "cnt" << "  ";
    std::cout << counter << "  ", std::cout << '\n';

}       



void Mouse::ResetInitialize(bool reset_state){

    if  (reset_state == true){

        reset_state_end_mouse = false;
       
        selected_point = 52;
        previous_point = 52;

        InitializePosArray();
        InitializeArrays();
        InitilizeConditionsArrays();
      

        turn_on_undo_button = false;
        lock_button_undo = false;

        n_selected_default = 0;
        default_points = false;
        n_selected_left = 0;
        last_points_left = false;
        n_selected_right = 0;
        last_points_right = false;
        n_selected_top = 0;
        last_points_top = false;
        n_selected_bottom = 0;
        last_points_bottom = false;
        n_selected_left_top = 0;
        last_point_left_top = false;
        n_selected_right_top = 0;
        last_point_right_top = false;
        n_selected_left_bottom = 0;
        last_point_left_bottom = false;
        n_selected_right_bottom = 0;
        last_point_right_bottom = false;
        last_points_exit = false;

        x = 0, y = 0, x_vector = 0, y_vector = 0, x_vector_last_points_left = 0, y_vector_last_points_left = 0, 
        x_vector_last_points_right = 0, y_vector_last_points_right = 0, x_vector_last_points_top = 0, y_vector_last_points_top = 0, 
        x_vector_last_points_bottom = 0, y_vector_last_points_bottom = 0, x_vector_last_point_left_top = 0, y_vector_last_point_left_top = 0,
        x_vector_last_point_right_top = 0, y_vector_last_point_right_top = 0, x_vector_last_point_left_bottom = 0, 
        y_vector_last_point_left_bottom = 0, x_vector_last_point_right_bottom = 0, y_vector_last_point_right_bottom = 0, x_fallow_point = 0, 
        y_fallow_point = 0; 

       
        radius_fallow_point = 3; 
        starting_fallow_black = true; 
        player_white_drawn = false;
		player_black_drawn = false;
        double_click = 0;
		old_point = 0;
        i_last_moves = 0;
        
        counter_how_many_white_last_moves = 0;
        i_offset_white_last_moves = 0;
        i_offset_white_last_moves_draw = 0;

        counter_how_many_black_last_moves = 0;
        i_offset_black_last_moves = 0;
        i_offset_black_last_moves_draw = 0;

        previous_count = 0;
        counter = 0;

        counter_how_many_white = 0;
        i_offset_white = 0;
        i_offset_white_draw = 0;
        counter_how_many_black = 0;
        i_offset_black = 0;
        i_offset_black_draw = 0;

        n_previous_default = 0;
        insert_xy_vector_previous_point_default = {0,0};
        insert_xy_vector_selected_point_default = {0,0};

        n_previous_left = 0;
        insert_xy_vector_previous_point_left = {0,0};
        insert_xy_vector_selected_point_left = {0,0};

		n_previous_right = 0;
        insert_xy_vector_previous_point_right = {0,0};
        insert_xy_vector_selected_point_right = {0,0};

		n_previous_top = 0; 
        insert_xy_vector_previous_top = {0,0};
        insert_xy_vector_selected_top = {0,0};

        n_previous_bottom = 0;
        insert_xy_vector_previous_bottom = {0,0};
        insert_xy_vector_selected_bottom = {0,0};

        n_previous_left_top = 0;
        insert_xy_vector_previous_left_top = {0,0};
        insert_xy_vector_selected_left_top = {0,0};

        n_previous_right_top = 0;
        insert_xy_vector_previous_right_top = {0,0};
        insert_xy_vector_selected_right_top = {0,0};

        n_previous_left_bottom = 0;
        insert_xy_vector_previous_left_bottom = {0,0};
        insert_xy_vector_selected_left_bottom = {0,0};

        n_previous_right_bottom = 0;
        insert_xy_vector_previous_right_bottom = {0,0};
        insert_xy_vector_selected_right_bottom = {0,0};

        n_exit = 0;
		last_points = false;
		set_last_points_left = false;
		set_last_points_right = false;
		set_last_points_top = false;
		set_last_points_bottom = false;
		set_last_point_left_top = false;
		set_last_point_right_top = false;
		set_last_point_left_bottom = false;
		set_last_point_right_bottom = false;
		last_points_exit = false;

        reset_state_end_mouse = true;

    }

}

void Mouse::InitializeArrays(){

    for (int i = 0; i <= 2; i++){
    previous_point_array[i] = 52;
    }

    for (int i = 1; i <= MAX_SPLINE_POINTS_BLACK_WHITE; i++){
    selected_previous_points_array[0] = 52;
    selected_previous_points_array[i] = 0;
    }
    
 
    for (int i = 0; i <= MAX_SPLINE_POINTS_BLACK_WHITE; i++){
        array_counter_white[i] = 0;
        }
    
    for (int i = 0; i <= MAX_SPLINE_POINTS_BLACK_WHITE; i++){
        array_counter_black[i] = 0;
        }
    
 
       


}



void Mouse::InitilizeConditionsArrays(){

    int  condtitions_array_xy_default_selected_points[65] = {7, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 
                                                            31, 32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46,
                                                            49, 50, 51, 52, 53, 54, 55, 58, 59, 60, 61, 62, 63, 64,
                                                            67, 68, 69, 70, 71, 72, 73, 76, 77, 78, 79, 80, 81, 82,
                                                            85, 86, 87, 88, 89, 90, 91, 97};
                                                            
    int conditions_array_xy_left_selected_points[9] = {12, 21, 30, 39, 48, 57, 66, 75, 84};
    int conditions_array_xy_right_selected_points[9] = {20, 29, 38, 47, 56, 65, 74, 83, 92};
    int conditions_array_xy_top_selected_points[4] = {4, 5, 9, 10};
    int conditions_array_xy_bottom_selected_points[4] = {94, 95, 99, 100};
    int conditions_array_xy_left_top_selected_point[1] = {6};
    int conditions_array_xy_right_top_selected_point[1] = {8};
    int conditions_array_xy_left_bottom_selected_point[1] = {96};
    int conditions_array_xy_right_bottom_selected_point[1] = {98};
    int conditions_array_xy_exit_selected_points[10] = {0, 1, 2, 3, 11, 93, 101, 102, 103, 104};                                                                            


    for (int i = 0; i < 65; i++){
        array_xy[condtitions_array_xy_default_selected_points[i]].conditions_array_xy = {{50,50}, {0,50}, {50,0}, {-50,-50}, {0,-50}, {-50,0}, {-50,50}, {50,-50}};

    }

    for (int i = 0; i < 9; i++){
        array_xy[conditions_array_xy_left_selected_points[i]].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84 = {{50,0}, {50,-50}, {50,50}};
    }

    for (int i = 0; i < 9; i++){
        array_xy[conditions_array_xy_right_selected_points[i]].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92 = {{-50,0}, {-50,-50}, {-50,50}};
    }

    for (int i = 0; i < 4; i++){
        array_xy[conditions_array_xy_top_selected_points[i]].conditions_array_xy_points_top_4_5_9_10 = {{-50,50}, {0,50}, {50,50}};
    }

    for (int i = 0; i < 4; i++){
        array_xy[conditions_array_xy_bottom_selected_points[i]].conditions_array_xy_points_bottom_94_95_99_100 = {{-50,-50}, {0,-50}, {50,-50}};
    }

    array_xy[conditions_array_xy_left_top_selected_point[0]].conditions_array_xy_point_left_top_6 = {{-50,50}, {0,50}, {50,50}, {50,0},{50,-50}};

    array_xy[conditions_array_xy_right_top_selected_point[0]].conditions_array_xy_point_right_top_8 = {{50,50}, {0,50}, {-50,50}, {-50,0}, {-50,-50}};

    array_xy[conditions_array_xy_left_bottom_selected_point[0]].conditions_array_xy_point_left_bottom_96 = {{-50,-50}, {0,-50}, {50,-50}, {50,0},{50,50}};

    array_xy[conditions_array_xy_right_bottom_selected_point[0]].conditions_array_xy_point_right_bottom_98 = {{50,-50}, {0,-50}, {-50,-50},{-50,0}, {-50,50}};

    for (int i = 0; i < 10; i++){
        array_xy[conditions_array_xy_exit_selected_points[i]].conditions_array_xy_points_exit_0_1_2_3_11_93_101_102_103_104 = {};
    }

}




void Mouse::DrawLinePointToPoint(){

    CalculateRange();
    FindIOfArray();
   

    if (CheckOutOfRangeArray()){

        return;
    }

    else{

    for (i_player_white = 0; i_player_white < counter_how_many_white; i_player_white++){
        
            if (i_player_white == 0)
            i_offset_white_draw = 0;
         
            else i_offset_white_draw += 2;
    
                DrawLineV(pos_array[array_counter_white[i_offset_white_draw]].position, pos_array[array_counter_white[i_offset_white_draw+1]].position, WHITE);
            
        }

    for (i_player_black = 0; i_player_black < counter_how_many_black; i_player_black++){

            if (i_player_black == 0)
                i_offset_black_draw = 0;
           
            else i_offset_black_draw += 2;
            
                DrawLineV(pos_array[array_counter_black[i_offset_black_draw]].position, pos_array[array_counter_black[i_offset_black_draw+1]].position, BLACK);
        }
        
        
    for (int i = 0 ; i < counter_how_many_white_last_moves; i++){
            
            if (i == 0)
                 i_offset_white_last_moves_draw = i_offset_white_last_moves;

            else i_offset_white_last_moves_draw -= 2;

                DrawLineEx(pos_array[array_counter_white[i_offset_white_last_moves_draw]].position, pos_array[array_counter_white[i_offset_white_last_moves_draw+1]].position, 3, WHITE);

        }

    for (int i = 0; i < counter_how_many_black_last_moves; i++){
    
            if (i == 0)
                i_offset_black_last_moves_draw = i_offset_black_last_moves;

            else i_offset_black_last_moves_draw -= 2;
    
                DrawLineEx(pos_array[array_counter_black[i_offset_black_last_moves_draw]].position, pos_array[array_counter_black[i_offset_black_last_moves_draw+1]].position, 3, BLACK);
      
            }
        }
    }   


bool Mouse:: CheckOutOfRangeArray(){

    //pos_array[array_counter_white[i_offset_white]]
    if ((array_counter_white[i_offset_white]) >= MAX_SPLINE_POINTS_POS){
        std::cout <<  "Out of range pos array, array counter white", std::cout <<'\n';
        return true;
    }

    //pos_array[array_counter_black[i_offset_black]]
    else if ((array_counter_black[i_offset_black]) >= MAX_SPLINE_POINTS_POS){
        std::cout << "Out of range  pos array, array counter black", std::cout <<'\n';
        return true;
    }

     //pos_array[array_counter_white[i_offset_white_draw]]
    else if ((array_counter_white[i_offset_white_draw]) >= MAX_SPLINE_POINTS_POS){
        std::cout <<  "Out of range pos array, array counter white draw ", std::cout <<'\n';
        return true;
    }

    //pos_array[array_counter_black[i_offset_black_draw]]
    else if ((array_counter_black[i_offset_white_draw]) >= MAX_SPLINE_POINTS_POS){
        std::cout << "Out of range  pos array, array counter black draw", std::cout <<'\n';
        return true;
    }

    //(array_counter_white[i_offset_white]
    else if (i_offset_white >= MAX_SPLINE_POINTS_BLACK_WHITE){
          std::cout << "Out of range array counter white, offset white ", std::cout <<'\n';
        return true;
    } 

    //array_counter_black[i_offset_black]
    else if (i_offset_black >= MAX_SPLINE_POINTS_BLACK_WHITE){
        std::cout <<  "Out of range array counter black, offset black", std::cout <<'\n';
        return true;
    }

    //(array_counter_white[i_offset_white_draw]
    else if (i_offset_white_draw>= MAX_SPLINE_POINTS_BLACK_WHITE){
        std::cout << "Out of range array counter white, offset white draw ", std::cout <<'\n';
      return true;
    } 

    //array_counter_black[i_offset_black_draw]
    else if (i_offset_black_draw >= MAX_SPLINE_POINTS_BLACK_WHITE){
        std::cout <<  "Out of range array counter black, offset black draw", std::cout <<'\n';
        return true;
    }

    //selected_previous_points_array_cout[counter]
    else if (counter >= MAX_SPLINE_POINTS_BLACK_WHITE){
        std::cout <<  "Out of range selected previous array", std::cout <<'\n';
        return true;
    }


    return false;

}


void Mouse::FallowPoint(){


    if (players_ref.player_white == false)
        player_white_drawn = true;

    else if (players_ref.player_white == true)
        player_white_drawn = false;


    if (players_ref.player_black == false)
        player_black_drawn = true;

    else if(players_ref.player_black == true)
        player_black_drawn = false;


    if (counter == 1)
    starting_fallow_black = false;

    check_bounce_state = players_ref.CheckBounce();
    
    x_fallow_point = array_xy[selected_point].position.x;
    y_fallow_point = array_xy[selected_point].position.y;

    if ((player_white_drawn == true && check_bounce_state == false) || 
        (players_ref.player_white == true && player_white_drawn == false && check_bounce_state == true ))

        DrawCircle(x_fallow_point, y_fallow_point, radius_fallow_point, WHITE);

    if ((starting_fallow_black == false && player_black_drawn == true && check_bounce_state == false) || 
        (players_ref.player_black == true && player_black_drawn == false && check_bounce_state == true ))

        DrawCircle(x_fallow_point, y_fallow_point, radius_fallow_point, BLACK);

}



int Mouse::DisplayLastMoves(){

    for (i_last_moves = 0 ; i_last_moves<MAX_SPLINE_POINTS; i_last_moves++){

        if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i_last_moves].position, radius)){
                
            if (i_last_moves != old_point)
                double_click = 0 ;

            else if (double_click == 0 && old_point == selected_point ) 
                double_click = 2;

        if(CheckCollisionPointCircle(GetMousePosition(), array_xy[selected_point].position, radius) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                double_click++;
                old_point = selected_point;

                if (double_click > 1)
                double_click = 2;

                 if (double_click == 1){

                   if (players_ref.player_white == true){
                      
                        counter_how_many_white_last_moves++;
                        counter_how_many_black_last_moves = 0;

                        if (counter == 1)
                        i_offset_white_last_moves = 0;

                        else 
                        i_offset_white_last_moves += 2;

                    }     

                    if (players_ref.player_black == true){

                        counter_how_many_black_last_moves++;
                        counter_how_many_white_last_moves = 0;

                        if (counter == 2)
                        i_offset_black_last_moves = 0;

                        else 
                        i_offset_black_last_moves += 2;

                    }      
                }
            }

            return i_last_moves;
        } 
    }

    return i_last_moves;
}



void Mouse::Undo(){

    if (check_bounce_state == true)

        turn_on_undo_button = true;

    else if (check_bounce_state ==false)

        turn_on_undo_button = false;
    
    if (button_ref.button_undo_state == true){

            lock_button_undo = true;

            InsertVectorUndo();
        
        if (players_ref.player_white){

            counter_how_many_white -= 1;
            counter_how_many_white_last_moves -= 1;
            i_offset_white -= 2;
            i_offset_white_draw -= 2;
            i_offset_white_last_moves -= 2;
            i_offset_white_last_moves_draw -= 2;
            
            counter -= 1;
            selected_point = selected_previous_points_array[counter];
            previous_point = selected_previous_points_array[counter-1];
            previous_point_array[0] = selected_point;
            previous_point_array[1] = selected_point;
            old_point = selected_point;
            double_click = 0;
            selected_previous_points_array[counter+1] = 0;
            pos_array[counter+2].position.x = 0;
            pos_array[counter+2].position.y = 0;
        }

        else if (players_ref.player_black){

            counter_how_many_black -= 1;
            counter_how_many_black_last_moves -= 1;
            i_offset_black -= 2;
            i_offset_black_draw -= 2;
            i_offset_black_last_moves -= 2;
            i_offset_black_last_moves_draw -= 2;
            
            counter -= 1;
            selected_point = selected_previous_points_array[counter];
            previous_point = selected_previous_points_array[counter-1];
            previous_point_array[0] = selected_point;
            previous_point_array[1] = selected_point;
            old_point = selected_point;
            double_click = 0;
            selected_previous_points_array[counter+1] = 0;
            pos_array[counter+2].position.x = 0;
            pos_array[counter+2].position.y = 0;
        }

            lock_button_undo = false;
            button_ref.button_undo_state =false;

    }

}


void Mouse::InsertVectorUndo(){

    // Undo for default points, all expected some cases
    insert_xy_vector_previous_point_default = {x_vector, y_vector};  
    array_xy[previous_point].conditions_array_xy.push_back(insert_xy_vector_previous_point_default);

    insert_xy_vector_selected_point_default = {-x_vector, -y_vector};  
    array_xy[selected_point].conditions_array_xy.push_back(insert_xy_vector_selected_point_default);
   

    // Undo for left side points
    insert_xy_vector_previous_point_left = {x_vector_last_points_left, y_vector_last_points_left};
    array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.push_back(insert_xy_vector_previous_point_left);
    
    insert_xy_vector_selected_point_left = {-x_vector_last_points_left, -y_vector_last_points_left};
    array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.push_back(insert_xy_vector_selected_point_left);


    // Undo for right side points
    insert_xy_vector_previous_point_right = {x_vector_last_points_right, y_vector_last_points_right};
    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.push_back(insert_xy_vector_previous_point_right);
  
    insert_xy_vector_selected_point_right = {-x_vector_last_points_right, -y_vector_last_points_right};
    array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.push_back(insert_xy_vector_selected_point_right);  
        

    // Undo for top side points
    insert_xy_vector_previous_top  = {x_vector_last_points_top, y_vector_last_points_top};
    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.push_back(insert_xy_vector_previous_top);
    
    insert_xy_vector_selected_top = { -x_vector_last_points_top, -y_vector_last_points_top};
    array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10.push_back(insert_xy_vector_selected_top);


    // Undo for bottm side point
    insert_xy_vector_previous_bottom = {x_vector_last_points_bottom, y_vector_last_points_bottom};
    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.push_back(insert_xy_vector_previous_bottom);

    insert_xy_vector_selected_bottom = {-x_vector_last_points_bottom, -y_vector_last_points_bottom};
    array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100.push_back(insert_xy_vector_selected_bottom);

    // Undo for left top point
    insert_xy_vector_previous_left_top = {x_vector_last_point_left_top, y_vector_last_point_left_top};
    array_xy[previous_point].conditions_array_xy_point_left_top_6.push_back(insert_xy_vector_previous_left_top);

    insert_xy_vector_selected_left_top = {-x_vector_last_point_left_top, -y_vector_last_point_left_top};
    array_xy[selected_point].conditions_array_xy_point_left_top_6.push_back(insert_xy_vector_selected_left_top);

    //Undo for righ top point
    insert_xy_vector_previous_right_top = {x_vector_last_point_right_top, y_vector_last_point_right_top};
    array_xy[previous_point].conditions_array_xy_point_right_top_8.push_back(insert_xy_vector_previous_right_top);

    insert_xy_vector_selected_right_top = {-x_vector_last_point_right_top, -y_vector_last_point_right_top};
    array_xy[selected_point].conditions_array_xy_point_right_top_8.push_back(insert_xy_vector_selected_right_top);

    //Undo for left bottom point
    insert_xy_vector_previous_left_bottom = {x_vector_last_point_left_bottom, y_vector_last_point_left_bottom};
    array_xy[previous_point].conditions_array_xy_point_left_bottom_96.push_back(insert_xy_vector_previous_left_bottom);

    insert_xy_vector_selected_left_bottom = {-x_vector_last_point_left_bottom, -y_vector_last_point_left_bottom};
    array_xy[selected_point].conditions_array_xy_point_left_bottom_96.push_back(insert_xy_vector_selected_left_bottom);
    
     //Undo for right bottom point
    insert_xy_vector_previous_right_bottom = {x_vector_last_point_right_bottom, y_vector_last_point_right_bottom};
    array_xy[previous_point].conditions_array_xy_point_right_bottom_98.push_back(insert_xy_vector_previous_right_bottom);

    insert_xy_vector_selected_right_bottom = {-x_vector_last_point_right_bottom, -y_vector_last_point_right_bottom};
    array_xy[selected_point].conditions_array_xy_point_right_bottom_98.push_back(insert_xy_vector_selected_right_bottom);

}   



void Mouse::SidePoints(){

        // Points 12_21_30_39_48_57_66_75_84 , last_points_left
        if (selected_point == 12 || selected_point == 21 || selected_point == 30 || selected_point == 39
            || selected_point == 48 || selected_point == 57 || selected_point == 66 || selected_point == 75
            || selected_point == 84){

                last_points = true;
                last_points_left = true;

                last_points_top = false;
                last_points_bottom = false;
                default_points = false;
             }
       
         // Points 20_29_38_47_56_65_74_83_92, last_points_right  
        else if (selected_point == 20 || selected_point == 29 || selected_point == 38 || selected_point == 47
            || selected_point == 56 || selected_point == 65 || selected_point == 74 || selected_point == 83
            || selected_point == 92){

                last_points = true;
                last_points_right = true;

                last_points_top = false;
                last_points_bottom = false;
                default_points = false; 
            }

        // Points 4_5_9_10, last_points_top
        else if (selected_point == 4 || selected_point ==5 || selected_point == 9 || selected_point == 10){

                last_points = true;
                last_points_top = true;

                last_points_left = false;
                last_points_right = false;
                default_points = false;

        }

        // Points 94_95_99_100, last_points_bottom
        else if (selected_point == 94 || selected_point ==95 || selected_point == 99 || selected_point ==100){

                last_points = true;
                last_points_bottom = true;

                last_points_left = false;
                last_points_right = false;
                default_points = false;
        }

        // Points 6, last_point_left_top
        else if (selected_point == 6){
                last_points = true;
                last_point_left_top = true;
                default_points = false;
        }
                  

        // Points 8, last_point_right_top
        else if (selected_point == 8){
                last_points = true;
                last_point_right_top = true;
                default_points = false;
         }
        

        // Points 96, last_point_left_bottom
        else if (selected_point == 96){
                last_points = true;
                last_point_left_bottom = true;
                default_points = false;
            }


        // Points 98, last_point_right_bottom
        else if (selected_point == 98){
                last_points = true;
                last_point_right_bottom = true;
                default_points = false;
            }


        // Points 0_1_2_3_11_93_101_102_103_104 (0 moves), last_points_exit
         else if (selected_point == 0 || selected_point == 1 || selected_point == 2 || selected_point == 3
                 || selected_point == 11 || selected_point == 93 || selected_point == 101 || selected_point == 102
                 || selected_point == 103 || selected_point == 104){

                last_points = true;
                last_points_exit =true;
                default_points = false;
                last_point_left_top = false;
                last_point_right_top = false;
                last_point_left_bottom = false;
                last_point_right_bottom =false;
                
            }


        else{
                default_points = true;
                last_points = false;
                last_points_left = false;
                last_points_right = false; 
                last_points_top = false;
                last_points_bottom = false;
                last_point_left_top = false; 
                last_point_right_top = false;   
                last_point_left_bottom = false;
                last_point_right_bottom = false;     
                last_points_exit = false;
                
        }
}
    

void Mouse::SideLastPointsSet(){

    // Points 12_21_30_39_48_57_66_75_84 , set_last_points_left
    if (previous_point == 12 || previous_point == 21 || previous_point == 30 || previous_point == 39
        || previous_point == 48 || previous_point == 57 || previous_point == 66 || previous_point == 75
        || previous_point == 84)

            set_last_points_left = true;
                
    else      
            set_last_points_left = false;

    // Points 20_29_38_47_56_65_74_83_92, set_last_points_right
    if (previous_point == 20 || previous_point == 29 || previous_point == 38 || previous_point == 47
        || previous_point == 56 || previous_point == 65 || previous_point == 74 || previous_point == 83
        || previous_point == 92)     

            set_last_points_right = true;

    else 
            set_last_points_right = false;

    // Points 4_5_9_10, set_last_points_top
    if (previous_point == 4 || previous_point ==5 || previous_point == 9 || previous_point == 10)

            set_last_points_top = true;
    
    else    
            set_last_points_top = false;

    // Points 94_95_99_100, set_last_points_bottom
    if (previous_point == 94 || previous_point ==95 || previous_point == 99 || previous_point ==100)
            
            set_last_points_bottom = true;

    else  
            set_last_points_bottom = false;


    // Points 6, set_last_point_left_top   
    if (previous_point == 6)

            set_last_point_left_top = true;

    else    
            set_last_point_left_top = false;

    // Points 8,  set_last_point_right_top
    if (previous_point == 8)

            set_last_point_right_top = true;

    else    
            set_last_point_right_top = false;

    // Points 96, set_last_point_left_bottom
    if (previous_point == 96)
            set_last_point_left_bottom = true;
        
    else 
            set_last_point_left_bottom = false;

    // Points 98, set_last_point_right_bottom
    if (previous_point == 98)
            set_last_point_right_bottom = true;
    
    else 
            set_last_point_right_bottom = false;

}


bool Mouse::CalculateRange(){
           
        // For all points expected specified cases, default points
    if (last_points == false){
    
                x_vector = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_default = array_xy[previous_point].conditions_array_xy.size();
                n_selected_default = array_xy[selected_point].conditions_array_xy.size();
    
        for (int i = 0; i< n_previous_default; i++){
            
                if (array_xy[previous_point].conditions_array_xy[i].x == x_vector && 
                    array_xy[previous_point].conditions_array_xy[i].y == y_vector){
                    
                    array_xy[previous_point].conditions_array_xy.erase(array_xy[previous_point].conditions_array_xy.begin() + i);
                    break;
                
                    }
                }
        
        for (int i = 0; i < n_selected_default; i++){
    
                if (array_xy[selected_point].conditions_array_xy[i].x == -x_vector && 
                    array_xy[selected_point].conditions_array_xy[i].y == -y_vector){
                        
                    array_xy[selected_point].conditions_array_xy.erase(array_xy[selected_point].conditions_array_xy.begin() + i);
                    break;
                    
                    }
                }
                
        for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
            
        for (int l = 0; l<n_selected_default; l++){
           
            if (array_xy[selected_point].conditions_array_xy[l].x == x && 
                array_xy[selected_point].conditions_array_xy[l].y == y){
    
                    if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
                            x = array_xy[i].position.x;
                            y = array_xy[i].position.y;
                        
                            DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                                return true;
                        }

                    }  
                }
            }

        // Update left side vectors here when out of last_points_left == true, for points 12_21_30_39_48_57_66_75_84
        if (set_last_points_left == true){
         
            x_vector_last_points_left = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
            y_vector_last_points_left = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
            n_previous_left = array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.size();
    
        for (int i = 0; i< n_previous_left; i++){
    
            if(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].x == x_vector_last_points_left &&
                array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].y == y_vector_last_points_left){
    
                array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.erase(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.begin() + i);
                break;
                }
            }
        }
        
        // Update right side vectors here when out of last_points_right == true, for points 20_29_38_47_56_65_74_83_92
        if (set_last_points_right == true){
           
               x_vector_last_points_right = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
               y_vector_last_points_right = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
       
               n_previous_right = array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.size();
       
           for (int i = 0; i < n_previous_right; i++){
       
               if(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].x == x_vector_last_points_right &&
                  array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].y == y_vector_last_points_right){
       
                    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.erase(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.begin() + i);
                    break;
                    }
                }   
            }
    
           // Update top side vectors here when out of last_points_top == true, for points 4_5_9_10
           if (set_last_points_top == true){
    
                x_vector_last_points_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_top = array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.size();
    
                for (int i= 0; i< n_previous_top; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].x == x_vector_last_points_top &&
                   array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].y == y_vector_last_points_top){
                    
                    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.erase(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.begin() + i);
                    break;
                    }
                }        
            }
    
        
           // Update bottom side vectors here when out of last_points_bottom == true, for points 94_95_99_100
           if (set_last_points_bottom == true){
    
                x_vector_last_points_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_bottom = array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.size();
    
            for (int i = 0; i<n_previous_bottom; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].x == x_vector_last_points_bottom &&
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].y == y_vector_last_points_bottom){
                    
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.erase(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.begin() + i);
                    break;
                    }
                }
           }
    
    
            // Update left top point vectors here when out of last_points_left_top == true, for point 6
            if (set_last_point_left_top == true){
    
                x_vector_last_point_left_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_point_left_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_left_top = array_xy[previous_point].conditions_array_xy_point_left_top_6.size();
    
            for (int i = 0; i<n_previous_left_top; i++){
    
                if(array_xy[previous_point].conditions_array_xy_point_left_top_6[i].x == x_vector_last_point_left_top &&
                    array_xy[previous_point].conditions_array_xy_point_left_top_6[i].y == y_vector_last_point_left_top){
                    
                    array_xy[previous_point].conditions_array_xy_point_left_top_6.erase(array_xy[previous_point].conditions_array_xy_point_left_top_6.begin() + i);
                    break;
                    }
                }
            }
            
    
            // Update right top point vectors here when out of last_points_right_top == true, for point 8
            if (set_last_point_right_top == true){
    
                x_vector_last_point_right_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_point_right_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_right_top = array_xy[previous_point].conditions_array_xy_point_right_top_8.size();
    
            for (int i = 0; i<n_previous_right_top; i++){
    
                if(array_xy[previous_point].conditions_array_xy_point_right_top_8[i].x == x_vector_last_point_right_top &&
                    array_xy[previous_point].conditions_array_xy_point_right_top_8[i].y == y_vector_last_point_right_top){
                    
                    array_xy[previous_point].conditions_array_xy_point_right_top_8.erase(array_xy[previous_point].conditions_array_xy_point_right_top_8.begin() + i);
                    break;
                    }
                }
            }
    
    
           // Update left bottom point vectors here when out of last_points_left_bottom == true, for point 96
           if (set_last_point_left_bottom == true){
    
            x_vector_last_point_left_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
            y_vector_last_point_left_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
            n_previous_left_bottom = array_xy[previous_point].conditions_array_xy_point_left_bottom_96.size();
    
            for (int i = 0; i<n_previous_left_bottom; i++){
    
                if(array_xy[previous_point].conditions_array_xy_point_left_bottom_96[i].x == x_vector_last_point_left_bottom &&
                    array_xy[previous_point].conditions_array_xy_point_left_bottom_96[i].y == y_vector_last_point_left_bottom){
                    
                    array_xy[previous_point].conditions_array_xy_point_left_bottom_96.erase(array_xy[previous_point].conditions_array_xy_point_left_bottom_96.begin() + i);
                    break;
                    }
                }
            }
    
    
        // Update right bottom point vectors here when out of last_points_right_bottom == true, for point 98
        if (set_last_point_right_bottom == true){
    
            x_vector_last_point_right_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
            y_vector_last_point_right_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
            n_previous_right_bottom = array_xy[previous_point].conditions_array_xy_point_right_bottom_98.size();
    
        for (int i = 0; i<n_previous_right_bottom; i++){
    
            if(array_xy[previous_point].conditions_array_xy_point_right_bottom_98[i].x == x_vector_last_point_right_bottom &&
                array_xy[previous_point].conditions_array_xy_point_right_bottom_98[i].y == y_vector_last_point_right_bottom){
                
                array_xy[previous_point].conditions_array_xy_point_right_bottom_98.erase(array_xy[previous_point].conditions_array_xy_point_right_bottom_98.begin() + i);
                break;

                }
            }
        }  
    }
    
        /////////////////////////////////////////////////////
                //change condition to last points == true
        //////////////////////////////////////////////////
    
    if (last_points == true){
    
        // Left side, points 12_21_30_39_48_57_66_75_84
        if(last_points_left == true){
    
                x_vector_last_points_left = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_left = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
                
                n_selected_left = array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.size();
                
            for (int i = 0; i < n_selected_left; i++){
    
                if (array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].x == -x_vector_last_points_left &&
                    array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].y == -y_vector_last_points_left){
                
                    array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.erase(array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.begin() + i);
                    break;
                    }
                }
            
            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;   
    
            for (int l = 0; l<n_selected_left; l++){
    
                if (array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[l].x == x &&
                    array_xy[selected_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[l].y == y){
    
                        if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                            x = array_xy[i].position.x;
                            y = array_xy[i].position.y;
    
                            DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                            return true;
    
                        }
                    }
                }
            }

            // Update left side vectors from top side here, last_points_top never go false when this move /---
               
                x_vector_last_points_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_top = array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.size();
    
            for (int i = 0; i < n_previous_top; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].x == x_vector_last_points_top &&
                    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].y == y_vector_last_points_top){
                    
                    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.erase(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.begin() + i);
                    break;
                }
            }        
                  
    
            // Update left side vectors from bottm side here, last_points_bottom never go false when this move \---
                x_vector_last_points_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_bottom = array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.size();
    
            for (int i = 0; i<n_previous_bottom; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].x == x_vector_last_points_bottom &&
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].y == y_vector_last_points_bottom){
                    
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.erase(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.begin() + i);
                    break;
                    }
                }
          
            }
        

        // Right side, points 20_29_38_47_56_65_74_83_92   
         if (last_points_right == true){
    
                x_vector_last_points_right = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_right = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_right = array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.size();
                
            for (int i = 0; i < n_selected_right; i++){
                if (array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].x == -x_vector_last_points_right &&
                    array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].y == -y_vector_last_points_right){
                    
                    array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.erase(array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.begin() + i);
                    break;
                    }
                }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
    
            for (int l = 0; l<n_selected_right; l++){
                if (array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[l].x == x &&
                    array_xy[selected_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[l].y == y){
    
                        if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                            x = array_xy[i].position.x;
                            y = array_xy[i].position.y;
                            DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                            return true;
    
                        }
                    }
                }
            }

            // Update right side vectors from top side here, last_points_top never go false when this move ---\'
            
                x_vector_last_points_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_top = array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.size();
    
            for (int i = 0; i < n_previous_top; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].x == x_vector_last_points_top &&
                    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10[i].y == y_vector_last_points_top){
                    
                    array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.erase(array_xy[previous_point].conditions_array_xy_points_top_4_5_9_10.begin() + i);
                    break;
                    }
                }        
              
    
            // Update right side vectors from botto side here, last_points_botomm never go false when this move ---/'
                x_vector_last_points_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_previous_bottom = array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.size();
    
            for (int i = 0; i<n_previous_bottom; i++){
    
                if(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].x == x_vector_last_points_bottom &&
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100[i].y == y_vector_last_points_bottom){
                    
                    array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.erase(array_xy[previous_point].conditions_array_xy_points_bottom_94_95_99_100.begin() + i);
                    break;
                    }
                } 
    
            }
    
    
            // Top side, points 4_5_9_10
            if (last_points_top == true){
    
                x_vector_last_points_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_top = array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10.size();
    
            for (int i = 0; i < n_selected_top; i++){
                    if (array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10[i].x == -x_vector_last_points_top &&
                        array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10[i].y == -y_vector_last_points_top){
                        
                        array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10.erase(array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10.begin() + i); 
                        break;
                    }     
                }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
                
            for (int l = 0; l<n_selected_top; l++){
                if (array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10[l].x == x &&
                    array_xy[selected_point].conditions_array_xy_points_top_4_5_9_10[l].y == y){
    
                    if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
                            
                        x = array_xy[i].position.x;
                        y = array_xy[i].position.y;
                        DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                        return true;
                        }
                     }
                 }
            }
    
            // Update top side vectors from left side here, last_points_top never go false when this move /---
               
                x_vector_last_points_left = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_left = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
        
                n_previous_left = array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.size();
        
            for (int i = 0; i < n_previous_left; i++){
        
                if(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].x == x_vector_last_points_left &&
                    array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].y == y_vector_last_points_left){
        
                    array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.erase(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.begin() + i);
                    break;
                }
            }
             
    
            // Update top side vectors from right side here, last_points_top never go false when this move --\'
            
                x_vector_last_points_right = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_right = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
        
                n_previous_right = array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.size();
        
            for (int i = 0; i < n_previous_right; i++){
        
                if(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].x == x_vector_last_points_right &&
                    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].y == y_vector_last_points_right){
        
                    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.erase(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.begin() + i);
                    break;
                    }
                }
            }
    

            // Bottm side, points 94_95_99_100, last_points_bottom
            if (last_points_bottom == true){
               
                x_vector_last_points_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_bottom = array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100.size();
    
            for (int i = 0; i < n_selected_bottom; i++){
                    if (array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100[i].x == -x_vector_last_points_bottom &&
                        array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100[i].y == -y_vector_last_points_bottom){
    
                          array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100.erase(array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100.begin() + i);
                          break; 
                        }
                    }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
                
            for (int l = 0; l<n_selected_bottom; l++){
                if (array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100[l].x == x &&
                    array_xy[selected_point].conditions_array_xy_points_bottom_94_95_99_100[l].y == y){
    
                    if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                        x = array_xy[i].position.x;
                        y = array_xy[i].position.y;
                        DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                        return true;
                        }
                     }
                 }
            }
    
            // Update  bottm side vectors from left side here, last_points_top never go false when this move \---
                x_vector_last_points_left = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_left = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
        
                n_previous_left = array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.size();
        
            for (int i = 0; i < n_previous_left; i++){
        
                if(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].x == x_vector_last_points_left &&
                    array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84[i].y == y_vector_last_points_left){
        
                    array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.erase(array_xy[previous_point].conditions_array_xy_points_left_12_21_30_39_48_57_66_75_84.begin() + i);
                    break;
                    }
                }
    
    
            // Update bottom side vectors from right side here, last_points_top never go false when this move --/'
                x_vector_last_points_right = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_points_right = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
        
                n_previous_right = array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.size();
        
            for (int i = 0; i < n_previous_right; i++){
        
                if(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].x == x_vector_last_points_right &&
                    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92[i].y == y_vector_last_points_right){
        
                    array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.erase(array_xy[previous_point].conditions_array_xy_points_right_20_29_38_47_56_65_74_83_92.begin() + i);
                    break; 
                    }
                }
            }

    
            // Left top point, point 6 last_point_left_top
             if (last_point_left_top == true){
               
                 x_vector_last_point_left_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                 y_vector_last_point_left_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_left_top = array_xy[selected_point].conditions_array_xy_point_left_top_6.size();
                
    
            for (int i = 0; i < n_selected_left_top; i++){
                    if (array_xy[selected_point].conditions_array_xy_point_left_top_6[i].x == -x_vector_last_point_left_top &&
                        array_xy[selected_point].conditions_array_xy_point_left_top_6[i].y == -y_vector_last_point_left_top){
    
                          array_xy[selected_point].conditions_array_xy_point_left_top_6.erase(array_xy[selected_point].conditions_array_xy_point_left_top_6.begin() + i);
                          break; 
                        }
                    }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
                
            for (int l = 0; l<n_selected_left_top; l++){
                if (array_xy[selected_point].conditions_array_xy_point_left_top_6[l].x == x &&
                    array_xy[selected_point].conditions_array_xy_point_left_top_6[l].y == y){
    
                    if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                        x = array_xy[i].position.x;
                        y = array_xy[i].position.y;
                        DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                        return true;
                        }
                    }
                 }
            }
        }
    
            // Right top point, point 8 last_point_right_top
            if (last_point_right_top == true){
                    
                x_vector_last_point_right_top = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_point_right_top = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
            n_selected_right_top = array_xy[selected_point].conditions_array_xy_point_right_top_8.size();
            
    
            for (int i = 0; i < n_selected_right_top ; i++){
                if (array_xy[selected_point].conditions_array_xy_point_right_top_8[i].x == -x_vector_last_point_right_top &&
                    array_xy[selected_point].conditions_array_xy_point_right_top_8[i].y == -y_vector_last_point_right_top){
    
                        array_xy[selected_point].conditions_array_xy_point_right_top_8.erase(array_xy[selected_point].conditions_array_xy_point_right_top_8.begin() + i); 
                        break;
                    }
                }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
                
            for (int l = 0; l<n_selected_right_top; l++){
            if (array_xy[selected_point].conditions_array_xy_point_right_top_8[l].x == x &&
                array_xy[selected_point].conditions_array_xy_point_right_top_8[l].y == y){
    
                if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                    x = array_xy[i].position.x;
                    y = array_xy[i].position.y;
                    DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                    return true;
                    }
                }
            }
        }        
    }
    
            // Left bottom point, point 96 last_point_left_bottom
            if (last_point_left_bottom == true){
                    
                x_vector_last_point_left_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_point_left_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_left_bottom = array_xy[selected_point].conditions_array_xy_point_left_bottom_96.size();
            
    
            for (int i = 0; i < n_selected_left_bottom ; i++){
                if (array_xy[selected_point].conditions_array_xy_point_left_bottom_96[i].x == -x_vector_last_point_left_bottom &&
                    array_xy[selected_point].conditions_array_xy_point_left_bottom_96[i].y == -y_vector_last_point_left_bottom){
    
                        array_xy[selected_point].conditions_array_xy_point_left_bottom_96.erase(array_xy[selected_point].conditions_array_xy_point_left_bottom_96.begin() + i); 
                        break;
                    }
                }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
            
            for (int l = 0; l<n_selected_left_bottom; l++){
            if (array_xy[selected_point].conditions_array_xy_point_left_bottom_96[l].x == x &&
                array_xy[selected_point].conditions_array_xy_point_left_bottom_96[l].y == y){
    
                if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                    x = array_xy[i].position.x;
                    y = array_xy[i].position.y;
                    DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                    return true;
                    }
                }
            }
        }        
    }   
    
            // Right bottom point, point 98 last_point_right_bottom
            if (last_point_right_bottom == true){
                    
                x_vector_last_point_right_bottom = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector_last_point_right_bottom = array_xy[selected_point].position.y - array_xy[previous_point].position.y;
    
                n_selected_right_bottom = array_xy[selected_point].conditions_array_xy_point_right_bottom_98.size();
            
    
            for (int i = 0; i < n_selected_right_bottom ; i++){
                if (array_xy[selected_point].conditions_array_xy_point_right_bottom_98[i].x == -x_vector_last_point_right_bottom &&
                    array_xy[selected_point].conditions_array_xy_point_right_bottom_98[i].y == -y_vector_last_point_right_bottom){
    
                        array_xy[selected_point].conditions_array_xy_point_right_bottom_98.erase(array_xy[selected_point].conditions_array_xy_point_right_bottom_98.begin() + i); 
                        break;
                    }
                }

            for(int i = 0; i<MAX_SPLINE_POINTS; i++){
                x = array_xy[i].position.x - array_xy[selected_point].position.x;
                y = array_xy[i].position.y - array_xy[selected_point].position.y;
            
            for (int l = 0; l<n_selected_right_bottom; l++){
            if (array_xy[selected_point].conditions_array_xy_point_right_bottom_98[l].x == x &&
                array_xy[selected_point].conditions_array_xy_point_right_bottom_98[l].y == y){
    
                if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius)){
    
                    x = array_xy[i].position.x;
                    y = array_xy[i].position.y;
                    DrawCircle(x, y, radius, (players_ref.player_white ==true) ? WHITE : BLACK);
                    return true;
                        }
                    }
                }
            }   
        }

            // Exit points 0_1_2_3_11_93_101_102_103_104 
            if (last_points_exit == true){
    
            n_exit = array_xy[selected_point].conditions_array_xy_points_exit_0_1_2_3_11_93_101_102_103_104.size();
    
            }
                
    
            // Update default vector for previous points here, when out of last_points == false
            if (last_points_left == true || last_points_right == true || last_points_top == true || last_points_bottom ||
                last_point_left_top == true || last_point_right_top == true || last_point_left_bottom == true ||
                last_point_right_bottom == true){
    
                x_vector = array_xy[selected_point].position.x - array_xy[previous_point].position.x;
                y_vector = array_xy[selected_point].position.y - array_xy[previous_point].position.y; 
    
                n_previous_default = array_xy[previous_point].conditions_array_xy.size();

            for (int i= 0; i < n_previous_default; i++){
    
                if (array_xy[previous_point].conditions_array_xy[i].x == x_vector && 
                    array_xy[previous_point].conditions_array_xy[i].y == y_vector){
                        
                    array_xy[previous_point].conditions_array_xy.erase(array_xy[previous_point].conditions_array_xy.begin() + i);
                    break;
                    }
                }  
            }
        }
            
        return false;   
    }



int Mouse::FindIOfArray(){
 
    if(CalculateRange()){
        
        for (int i=0; i<MAX_SPLINE_POINTS; i++){
             
            if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i].position, radius) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                
                selected_point = i; 
                counter++;
                selected_previous_points_array[counter] = selected_point;

                // Previous point logic
                previous_count++;
                previous_point_array[previous_count] = selected_point;
                previous_point = previous_point_array[previous_count-1];
                previous_point_array[previous_count-1] = previous_point_array[previous_count];     
                  if (previous_count > 0)
                     previous_count = 0;


                if (players_ref.player_white == true){
                    counter_how_many_white++;
                    pos_array[counter+1].position = array_xy[selected_point].position;

                    if (counter_how_many_white == 1)
                        i_offset_white = 0;
                    else 
                        i_offset_white += 2;

                    array_counter_white[i_offset_white] = counter;
                    array_counter_white[i_offset_white+1] = counter+1;
                 
                }
          
                else if (players_ref.player_black == true){
                    counter_how_many_black++;
                    pos_array[counter+1].position = array_xy[selected_point].position;

                    if (counter_how_many_black == 1)
                        i_offset_black = 0;
                    else 
                        i_offset_black += 2;

                    array_counter_black[i_offset_black] = counter;
                    array_counter_black[i_offset_black+1] = counter+1;
                   
                }

                return selected_point;
                     
                }
            }
        }

        return selected_point;
}