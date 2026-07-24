#include <iostream>
#include <cmath>
using namespace std;

int x[20], n;
bool found = false;

bool Place(int x[], int k, int i)
{
    for(int j = 1; j <= k - 1; j++)
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    return true;
}

void PrintSolution(int x[], int n)
{
    cout << "One Feasible Solution:\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void NQueens(int x[], int n, int k)
{
    if(found == true)
        return;

    for(int i = 1; i <= n; i++)
    {
        if(Place(x, k, i))
        {
            x[k] = i;

            if(k == n)
            {
                PrintSolution(x, n);
                found = true;
                return;
            }
            else
                NQueens(x, n, k + 1);
        }
    }
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens(x, n, 1);

    if(found == false)
        cout << "No feasible solution";

    return 0;
}

