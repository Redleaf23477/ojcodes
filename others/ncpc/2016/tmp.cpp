//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

bool make[100];

void dfs(vector<int> &arr, int s, int dep, int sum)
{
    if(dep == arr.size()) return;
    for(int i = s; i < arr.size(); i++)
    {
        make[sum+arr[i]] = true;
        dfs(arr, i+1, dep+1, sum+arr[i]);
    }
}

bool ok(int i, int j, int k, int l)
{
    memset(make, 0, sizeof(make));
    vector<int> arr = {1, 1, 1, i, j, k, l};
    dfs(arr, 0, 0, 0);
    for(int it = 1; it <= 90; it++)
        if(!make[it]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 1; i <= 90; i++)
    {
        for(int j = 1; j <= 90; j++)
        {
            for(int k = 1; k <= 90; k++)
            {
                int l = 90-3-i-j-k;
                if(l <= 0) continue;
                if(ok(i,j,k,l)) cout << i << " " << j << " " << k << " " << l << endl;
            }
        }
    }
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
}

