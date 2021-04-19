#include <iostream>

using namespace std;

class Gameboard{
    private:
    char board[3][3];
    int squaresRemaining = 9;

    public:
    void resetBoard();
    void showBoard();
    void playerMove(char);
    bool checkWin(char);

    int getSquaresRemaining();
    
    Gameboard();
};

Gameboard::Gameboard(){
for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void Gameboard::resetBoard(){
    squaresRemaining = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void Gameboard::showBoard(){
    cout << "  0" << "   1" << "   2" << '\n';
    cout << "0 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << '\n';
    cout << " ----------" << '\n';
    cout << "1 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << '\n';
    cout << " ----------" << '\n';
    cout << "2 " <<  board[2][0] << " | " << board[2][1] << " | " << board[2][2] << '\n';
}

int Gameboard::getSquaresRemaining(){
    return squaresRemaining;
}
void Gameboard::playerMove(char marker){
    bool validMove = false;
    int row, column;
    
    cout << "It's " << marker << "'s Turn!" << '\n';
    do{
        cout << "Choose a row: " << '\n';
            cin >> row;
        while(!cin || row < 0 || row > 2){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Please choose a valid row: "<< '\n';
            cin >> row;
        }

        cout << "Choose a column: " << '\n';
            cin >> column;
        while(!cin || column < 0 || column > 2){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Please choose a valid column: "<< '\n';
            cin >> column;
        }

        if(board[row][column] != ' '){
            cout << "Please choose an empty space!" << '\n';
            continue;
        } else{
            validMove = true;
        }

    }while(!(validMove));

    board[row][column] = marker;
    squaresRemaining--;
}

bool Gameboard::checkWin(char m){ //m for "marker"
    //First Row Win
    if(board[0][0] == m && board[0][1] == m && board[0][2] == m){
        return true;
    }
    //Second row win
    if(board[1][0] == m && board[1][1] == m && board[1][2] == m){
        return true;
    }
    //Third row win
    if(board[2][0] == m && board[2][1] == m && board[2][2] == m){
        return true;
    }

    //First Column Win
    if(board[0][0] == m && board[1][0] == m && board[2][0] == m){
        return true;
    }
    //Second Column Win
    if(board[0][1] == m && board[1][1] == m && board[2][1] == m){
        return true;
    }
    //Third Column Win
    if(board[0][2] == m && board[1][2] == m && board[2][2] == m){
        return true;
    }

    //First diagonal win
    if(board[0][0] == m && board[1][1] == m && board[2][2] == m){
        return true;
    }
    //Second diagonal win
    if(board[0][2] == m && board[1][1] == m && board[2][0] == m){
        return true;
    }

    return false;
}

