#include <cstdlib>
#include <iostream>
using namespace std;

const int NUM_ROW = 3;
const int NUM_COL = 3;

void reset_board(char board[][NUM_COL], int NUM_ROW);       // test if the game is finished
void player1(char board[][NUM_COL], int NUM_ROW);           // player 1 move
void player2(char board[][NUM_COL], int NUM_ROW);           // player 2 move
void print_board(char const board[][NUM_COL], int NUM_ROW); // print live board
bool test_board(char const board[][NUM_COL], int NUM_ROW);  // test if the game is finished

int main()
{
    char board[NUM_ROW][NUM_COL];

    char play;

    // Welcome page

    system("clear");

    cout << "Welcome to TWO-PLAYER TIC-TAC-TOE!\n\n\n Press 'P' to play or 'Q' to quit \n";
    cin >> play;
    while (play != 'q' && play != 'Q')
    {
        system("clear");

        bool game_finished = false;

        system("clear");

        reset_board(board, NUM_ROW); // reset the board

        while (game_finished == false)
        {
            player1(board, NUM_ROW);
            game_finished = test_board(board, NUM_ROW);

            if (game_finished == false)
            {
                player2(board, NUM_ROW);
                game_finished = test_board(board, NUM_ROW);
            }

            if (game_finished == true)
            {
                cout << "\n\nPress ENTER to continue...";
                cin.get();
                cin.get();
                system("clear");
                cout << "Welcome to TWO-PLAYER TIC-TAC-TOE!\n\n\n Press 'P' to play or 'Q' to "
                        "quit\n";
                cin >> play;
            }
        }
    }
    return 0;
}

// reset the board
void reset_board(char board[][NUM_COL], int NUM_ROW)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '*';
        }
    }
}
// Print out board
void print_board(char const board[][NUM_COL], int NUM_ROW)
{
    cout << "-------------\n";
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n";
    cout << "-------------\n";
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n";
    cout << "-------------\n";
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n";
    cout << "-------------\n";
}

// one round of game play
void player1(char board[][NUM_COL], int NUM_ROW)
{
    int player1_row, player1_col;

    print_board(board, NUM_ROW); // prints initial board

    cout << "Enter the coordinates of where you want to place your piece.\n";
    cout << "Player 1 Enter Row: ";
    cin >> player1_row;
    cout << "Player 1 Enter Column: ";
    cin >> player1_col;

    while (board[player1_row][player1_col] != '*' || (player1_row >= 3 || player1_col >= 3))
    {
        if (player1_row >= NUM_ROW || player1_col >= NUM_COL)
            cout << "Square does not exist, please try a different square.\n";
        else if (board[player1_row][player1_col] != '*')
            cout << "Square occupied, please try a different square.\n";

        cout << "Enter the coordinates of where you want to place your piece.\n";
        cout << "Player 1 Row: ";
        cin >> player1_row;
        cout << "Player 1 Column: ";
        cin >> player1_col;
    }

    board[player1_row][player1_col] = 'X';

    system("clear");
}

void player2(char board[][NUM_COL], int NUM_ROW)
{
    int player2_row, player2_col;

    print_board(board, NUM_ROW);

    cout << "Enter the coordinates of where you want to place your piece.\n";
    cout << "Player 2 Enter Row: ";
    cin >> player2_row;
    cout << "Player 2 Enter Column: ";
    cin >> player2_col;

    while (board[player2_row][player2_col] != '*' || (player2_row >= 3 || player2_col >= 3))
    {
        if (player2_row >= NUM_ROW || player2_col >= NUM_COL)
            cout << "Square does not exist, please try a different square.\n";
        else if (board[player2_row][player2_col] != '*')
            cout << "Square occupied, please try a different square.\n";

        cout << "Enter the coordinates of where you want to place your piece.\n";
        cout << "Player 2 Row: ";
        cin >> player2_row;
        cout << "Player 2 Column: ";
        cin >> player2_col;
    }

    board[player2_row][player2_col] = 'O';

    system("clear");
}

// tests the board for a winner
bool test_board(char const board[][NUM_COL], int NUM_ROW)
{
    // tests the rows
    for (int i = 0; i < NUM_ROW; i++)
    {
        for (int j = 0; j < NUM_COL; j++)
        {
            if (board[i][j] != '*' &&
                (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 1]))
            {
                if (board[i][j] == 'X')
                {
                    print_board(board, NUM_ROW);
                    cout << "Player 1 WINS!!!\n";
                    return true;
                }
                else if (board[i][j] == 'O')
                {
                    print_board(board, NUM_ROW);
                    cout << "Player 2 WINS!!!\n";
                    return true;
                }
            }
        }
    }

    // tests the columns
    for (int i = 0; i < NUM_COL; i++)
    {
        for (int j = 0; j < NUM_ROW; j++)
        {
            if (board[j][i] != '*' && board[j][i] == board[j + 1][i] &&
                board[j + 2][i] == board[j + 1][i])
            {
                if (board[j][i] == 'X')
                {
                    print_board(board, NUM_ROW);
                    cout << "Player 1 WINS!!!\n";
                    return true;
                }
                else if (board[j][i] == 'O')
                {
                    print_board(board, NUM_ROW);
                    cout << "Player 2 WINS!!!\n";
                    return true;
                }
            }
        }
    }

    // tests the diagnols
    if (board[0][0] != '*' && (board[0][0] == board[1][1] && board[1][1] == board[2][2]))
    {
        if (board[0][0] == 'X')
        {
            cout << "Player 1 WINS!!!\n";
            print_board(board, NUM_ROW);
            return true;
        }
        else if (board[0][0] == 'O')
        {
            cout << "Player 2 WINS!!!\n";
            print_board(board, NUM_ROW);
            return true;
        }
    }

    else if (board[2][0] != '*' && (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
    {
        if (board[2][0] == 'X')
        {
            cout << "Player 1 WINS!!!\n";
            print_board(board, NUM_ROW);
            return true;
        }
        else if (board[2][0] == 'O')
        {
            cout << "Player 2 WINS!!!\n";
            print_board(board, NUM_ROW);
            return true;
        }
    }

    // testing for a tie
    int counter;
    for (int i = 0; i < NUM_ROW; i++)
    {
        for (int j = 0; j < NUM_COL; j++)
        {
            if (board[i][j] != '*')
            {
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        print_board(board, NUM_ROW);
        cout << "Players Tied!\n";
        return true;
    }
    return false;
}
