#include <iostream>

using namespace std;

void display(char arr[3][3]);
int get_choice();
/*int postion(char arr[3][3]);
void replacement();
bool check_col();
bool check_row();
bool check_diag();
bool check_win();*/



int main() {


    char board[3][3] = { { '*','*','*' },{ '*','*','*' },{ '*','*','*' } };



    cout << get_choice() << endl;

  
    return 0;

}



void display(char arr[3][3]) {

    cout << "-------------\n" ;
    for (int i = 0; i < 3; i++) {

        cout << "| ";

        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " | ";


        }

        cout << endl;
        cout << "-------------";
        cout << endl;
    }

}

int get_choice() {
    int choice = 0;
    cout << "what positon do you choose? ";
    cin >> choice;
    cout << endl;

    return choice;
}

int replacement(int i, char arr[3][3], int marker) {
    int col = i % 3;
    col = (col == 0 ? 3 : col) - 1;
    int row = static_cast<int>(i / 3.5);

    if  (arr[row][col] == ' ') {




    }
    else {
        //try again
    }

    return 0;

   
}