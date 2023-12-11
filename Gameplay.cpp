#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int currentPlayer = 1;

void drawBoard() {
    system("clear"); 
    cout << "Silverogue\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isMoveValid(int move) {
    return (move >= 1 && move <= 9 && board[(move - 1) / 3][(move - 1) % 3] == ' ');
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Check baris
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Check kolom
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Check diagonal 1
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Check diagonal 2
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void botMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isMoveValid(move));

    char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
    board[(move - 1) / 3][(move - 1) % 3] = playerSymbol;
}

int main() {
    int move;
    bool gameRunning = true;

    while (gameRunning) {
        drawBoard();

        if (currentPlayer == 1) {
            cout << "Knight, enter your move (1-9): ";
            cin >> move;

            if (isMoveValid(move)) {
                char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
                board[(move - 1) / 3][(move - 1) % 3] = playerSymbol;

                if (checkWin()) {
                    drawBoard();
                    cout << "Knight wins!\n";
                    gameRunning = false;
                } else if (isBoardFull()) {
                    drawBoard();
                    cout << "It's a tie!\n";
                    gameRunning = false;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Please try again.\n";
            }
        } else {
            botMove();

            if (checkWin()) {
                drawBoard();
                cout << "Dragon wins!\n";
                gameRunning = false;
            } else if (isBoardFull()) {
                drawBoard();
                cout << "It's a tie!\n";
                gameRunning = false;
            } else {
                switchPlayer();
            }
        }
    }

    return 0;
}
