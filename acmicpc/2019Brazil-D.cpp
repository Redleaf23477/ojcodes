//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

int vn, k;
int pa[N];

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
    cin >> vn >> k;
    for(int i = 2; i <= vn; i++) 
    {
        int j; cin >> j;
        pa[i] = j;
    }
}

void process()
{
    queue<int> q;
    vector<int> len(vn+1, 0);
    vector<bool> isLeaf(vn, true);
    for(int i = 1; i <= vn; i++) isLeaf[pa[i]] = false;
    for(int i = 1; i <= vn; i++) if(isLeaf[i]) q.push(i);

    while(q.empty())
    {
    }
}

