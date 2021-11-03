#include <iostream>
#include <string>

using namespace std;

void display(); // displays the board
int get_choice(); // gets the marker the current player wants to place
int mark_cell(int i); // sets the current player's marker

// Returns the current player's marker should be
char get_current_player_marker();

// Returns row index of a cell based on a cell number.
int get_cell_row(int);
// Returns col index of a cell based on a cell number.
int get_cell_col(int);
// Return value at a cell
char get_cell(int);

// These check whether or not a play won each round
bool check_col_win();
bool check_row_win();
bool check_diag_win();
bool check_win();



char board[3][3] = { { ' ',' ',' ' },{ ' ',' ',' ' },{ ' ',' ',' ' } };
char player_one_marker;
char player_two_marker;

bool is_player_one_turn = true;

int main() {
    // Choose marker for players
    do {
        cout << "Player 1 choose between X and O: ";
        cin >> player_one_marker;
        player_one_marker = toupper(player_one_marker);

    } while (player_one_marker != 'X' && player_one_marker != 'O');

    if (player_one_marker == 'X') {
        player_two_marker = 'O';
    }
    else {
        player_two_marker = 'X';
    }

    // Start the game
    bool win = false;

    do {
        bool cellMarked;
        do {
            cellMarked = mark_cell(get_choice());
        } while(!cellMarked);

        display();

        win = check_win();
        is_player_one_turn = !is_player_one_turn; // watch out for this

    } while (!win);

    cout << "PLAYER " << (is_player_one_turn ? 2 : 1) << " WON!";

    return 0;
}

void display() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }

        cout << endl;
        cout << "-------------";
        cout << endl;
    }

}

int get_choice() {
    int choice = 0;
    cout << "[PLAYER " << (is_player_one_turn ? 1: 2) << "\'s TURN] What position do you choose? ";
    cin >> choice;
    cout << endl;

    return choice;
}

char get_current_player_marker() {
    return (is_player_one_turn ? player_one_marker : player_two_marker);
}

int get_cell_row(int i) {
    return static_cast<int>(i / 3.5);
}

int get_cell_col(int i) {
    int col = i % 3;
    return (col == 0 ? 3 : col) - 1;
}

char get_cell(int i) {
    int row = get_cell_row(i);
    int col = get_cell_col(i);

    return board[row][col];
}

int mark_cell(int i) {
    int row = get_cell_row(i);
    int col = get_cell_col(i);

    if (board[row][col] == ' ') {
        board[row][col] = get_current_player_marker();
        return true; // replacement succesfull

    } else if (i < 0 || i > 9) {
        cout << "Replacement out of range. Make sure it's between 1 and 9.";
        return false; // replacement not succesfull
    }
    else {
        cout << "This position has been filled choose another one." << endl;
        return false; // replacement not succesfull
    }
}

bool check_col_win() {
    // Iterates throught all columns
    for (int col = 0; col < 3; col++) {
        // If all rows on that column are the same
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[2][col] == get_current_player_marker()) {
            // Returns whether or not the value at one of those cells is equal to the current player's marker
            return true;
        }
    }

    return false;
}


bool check_row_win() {
    // Iterates throught all rows
    for (int row = 0; row < 3; row++) {
        // If all columns on that row are the same
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][2] == get_current_player_marker()) {
            return true;
        }
    }

    return false;
}

bool check_diag_win() {
    // Only possible combinations for a diagonal win
    if (get_cell(1) == get_cell(5) && get_cell(5) == get_cell(9) && get_cell(9) == get_current_player_marker()) {
        return true;
    } else if (get_cell(3) == get_cell(5) && get_cell(5) == get_cell(7) && get_cell(7) == get_current_player_marker()) {
        return true;
    }

    return false;
}

bool check_win() {
    return check_col_win() || check_row_win() || check_diag_win();
}

