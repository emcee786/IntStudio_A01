#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// / CS103 Assessment 1, Emma Corkery - Question 5.

// Struct for state of game play
struct shape_game
{   
    int score[5];
    int play_count;
    bool playing;
};

// Print triangle on demand
void print_triangle(){
    cout << "\n";
    cout << "   *\n";
    cout << "  * *\n";
    cout << " * * *\n";
    cout << "\n";
}

// Print square on demand
void print_square(){
    cout << "\n";
    cout << " * * * \n";
    cout << " * * * \n";
    cout << " * * * \n";
    cout << "\n";
}

// Print h * w rectangle, if height == width, add 1 to height to make a rectangle
void print_rectangle (int height, int width){
    char star = '*';
    cout << endl;
    if (height == width) { // change squares to rectangles
        height += 1;
    }
    for (int h = 0; h < height; h++ ){
        for (int w = 0; w < width; w++) {
                cout << " " << star; // for w in height print spaced *'s
            }
        cout << endl;
    }
    cout << endl;
}       

// generate two random ints for creating a rectangle
int generate_rectangle(){
    srand(time(0));
    int height = rand() % 4 + 2;
    int width = rand() % 4 + 2;
    print_rectangle(height, width);
    return 0;
}

// randomly generate a shape, print it, return matching case as int
int generate_shape(){
    srand(time(0));
    int shape = rand() % 3;
    switch(shape){
        case 0:
            print_triangle();
            break;
        case 1:
            print_square();
            break;
        case 2:
            generate_rectangle();
            break;
    }
    return shape;
}

// convert char to matching shape int, if invalid selection say so, player still loses
int check_answer(char ch){ 
    if ( ch == 't' )
        { return 0; }
    if ( ch == 's' ) 
        { return 1; }
    if (ch == 'r') 
        { return 2; }  
    else 
        { cout << "Incorrect or invalid selection. \n"; return 3; }
}

// Calculate score from game state objects score array, return the score as integer value
// I would have just accumulated this but marking sheet said I had to have a final score function.
int final_score(shape_game state) {
    int total = 0;
    for (int i = 0;  i < 5; i++)
    {   
        total += state.score[i];
    }
    return total;
    cout << total;
}

// Starts a 5 match game loop, returns the score from this game as an integer
int start_play(){
    shape_game state;
    state.play_count = 5;
    char answer;
    int i = 0;

    while (state.play_count > i) // game loop for 5 games
    {
        cout << "What shape is this?\n";
        int shape_val = generate_shape();
        cout << "Enter t, for triangle\n";
        cout << "Enter s, for square\n";
        cout << "Enter r, for rectangle\n";
        cout << "Enter n, for none of the above\n";
        cin >> answer;
        int answer_val = check_answer(answer);
        
        if (answer_val == shape_val) // add 10 points to score array for correct guess
            {
            state.score[i] = 10;
            cout << "Correct!\n";
        }
        if  (answer_val != shape_val) // add 0 points for incorrect guess
            {
            state.score[i] = 0;
            cout << "Wrong!\n";
        }
        i += 1;
    }
    int points = final_score(state);
    cout << "You got " << points << " points!" << endl;
    return points;
}


void main_menu() { 
    int selection;
    bool played = false;     // Control boolean to stop early score requests 
    bool in_menu = true;     // Control boolean for leaving menu loop
    int topscore = 0;
    const int PLAY = 1,      // Constants for main menu selection
            FINAL_SCORE = 2,
            EXIT = 3;
    cout << "\n\n\n\n";
    cout << "Welcome to guess the shape!\n" << endl;
    

    while (in_menu) {
        cout << "--== MAIN MENU ==--"<< endl;
        cout << "1. Play" << endl;
        cout << "2. Final Score" << endl;
        cout << "3. Exit" <<endl;
        cout << "Please select from the above options" << endl;
        cin >> selection;

        if (selection == 1){  // enter a game loop, if score better than current high score record it, else discard
            int newscore = start_play();
            if (topscore < newscore) {topscore = newscore;}; 
            played = true;
        }
        else if (selection == 2){
            if (played) {
                cout << "Your top score was: " << topscore << endl; // print score
            }
            else {
                cout << "Play a game first!" << endl; // if no score advise to play game
            }
        }
        else if (selection == 3){ // exit menu loop, could have used a break but I think this is nicer
            in_menu = false;
            cout << "Bye!" << endl;
        }
        else {
            cout << "Please enter a valid option." << endl;  // Cacth bad entries
        }
        cout << "\n\n\n"; // Moving menu up for readability
    }
}


// Upon running this file a shape guessing game will begin
// Menu to start game, display score and exit,
// Games each cosist of 5 guesses, the top score is recorded for this session
int main()
{   
    main_menu();
    return 0;
}