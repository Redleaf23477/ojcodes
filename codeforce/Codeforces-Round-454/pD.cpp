//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int M = 100005;
bool src;
int arr[M];
int r, c;
void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    src = false;
    cin >> r >> c;
    if(r > c)
    {
        int tmp = r; r = c, c = tmp;
        src = true;
    }
}

void print(char ch)
{
    if(ch == 'y')
    {
        cout << "YES" << endl;
        for(int i = 0; i < r; i++)
        {
            cout << arr[i*c];
            for(int j = 1; j < c; j++)
            {
                cout << " " << arr[i*c+j];
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;
}

void process()
{
    if(r == 1 && c == 1) 
    {
        arr[0] = 1; print('y');
    }
    else if(r == 1 && (c == 2 || c == 3)) print('n');
    else if(r == 1)
    {
        int i, j;
        for(i = 0, j = 2; j <= c; i++, j+=2) arr[i] = j;
        for(j = 1; j <= c; i++, j+=2) arr[i] = j;
        print('y');
    }
    else if(r == 2 && (c == 2 || c == 3)) print('n');
    else if(r == 3 && c == 3)
    {
        int tmp[] = {8, 3, 4, 1, 5, 9, 6, 7, 2};
        for(int i = 0; i < 9; i++) arr[i] = tmp[i];
        print('y');
    }
    else
    {
        int *ptr = arr;
        for(int i = 1; i <= r*c; i++, ptr++) *ptr=i;
        if(src)
        {
            int tmp = r; r = c, c = tmp;
            //even columns: up shift*2
            for(int i = 0; i < c; i+=2)
            {
                int tmp1 = arr[i], tmp2 = arr[i+c];
                for(int j = 0; j < r-2; j++) arr[i+j*c] = arr[i+(j+2)*c];
                arr[i+(r-2)*c] = tmp1, arr[i+(r-1)*c] = tmp2;
            }
            //odd rows: left shift*1
            for(int i = 1; i < r; i+=2)
            {
                int tmp = arr[i*c];
                for(int j = 0; j < c-1; j++) arr[i*c+j] = arr[i*c+j+1];
                arr[(i+1)*c-1] = tmp;
            }
            print('y');
        }
        else
        {
            //even rows: left shift *2
            for(int i = 0; i < r; i+=2)
            {
                int tmp1 = arr[i*c], tmp2 = arr[i*c+1];
                for(int j = 0; j < c-2; j++) arr[i*c+j] = arr[i*c+j+2];
                arr[(i+1)*c-2] = tmp1, arr[(i+1)*c-1] = tmp2;
            }
            //odd columns: up shift *1
            for(int i = 1; i < c; i+=2)
            {
                int tmp = arr[i];
                for(int j = 0; j < r-1; j++) arr[j*c+i] = arr[(j+1)*c+i];
                arr[(r-1)*c+i] = tmp; 
            }
            print('y');
        }
    }
}

