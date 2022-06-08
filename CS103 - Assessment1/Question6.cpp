#include <iostream>
#include <cstdlib>
using namespace std;

// CS103 Assessment 1, Emma Corkery - Question 6.

struct date {  // Structure for date. I have not included any logic to check if the date is valid or consecutive. 
    int day, month, year; // So long as the user provides three integers, this will return it as a date.

    date() {
        day = month = year = 0;
    }
    void print() {
        cout << day << "/" << month << '/' << year << endl;
    }
};


struct expenses {  // Struct for expenses 
        date en_date;
        double transport,
            entertainment,
            others,
            food,
            total;

        expenses(){      // Empty constructor
            date en_date;
            transport = entertainment = others = food = total = 0;
        }

        expenses (date _en_date, double tr, double ent, double ot, double fd, double tot) {
            transport = tr;
            entertainment = ent;
            others = ot;
            food = fd;
            total = tot;
        } 

        void print() {    /// function for printing expense struct report
            cout << "EXPENSE REPORT for ";
            en_date.print();
            cout << "------------------------" << endl;
            cout << "Transport:     $" << transport << endl;
            cout << "Entertainment: $" << entertainment << endl;
            cout << "Food:          $" << food << endl;
            cout << "Other:         $" << others << endl;
            cout << "------------------------" << endl;
            cout << "Total:         $" << total <<endl;
        }
};


expenses input_data(){   /// Collects input data from user
    date entry_date;
    expenses entry;
    cout << "What date were these expenses incurred? Please enter as DD MM YY: " << endl;
    cin >> entry_date.day >> entry_date.month >> entry_date.year;
    entry.en_date = entry_date;
    cout << "Enter your expenses when prompted, enter 0 if none were incurred \n" << endl;
    cout << "Please enter transport costs: " << endl;
    cin >> entry.transport;
    cout << "Please enter entertainment costs: " << endl;
    cin >> entry.entertainment;
    cout << "Please enter food costs: " << endl;
    cin >> entry.food;
    cout << "Please enter any other costs: " << endl;
    cin >> entry.others;
    entry.total = entry.transport + entry.entertainment + entry.food + entry.others;  /// Adds user input and stores it as total
    cout << "Your total expenses for " << entry_date.day << "/" << entry_date.month << "/" << entry_date.year << " are: " << endl;
    cout << entry.total << endl;
    return entry;
}


// Prints a weekly totals report, based on the array of user entries
void week_report(expenses weekly[7], int entries){
    expenses week;
    int i = 0;
        while (i < entries) {
            week.transport += weekly[i].transport;
            week.entertainment += weekly[i].entertainment;
            week.food += weekly[i].food;
            week.others += weekly[i].others;
            week.total += weekly[i].total;
            i++;
        }
    cout << "------- WEEKLY REPORT -------\n";
    week.print();  //uses struct print function
    cout << "------- WEEKLY REPORT -------\n";
}

void print_menu(){
    int selection = 0; // User menu selection
    int current_ent = 0; // Records current number of daily entries
    bool in_menu = true; // Keeps menu open until user selects exit
    expenses weekly[7]; // Array for storing 7 entries (1 week) of daily expsense data

    while (in_menu) {
        cout << "\n";
        cout << "--== MAIN MENU ==--" << endl;
        cout << "Welcome to your Personal Expense Tracking System." << endl;
        cout << "Please select from the menu options below: \n" << endl;
        cout << "1. Input my daily expenses. " << endl;
        cout << "2. Show daily report. " << endl;
        cout << "3. Show weekly report. " << endl;
        cout << "4. Exit. " << endl;
        cin >> selection;
        cout << "\n";

        if (selection == 1) {
            if (current_ent < 7) {
                expenses entry = input_data();
                weekly[current_ent++] = entry;
            }
            else {
                cout << "You have already completed the weeks entries \n";  // Program only stores 7 inputs(1 week)
            }
        }
        else if  (selection == 2) {  // Returns days in order of input
            int day = 0;
            cout << "Which day would you like to view the expense report for, 1 - 7 :"; 
            cin >> day;
            if (day <= current_ent) {         // Checks if data for the selected day exists
                weekly[day - 1].print();    
            }
            else {
                cout << "\nThere is no expense record for this day. Please provide data or a valid selection." << endl; 
            }
        }
        else if (selection == 3) {  //Checks that enough data has been input for a weekly report. User must input at least 3 days of
            if (current_ent < 3) {  // expenses in order to use the Weekly Report option. 
                cout << "Weekly report unavailable. You have entered less than 3 days of expenses. \n Please add more to access this function." << endl; 
            }
            else {
                week_report(weekly, current_ent);
            }
        }
        else if (selection == 4) {   // Ends menu loop and terminates program
            in_menu = false;
            cout << "Goodbye!\n";
        }
        else {
            cout << "Please enter a valid selection. \n";
        }
        cout << "\n\n\n"; // Moving menu up for readability
    }
}


int main(){
    print_menu();
    return 0;
}
