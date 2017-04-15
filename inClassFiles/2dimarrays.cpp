//This program demos arrays
#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 2;
const int COLS = 3;

int main()
{
    int scores[ROWS][COLS] = {0}, total = 0;
    double avg = 0;
    cout << "Please enter 6 scores:";
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cin >> scores[i][j];
        }
    }
    //output the whole array
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << scores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //calculate the quiz average for each student
    for(int i = 0; i < ROWS; i++)
    {
        total = 0;
        for(int j = 0; j < COLS; j++)
        {
            total += scores[i][j];
        }
        avg = static_cast<double>(total) / COLS;
        cout << "Average of student " << i + 1 << " = " << avg << endl;
    } 

    return 0;
}

