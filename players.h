#ifndef PLAYERS_H
#define PLAYERS_H

#include "mouse.h"

class Mouse;
class Button;

class Players{

    public:

        Players(bool player_white_, bool player_black_, Mouse& mouse_ref_, Button& button_ref_);

        
        void Print();
        bool CheckBounce();
        void CallPlayersFunctions();
     
        bool player_white;
        bool player_black;

        bool player_win_turn_on_window;
        bool which_player_win;
        bool reset_state_end_players;

     
    private:

        
        int ChangePlayers();
        void PlayersWhoWinOutOfMoves();
        void PlayersWin();
        void ResetInitialize(bool reset_state);

        Mouse& mouse_ref;
        Button& button_ref;
        int double_click;
        int i_change_players;
        int old_point;


};


#endif