//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 200005;
int n, pos;
int arr[N], pt[N];

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
    cin >> n >> pos;
    pos--;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> pt[i];
}

void process()
{
    priority_queue<int> pq;
    int f = 1, b = n-1, focus = arr[pos]+pt[0];
    pq.push(focus);
    for(int i = 0; i < n; i++)
    {
        if(i == pos) continue;
        if(arr[i] > focus) pq.push(arr[i]+pt[f++]);
        else pq.push(arr[i]+pt[b--]);
    }
    int cnt = 1;
    while(pq.top() > focus)
    {
        pq.pop();
        cnt++;
    }
    cout << cnt << endl;
}

