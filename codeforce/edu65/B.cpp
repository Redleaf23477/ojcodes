//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

vector<int> guess;

void init();
void process();

int32_t main()
{
    init();
    process();
    return 0;
}

inline int query(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    cin >> x;
    return x;
}

void init()
{
    for(int i = 0; i < 4; i++) guess.push_back(query(i+1, i+2));
}

bool good(vector<int> &arr)
{
    for(int i = 0; i < 4; i++)
    {
        if(arr[i]*arr[i+1] != guess[i]) return false;
    }
    return true;
}

void process()
{
    vector<int> arr = {4, 8, 15, 16, 23, 42};
    do
    {
        if(good(arr)) 
        {
            cout << "!";
            for(auto x:arr) cout << " " << x;
            cout << endl;
            break;
        }
    } while(next_permutation(arr.begin(), arr.end()));
}

