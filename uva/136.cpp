//uva 136 ugly number
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef unsigned long long int ll;

void init();
void process();

int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    set<ll> vis;
    int arr[] = {2, 3, 5};
    pq.push(1);
    for(int i = 0; i < 1499; i++)
    {
        ll tp = pq.top(); pq.pop();
        for(int j = 0; j < 3; j++) if(vis.count(tp*arr[j]) == 0) pq.push(tp*arr[j]), vis.insert(tp*arr[j]);
    }
    cout << "The 1500'th ugly number is " << pq.top() << "." << endl;
    return 0;
}

