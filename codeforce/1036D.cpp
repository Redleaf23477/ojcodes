//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;
int lenA, lenB;
ll arrA[N], arrB[N];
ll sumA[N], sumB[N];

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
    cin >> lenA;
    for(int i = 0; i < lenA; i++) cin >> arrA[i+1];
    cin >> lenB;
    for(int i = 0; i < lenB; i++) cin >> arrB[i+1];
    for(int i = 0; i < lenA; i++) sumA[i+1] = sumA[i]+arrA[i+1];
    for(int i = 0; i < lenB; i++) sumB[i+1] = sumB[i]+arrB[i+1];
}

void process()
{
    int cnt = 0, leftA = 0, leftB = 0;
    for(int i = 1; i <= lenA; i++)
    {
        ll *ptr = lower_bound(sumB, sumB+1+lenB, sumA[i]);
        if(ptr != sumB+1+lenB && *ptr == sumA[i]) cnt++, leftA = i, leftB = ptr-sumB;
    }
    if(leftA != lenA || leftB != lenB) cout << -1 << endl;
    else cout << cnt << endl;
}

