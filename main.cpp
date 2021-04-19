#include <iostream>
#include "gameboard.h"

using namespace std;

int main() {
    Gameboard newGame;
    while(newGame.getSquaresRemaining() > 0){
        newGame.showBoard();
        newGame.playerMove('X');
        newGame.showBoard();
        
        if(newGame.checkWin('X')){
            cout << "X wins!" << '\n';
            return 0;
        }
        
        if(newGame.getSquaresRemaining() == 0){
            break;
        }
        newGame.playerMove('O');
        newGame.showBoard();
        
        if(newGame.checkWin('O')){
            cout << "O Wins!" << '\n';
            return 0;
        }
        cout << newGame.getSquaresRemaining() << '\n';
    } 
     
    cout << "Its a draw!" << '\n';
    return 0;

}