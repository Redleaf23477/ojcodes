//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> Pt;
#define x first
#define y second

int n;
vector<Pt> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

bool cmp(const Pt &lhs, const Pt &rhs)
{
    if(lhs.x != rhs.x) return lhs.x < rhs.x;
    else return lhs.y < rhs.y;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr.begin(), arr.end(), cmp);
}

bool bad()
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i].y < arr[i-1].y) return true;
    }
    return false;
}

void printPath()
{
    int x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        while(x < arr[i].x) { cout << "R"; x++; }
        while(y < arr[i].y) { cout << "U"; y++; }
    }
    cout << endl;
}

void process()
{
    if(bad()) cout << "NO" << endl;
    else 
    {
        cout << "YES" << endl;
        printPath();
    }
}

