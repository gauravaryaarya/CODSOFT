#include <iostream>

using namespace std;

class TicTacToeGame {
private:
    char board[3][3];
    char currentPlayer;
    string player1, player2;

    void initializeBoard() {
        char count = '1';
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = count++;
            }
        }
        currentPlayer = 'X';
    }

    void displayBoard() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << board[i][j];
                if(j != 2) cout << " | ";
            }
            cout << endl;
            if(i != 2) cout << "---------" << endl;
        }
    }

    bool isWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    bool isTie() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

public:
    TicTacToeGame() {
        initializeBoard();
    }

   void playRound() {
    int move;
    bool validMove = false;
    while(!validMove) {
        displayBoard();
        cout << ((currentPlayer == 'X') ? player1 : player2) << "'s turn. Enter your position (1-9): ";
        cin >> move;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }

        int x = (move - 1) / 3;
        int y = (move - 1) % 3;

        if(move >= 1 && move <= 9 && board[x][y] != 'X' && board[x][y] != 'O') {
            validMove = true;
            board[x][y] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move!" << endl;
        }
    }
}


    void playGame() {
        cout << "Enter Player-1's Name (X): ";
        cin >> player1;
        cout << "Enter Player-2's Name (O): ";
        cin >> player2;
        cin.ignore();

        while(!isWin() && !isTie()) {
            playRound();
        }

        displayBoard();
        if(isWin()) {
            cout << ((currentPlayer == 'O') ? player1 : player2) << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        char choice;
        cout << "Play again? (Y/N): ";
        cin >> choice;

        if(choice == 'Y' || choice == 'y') {
            initializeBoard();
            playGame();
        }
    }
};

int main() {
    TicTacToeGame game;
    game.playGame();
    return 0;
}
