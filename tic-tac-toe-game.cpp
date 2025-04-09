#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = start++;
}

void displayBoard() {
    cout << "\nTIC-TAC-TOE GAME\n";
    cout << "Player A (X)  -  Player B (O)\n\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j != 2) cout << "  |  ";
        }
        cout << "\n";
        if (i != 2)
            cout << "\n     |     |     \n";
    }
    cout << endl;
}

bool isValidMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    return (cell >= 1 && cell <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

string getPlayerName(char symbol) {
    return (symbol == 'X') ? "A" : "B";
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int move;
            cout << "Player " << getPlayerName(currentPlayer) << " (" << currentPlayer << "), enter your move (1-9): ";
            cin >> move;

            if (!isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << getPlayerName(currentPlayer) << " (" << currentPlayer << ") wins!\n";
                gameOver = true;
            } else if (isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}