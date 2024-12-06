#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }
    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    std::cout << "Player 1, choose your marker: ";
    char marker_p1;
    std::cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won;

    for (int i = 0; i < 9; i++) {
        std::cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        std::cin >> slot;

        if (slot < 1 || slot > 9) {
            std::cout << "Invalid slot! Try again." << std::endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            std::cout << "Slot occupied! Try again." << std::endl;
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();

        if (player_won == 1) {
            std::cout << "Player 1 won! Congratulations!" << std::endl;
            break;
        }
        if (player_won == 2) {
            std::cout << "Player 2 won! Congratulations!" << std::endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        std::cout << "It's a tie!" << std::endl;
    }
}

int main() {
    game();
    return 0;
}