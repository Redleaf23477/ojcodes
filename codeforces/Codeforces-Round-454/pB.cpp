//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

char arr[10][10];
int R, C;

void init();
void process();
void print();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    print();
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> arr[i][j];
    cin >> R >> C;
    R--, C--;
}

void process()
{
    int rr = R%3, cc = C%3;
    bool mod = false;
    for(int r = rr*3; r < rr*3+3; r++)
    {
        for(int c = cc*3; c < cc*3+3; c++)
        {
            if(arr[r][c] == '.') mod = true, arr[r][c] = '!';
        }
    }
    if(!mod)
    {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(arr[i][j] == '.') arr[i][j] = '!';
    }
}

void print()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 3; j < 6; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 6; j < 9; j++) cout << arr[i][j];
        cout << endl;
    }
    cout << endl;
    for(int i = 3; i < 6; i++)
    {
        for(int j = 0; j < 3; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 3; j < 6; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 6; j < 9; j++) cout << arr[i][j];
        cout << endl;
    }
    cout << endl;
    for(int i = 6; i < 9; i++)
    {
        for(int j = 0; j < 3; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 3; j < 6; j++) cout << arr[i][j];
        cout << " ";
        for(int j = 6; j < 9; j++) cout << arr[i][j];
        cout << endl;
    }
}
