#include "players.h"



Players::Players(bool player_white_, bool player_black_, Mouse& mouse_ref_, Button& button_ref_): 
                player_white(player_white_), player_black(player_black_), mouse_ref(mouse_ref_), 
                    button_ref(button_ref_){}



void Players::CallPlayersFunctions(){

        ChangePlayers();
        PlayersWhoWinOutOfMoves();
        PlayersWin();
        ResetInitialize(button_ref.button_reset_state);
      
}


void Players::Print(){
    
}

void Players::ResetInitialize(bool reset_state){

    if (reset_state == true){

       
        reset_state_end_players = false;
        player_white = true;
        player_black = false;

        double_click = 0;
        i_change_players = 0;
        old_point = 0;
        player_win_turn_on_window = false;
        which_player_win = false;

        reset_state_end_players = true;
    }


}


bool Players::CheckBounce(){
        
    // Update 
     mouse_ref.DrawLinePointToPoint();
     

    if ((mouse_ref.default_points == true && mouse_ref.n_selected_default > 0 && mouse_ref.n_selected_default < 7) ||
        (mouse_ref.last_points_left == true && mouse_ref.n_selected_left > 0 && mouse_ref.n_selected_left < 3) ||
        (mouse_ref.last_points_right == true && mouse_ref.n_selected_right > 0 && mouse_ref.n_selected_right < 3) ||
        (mouse_ref.last_points_top == true && mouse_ref.n_selected_top > 0 && mouse_ref.n_selected_top < 3) ||
        (mouse_ref.last_points_bottom == true && mouse_ref.n_selected_bottom > 0 && mouse_ref.n_selected_bottom < 3) ||
        (mouse_ref.last_point_left_top == true && mouse_ref.n_selected_left_top > 0 && mouse_ref.n_selected_left_top < 5) ||
        (mouse_ref.last_point_right_top == true && mouse_ref.n_selected_right_top > 0 && mouse_ref.n_selected_right_top < 5) ||
        (mouse_ref.last_point_left_bottom == true && mouse_ref.n_selected_left_bottom > 0 && mouse_ref.n_selected_left_bottom < 5) ||
        (mouse_ref.last_point_right_bottom == true && mouse_ref.n_selected_right_bottom > 0 && mouse_ref.n_selected_right_bottom < 5))     
       
             return true;

    else 
            return false;
         
        

}
   

int Players::ChangePlayers(){
 
    for (i_change_players = 0 ; i_change_players<MAX_SPLINE_POINTS; i_change_players++){

        if (CheckCollisionPointCircle(GetMousePosition(), array_xy[i_change_players].position, mouse_ref.radius)){
                
            if (i_change_players != old_point)
                double_click = 0 ;

            else if (double_click == 0 && old_point == mouse_ref.selected_point ) 
                double_click = 2;

        if(CheckCollisionPointCircle(GetMousePosition(), array_xy[mouse_ref.selected_point].position, mouse_ref.radius) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                double_click++;
                old_point =  mouse_ref.selected_point;

                if (double_click > 1)
                    double_click = 2;

                 if (double_click == 1){

                if (CheckBounce()){

                    if (player_white == true){

                        player_white = true;
                        player_black = false;   
                    }
                
                else if ( player_black == true ){   
                        player_white = false;
                        player_black = true;
                    }
                }

                else {

                    if (player_white == true){

                        player_white = false;
                        player_black = true;
                    
                        }
                    
                    else if ( player_black == true ){   

                        player_white = true;
                        player_black = false;

                        }              
                    } 
                }
            }

            return i_change_players;  
        }
    }

    return i_change_players; 
}


void Players::PlayersWhoWinOutOfMoves() {

// Function out of moves which_player_win = true player white win 

    if ((player_white == true && mouse_ref.default_points == true && mouse_ref.n_selected_default == 0) ||
        (player_white == true && mouse_ref.last_points_left == true && mouse_ref.n_selected_left == 0) || 
        (player_white == true && mouse_ref.last_points_right == true && mouse_ref.n_selected_right == 0) ||
        (player_white == true && mouse_ref.last_points_top == true && mouse_ref.n_selected_top == 0) ||
        (player_white == true && mouse_ref.last_points_bottom == true && mouse_ref.n_selected_bottom == 0)||
        (player_white == true && (mouse_ref.selected_point == 3 || mouse_ref.selected_point == 11 || 
            mouse_ref.selected_point == 93 || mouse_ref.selected_point == 101))){

            player_win_turn_on_window = true;
            which_player_win = true;
    }

    else if ((player_black == true && mouse_ref.default_points == true && mouse_ref.n_selected_default == 0) ||
             (player_black == true && mouse_ref.last_points_left == true && mouse_ref.n_selected_left == 0) ||
             (player_black == true && mouse_ref.last_points_right == true && mouse_ref.n_selected_right == 0) ||
             (player_black == true && mouse_ref.last_points_top == true && mouse_ref.n_selected_top == 0) ||
             (player_black == true && mouse_ref.last_points_bottom == true && mouse_ref.n_selected_bottom == 0) ||
             (player_black == true && (mouse_ref.selected_point == 3 || mouse_ref.selected_point == 11 || 
                mouse_ref.selected_point == 93 || mouse_ref.selected_point == 101))){

            player_win_turn_on_window = true;
            which_player_win = false;
    }

    else {

            player_win_turn_on_window = false;
            which_player_win = false;

        }
    }


void Players::PlayersWin(){

        if (mouse_ref.selected_point == 0 || mouse_ref.selected_point == 1 || mouse_ref.selected_point == 2){

            which_player_win = true;
            player_win_turn_on_window = true;
         
        }

        
        else if  (mouse_ref.selected_point == 102 || mouse_ref.selected_point == 103 || mouse_ref.selected_point == 104){
            
            which_player_win = false;
            player_win_turn_on_window = true;

        }



}


