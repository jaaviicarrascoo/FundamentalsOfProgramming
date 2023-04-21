
#include <iostream>
#include <array>
#include <unistd.h> // for usleep()
using namespace std;

// consts
const int ROWS = 40;
const int COLS = 120;      // open it in a Terminal window big enough
const long DELAY = 10000;  // microsecs (1E-06 sec)
const bool BORDER = false; // live flows through walls

enum TState
{
    DEAD,
    ALIVE,
    TO_DIE,
    TO_BEBORN
};
typedef array<array<TState, COLS>, ROWS> TField;

// To clear screen.  For some terminals
// you have to find out which is the escape
// seq.  Standard Linux VT100:
const char CLRSCR[] = "\x1B[H\x1B[J";
// in windows, you could need to call the operating system
// system("cls")

// prototypes
void init(TField &field);
void nextGeneration(TField &field);
int noNeighbours(TField t, int row, int col);
void showBoard(TField field);
int countIt(TField t, int i, int j);

int main()
{
    // To Stop automatically:
    // check if reached a still state or a
    // typical rotative of two states.
    // there are other possible loops we are not
    // catching here
    TField field, antField, preAntField;
    int i = 1;
    srand((unsigned)time(0)); // new each run!
    init(field);

    do
    {
        showBoard(field);
        cout << "Generation: " << i++ << "  (^C to cut)" << '\r';
        cout.flush(); // '\r' rewrites the same line
        preAntField = antField;
        antField = field;
        nextGeneration(field); // modify in-situ, faster
        usleep(DELAY);
        cout << CLRSCR;
    } while (antField != field and field != preAntField);

    showBoard(field);
    cout << "Generation: " << i++ << endl;
    return 0;
}

// subprograms

void nextGeneration(TField &field)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int noNeigh;

            if (field[row][col] == ALIVE)
            {
                noNeigh = noNeighbours(field, row, col);

                if (not(noNeigh == 2 or noNeigh == 3))
                    field[row][col] = TO_DIE;
            }
            else
            { // not alive
                noNeigh = noNeighbours(field, row, col);

                if (noNeigh == 3)
                    field[row][col] = TO_BEBORN;
            }
        }
    }
    // now we can really DO the changes
    for (int m = 0; m < ROWS; m++)
        for (int n = 0; n < COLS; n++)
        {
            if (field[m][n] == TO_DIE)
                field[m][n] = DEAD;

            if (field[m][n] == TO_BEBORN)
                field[m][n] = ALIVE;
        }
}

void init(TField &field)
{
    // we could read a file with "special" confs
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            field[row][col] = TState(rand() % 2);
}

int noNeighbours(TField t, int row, int col)
{
    return countIt(t, row - 1, col - 1) +
           countIt(t, row, col - 1) +
           countIt(t, row + 1, col - 1) +
           countIt(t, row - 1, col) +
           countIt(t, row + 1, col) +
           countIt(t, row - 1, col + 1) +
           countIt(t, row, col + 1) +
           countIt(t, row + 1, col + 1);
}

// counts neighbours. Here the board can be made infinite
int countIt(TField t, int i, int j)
{
    bool isAnybodyThere = false;
    if (i < 0 or i >= ROWS or j < 0 or j >= COLS)
    {
        if (BORDER)
            isAnybodyThere = false;
        else
        {
            i = (i < 0) ? ROWS - 1 : i;
            j = (j < 0) ? COLS - 1 : j;
            j = (j == COLS) ? 0 : j;
            i = (i == ROWS) ? 0 : i;
            isAnybodyThere = t[i][j] == ALIVE or t[i][j] == TO_DIE;
        }
    }
    else
        isAnybodyThere = t[i][j] == ALIVE or t[i][j] == TO_DIE;
    return isAnybodyThere ? 1 : 0;
}

void showBoard(TField field)
{
    for (int row = 0; row < ROWS; row++)
    {
        cout << '|';

        for (int col = 0; col < COLS; col++)
            cout << ((field[row][col]) ? '#' : ' ');

        cout << "|" << endl;
    }
}