//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

const int N = 1000006;
int n, arr[N], tmp[N];

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
    for(int i = 0; i < n; i++) cin >> arr[i];
}

ll ms_inversion(int* arr, int len)
{
    ll tot = 0;
    if(len == 1) return 0;
    // divide
    int leftLen = len/2, rightLen = len-leftLen ;
    int *leftArr = arr, *rightArr = arr+leftLen ;
    tot += ms_inversion(leftArr, leftLen);
    tot += ms_inversion(rightArr, rightLen);
    // conquer
    int tmpLen = 0, l = 0, r = 0;
    while(l < leftLen && r < rightLen)
        if(leftArr[l] < rightArr[r]) tmp[tmpLen++] = leftArr[l++];
        else tot += leftLen-l, tmp[tmpLen++] = rightArr[r++];
    while(l < leftLen) tmp[tmpLen++] = leftArr[l++];
    while(r < rightLen) tmp[tmpLen++] = rightArr[r++];
    for(int i = 0; i < tmpLen ; i++) arr[i] = tmp[i];
    return tot;
}

#define lowbit(x) (x&-x)
ll bit[N];
void add(int x, ll val)
{
    for(; x <= n; x+=lowbit(x))
        bit[x] += val;
}
ll query(int x)
{
    ll tot = 0;
    for(; x; x-=lowbit(x))
        tot += bit[x];
    return tot;
}
ll bit_inversion(int *arr, int len)
{
    ll tot = 0;
    for(int i = len-1; i >= 0; i--)
    {
        tot += query(arr[i]-1);
        add(arr[i], 1);
    }
    return tot;
}

void process()
{
    ll inv = bit_inversion(arr, n);
    if(n%2 == inv%2) cout << "Petr" << endl;
    else cout << "Um_nik" << endl;
}

