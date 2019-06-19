//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 200005;
const ll INF = (1ll<<60);
int n;
bool del[N];
ll arr[N];

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
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        del[i] = false;
        cin >> arr[i];
    }
}

void process()
{
    vector<int> trash;
    int negNum = 0;
    ll mxNeg = -INF, pos = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0) 
        {
            trash.push_back(i);
        }
        if(arr[i] < 0)
        {
            negNum++;
            if(arr[i] > mxNeg) mxNeg = arr[i], pos = i;
        }
    }
    if(negNum%2 == 1) trash.push_back(pos);
    for(int i = 1; i < trash.size(); i++)
    {
        del[trash[i-1]] = true;
        cout << 1 << " " << trash[i-1]+1 << " " << trash[i]+1 << endl;
    }
    if(trash.size() && trash.size() < n)
    {
        del[trash.back()] = true;
        cout << 2 << " " << trash.back()+1 << endl;
    }
    int prv = -1;
    for(int i = 0; i < n; i++)
    {
        if(!del[i])
        {
            if(prv == -1) prv = i;
            else 
            {
                cout << 1 << " " << prv+1 << " " << i+1 << endl;
                prv = i;
            }
        }
    }
}
