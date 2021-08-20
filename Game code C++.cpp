

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Player{
        public:
        string hand;
        int hands_won;
        string name;
};
vector<Player> players(2);

void print_winner(int mode);
bool GAME_OVER();

class Game{
        public:
        int mode;
        string hand;
        int hands_won;
        string name;
public:
void game_start(){
    cout << "-------------------------------------------\n";

    int mode=1;
    if (mode == 1){
        cout << "Enter player1 name: ";
        cin >> players[0].name;
     cout << "Enter player2 name: ";
        cin>>players[1].name;
    }
    while (mode == 1){
        while (!GAME_OVER()){
            cout << players[0].name<<" choose rock,paper, or scissor: "<<endl;
            cin >> players[0].hand;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
           cout << players[1].name<<" choose rock,paper, or scissor: "<<endl;
           cin>> players[1].hand;
            cout << players[0].name<<" chose: " << players[0].hand<<endl<<players[1].name<<" chose: " << players[1].hand <<endl; //display each player's choice for the round
            print_winner(1);
            while (players[0].hand == players[1].hand){
                       cout << players[0].name<<" choose rock,paper, or scissor: "<<endl;
                        cin >> players[0].hand;
                        cout << players[1].name<<" choose rock,paper, or scissor: "<<endl;
                         cin>> players[1].hand;
                          cout << players[0].name<<" chose: " << players[0].hand <<endl<<players[1].name<<" chose: " << players[1].hand <<endl; //display each player's choice for the round
                          print_winner(1);
            }
        }
     if (GAME_OVER()){ //display winner
            if (players[0].hands_won == 2){
                cout << "Congratulations, " << players[0].name << " win the game!\n";
                return;
            }
            else
            {
               cout << "Congratulations, " << players[1].name << " win the game!\n";
              return;
            }
        }

    }
}
};
void print_winner(int mode)
{
    if (mode == 1){
        if (players[0].hand == "rock" && players[1].hand == "scissor"){
            cout << players[0].name<<" win!"<<endl;
            players[0].hands_won += 1;
        }else if (players[0].hand == "scissor" && players[1].hand == "paper"){
            cout << players[0].name<<" win!"<<endl;
            players[0].hands_won += 1;
        }else if (players[0].hand == "paper" && players[1].hand == "rock"){
            cout << players[0].name<<" win!"<<endl;
            players[0].hands_won += 1;
        }else if (players[0].hand == players[1].hand){
            cout << "        It's a draw!"<<endl;
        }else{
            cout <<players[1].name<<" wins!"<<endl;
        players[1].hands_won += 1;
        }
    }
}

int main()
{
    Game g;
    cout << "---------------------------------------------------\n";
    cout << "Game Rock, Paper, Scissors.\nTo play, type '1'. \nTo exit, type '2'.\n";
    cout << "---------------------------------------------------\n";
    int choice;
    cin >> choice;
    switch (choice){
        case 1:
            g.game_start();
            break;
        case 2:
            return 0;
        default:
            cout << "You made an invalid choice.Exit game";
            return 0;
    }
    if (GAME_OVER())
    {
        cout << "Would you like to play again? Type y or n  ";
        char input;
        cin >> input;
        if (input == 'y'){
            g.game_start();
        }
        return 0;
    }
}
bool GAME_OVER(){
    if(players[0].hands_won == 2 || players[1].hands_won == 2){
        return true;
    }
    return false;
}


