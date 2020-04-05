// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

int n;
vector<int> arr;

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
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        arr[i] -= x;
    }
}

int dc(int l, int r)
{
    if(l == r) return 0;
    int mid = (l+r)/2;
    int ans = 0;
    ans += dc(l, mid);
    ans += dc(mid+1, r);
    inplace_merge(arr.begin()+l, arr.begin()+mid+1, arr.begin()+r+1);
    return ans;
}

void process()
{
    cout << dc(0, n-1) << endl;
    for(auto x : arr) cout << x << " ";
    cout << endl;
}

