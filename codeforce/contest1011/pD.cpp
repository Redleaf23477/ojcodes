//
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int N = 33;

int mxdist, n;
bool seq[N];

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    cin >> mxdist >> n;
}

void getSeq()
{
    for(int i = 0; i < n; i++)
    {
        int res;
        cout << 1 << endl;
        cin >> res;
        if(res == 0) exit(0);
        else if(res == 1) seq[i] = true;
        else seq[i] = false;
    }
}

void getAns()
{
    int high = mxdist, low = 1, mid, res;
    for(int i = 0; low <= high; i=(i+1)%n)
    {
        mid = low+(high-low)/2;
        cout << mid << endl;
        cin >> res;
        if(res == 0) exit(0);
        if(seq[i] == false) res = -res;
        if(res == 1) low = mid+1;
        else high = mid-1;
    }
}

void process()
{
    getSeq();
    getAns();
}

