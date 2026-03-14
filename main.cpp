#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void showBoard() {
    cout << endl;
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
    cout << "-+-+-" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
    cout << "-+-+-" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
    cout << endl;
}

bool makeMove(int move) {

    int row = (move-1) / 3;
    int col = (move-1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

bool checkWin() {

    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return true;

    return false;
}

void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {

    int move;
    int turns = 0;

    while(true) {

        showBoard();

        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> move;

        if(makeMove(move)) {

            turns++;

            if(checkWin()) {
                showBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if(turns == 9) {
                showBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            switchPlayer();
        }
        else {
            cout << "Invalid move! Try again.\n";
        }
    }

    return 0;
}