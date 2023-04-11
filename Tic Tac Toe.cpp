#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' ')); // Inicjalizacja planszy 3x3
char currentPlayer = 'X'; // Zmienna przechowujaca aktualnego gracza

// Funkcja sprawdzajaca, czy plansza jest pelna
bool isBoardFull() {
    for (auto &row : board)
        for (char cell : row)
            if (cell == ' ')
                return false;
    return true;
}

// Funkcja sprawdzajaca, czy którys z graczy wygral
bool checkWin() {
    for (int i = 0; i < SIZE; ++i)
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
            return true;

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return true;

    return false;
}

// Funkcja wyœwietlajaca plansze
void printBoard() {
    for (auto &row : board) {
        for (char cell : row)
            cout << cell << '|';
        cout << "\b \n-+-+-\n";
    }
    cout << "\b\b\b\b\b \n";
}

// Funkcja umozliwiajaca wykonanie ruchu na podanej pozycji
bool makeMove(int pos) {
    int x = --pos / SIZE;
    int y = pos % SIZE;
    if (board[x][y] == ' ') {
        board[x][y] = currentPlayer;
        return true;
    }
    return false;
}

int main() {
    int pos;

    // Petla glówna gry
    while (!isBoardFull() && !checkWin()) {
        printBoard();
        cout << "Gracz " << currentPlayer << ", podaj pozycje (1-9): ";
        cin >> pos;

        // Obsluga blednych danych wejsciowych
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Niepoprawny wprowadzony znak, sprobuj ponownie.\n";
            continue;
        }

        // Obsluga poprawnych danych wejsciowych
        if (pos >= 1 && pos <= 9 && makeMove(pos)) {
            if (checkWin()) {
                printBoard();
                cout << "Gracz " << currentPlayer << " wygrywa!\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Niepoprawny ruch, sprobuj ponownie.\n";
        }
    }

    // Jesli nie ma to wyœwietla komunikat o remisie
        if (!checkWin()) {
        printBoard();
        cout << "Remis!\n";
    }

    return 0;
}
