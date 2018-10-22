//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 13;
int n, first;
int arr[N];

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
    cin >> n >> first;
    for(int i = 0; i < n; i++) cin >> arr[i];
    first = arr[first];
    sort(arr, arr+n);
}

void process()
{
    int ac = 0, pen = first, tim = first;
    if(first <= 300) 
    {
        ac = 1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == first) continue;
            if(arr[i] + tim <= 300)
            {
                tim += arr[i];
                pen += tim;
                ac++;
            }
        }
    }
    else ac = pen = 0;
    cout << ac << " " << pen << endl;
}

