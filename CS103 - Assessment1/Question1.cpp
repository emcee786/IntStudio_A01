#include<iostream>
using namespace std;

// CS103 Assessment 1, Emma Corkery - Question 1.

// enum for user to input position using only a character
enum position {g, m, s, w, d}; 


// soccer struct, containing player info
struct soccer 
{  
    int num;
    float speed;
    int pos;
};


// Converts the int position to a string using a switch statement
string print_position(int pos)  
{   
    switch(pos) 
    {
        case g:
            return "Goalkeeper";
        case m:
            return "Midfielder";
        case s:
            return "Striker";
        case w:
            return "Winger";
        case d:
            return "Defender";
        default:
            return "Invalid";
    }
}


// Sets the player position to an int for switch statement
int set_position(char ch) {  
    if (ch == 'g') 
        { return 0 ;}
    if (ch == 'm') 
        { return 1 ;}
    if (ch == 's') 
        { return 2 ;}
    if (ch == 'w') 
        { return 3 ;}
    if (ch == 'd') 
        { return 4 ;}
    else 
        { cout << "Invalid position entered \n"; return 5;}
}


// Collects soccer player data from the user
// RETURN: Player struct
soccer collect_data() {  
    soccer player;
    char position;
    cout << "Please type player's number: " ;
    cin >> player.num;
    cin.ignore();
    cout << "Please type player's top speed in mph: " ;
    cin >> player.speed;
    cin.ignore();
    cout << "Please type player's position: ";
    cin >> position;
    player.pos = set_position(position); // calls the function to set the player position as an int value
    return player;

}


// Prints player info
void print_player_info (soccer player)  {  
    cout << "\nThe player's number is " << player.num << "\n";
    cout << "They have a top speed of " << player.speed << "mph \n";
    cout << "And their position is " << print_position(player.pos) << "\n\n";
}


int main() {
    soccer player1 = collect_data();
    soccer player2 = collect_data();
    print_player_info(player1);
    print_player_info(player2);
    return 0;
}