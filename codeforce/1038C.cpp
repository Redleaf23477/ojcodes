//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

int n;
ll arrA[N], arrB[N];

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
        cin >> arrA[i];
    for(int i = 0; i < n; i++)
        cin >> arrB[i];
    sort(arrA, arrA+n, greater<ll>());
    sort(arrB, arrB+n, greater<ll>());
}

void process()
{
    ll a = 0, b = 0;
    int idxA = 0, idxB = 0;
    for(int i = 0; i < n; i++)
    {
        // turn A
        if(idxA == n) idxB++;
        else if(idxB == n) a += arrA[idxA++];
        else if(arrA[idxA] >= arrB[idxB]) a += arrA[idxA++];
        else idxB++;
        // turn B
        if(idxB == n) idxA++;
        else if(idxA == n) b += arrB[idxB++];
        else if(arrB[idxB] >= arrA[idxA]) b += arrB[idxB++];
        else idxA++;
    }
    cout << a-b << endl;
}

