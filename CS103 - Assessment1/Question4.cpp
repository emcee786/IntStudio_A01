#include <iostream>
using namespace std;

// CS103 Assessment 1, Emma Corkery - Question 4.

// struct for state of game play
struct game_state
{
    int guess_count;
    char missing_char;
    bool player_wins;
    bool playing;
    string word;
};

// Displays game intro when called by main()
void print_intro() {
    cout << "\n";
    cout << "Welcome to Hangman! This game tests your spelling ability." << endl;
    cout << "---------------------------------------------------------------" <<endl;
    cout << "\n";
    cout << "        _________ "    << endl;
    cout << "       |         |"    << endl;
    cout << "       |         O"    << endl;
    cout << "       |        \\|/"  << endl;
    cout << "       |         | "   << endl;
    cout << "       |        / \\"  << endl;
    cout << "       | "             << endl;
    cout << "       | "             << endl;
    cout << "     ----- "           << endl;
}

// Takes game state, and prints relevant image for the games end
void print_hangman(game_state state) {

    if (state.player_wins) {                // Player wins
        cout << "\n";
        cout << "Your guess is correct!" << endl;
        cout << "\n";
        cout << "               O"    << endl;
        cout << "              \\|/"  << endl;
        cout << "               | "   << endl;
        cout << "              / \\"  << endl;
    }
    else {                                  //Player loses
        cout << "\n";
        cout << "Your guesses were wrong!"  <<endl;
        cout << "GAME OVER!"            << endl;
        cout << "\n";
        cout << "        _________ "    << endl;
        cout << "       |         |"    << endl;
        cout << "       |        /|\\"  << endl;
        cout << "       |         | "   << endl;
        cout << "       |        /|\\"  << endl;
        cout << "       |         O"    << endl;
        cout << "       | "             << endl;
        cout << "       | "             << endl;
        cout << "     ----- "           << endl;
    }
}

// Function begins a game loop that ends after 3 guesses or correct answer
// Returns a game state object on completion
game_state begin_play(){ 
    game_state state;
    state.guess_count = 3;
    state.word = "yoobee";
    state.missing_char = 'o';
    state.player_wins = false;
    state.playing = true; 
    char guess_char;

    while (state.playing) { // While guess count is more than 0; loop asks user for input and checks their character against the missing character
        cout << "Guess the missing letter in Yo_bee: ";
        cin >> guess_char;

        if (guess_char == state.missing_char) { // If player guess correctly, game ends.
            state.player_wins = true;
            state.playing = false;
            print_hangman(state);
        }

        if (guess_char != state.missing_char) { // If player guesses incorrectly but still has guesses available, gae continues
            state.guess_count -= 1;
        }   

        if (state.guess_count == 0) { // If player has used all 3 guesses, end game loop. 
            state.playing = false;
            print_hangman(state);
        }   
    }
    return state;
}


int main() {
    print_intro(); // On start, prints game introduction.
    begin_play(); // Begins a single game loop.
    return 0;
}