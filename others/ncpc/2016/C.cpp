//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

string str;
int target;
vector<int> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(getline(cin, str) && str[0] != '0')
    {
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    stringstream ss(str);
    int x;
    arr.clear();
    while(ss >> x)
    {
        arr.push_back(x);
    }
}

void process()
{
    int INF = (1ll << 30);
    if(arr.size() <= 2)
    {
        cout << 1 << endl;
    }
    else
    {
        int mn = -INF, mx = INF, prv = arr[1];
        if(arr[0] < arr[1]) mn = arr[0];
        else mx = arr[0];
        for(size_t i = 2; i < arr.size(); i++)
        {
            if(arr[i] < mn || arr[i] > mx)
            {
                cout << 0 << endl; return;
            }
            if(arr[i] > prv) mn = prv;
            else mx = prv;
            prv = arr[i];
        }
        cout << 1 << endl;
    }
}

