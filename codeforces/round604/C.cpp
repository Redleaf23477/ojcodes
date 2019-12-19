//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<int> sum;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    sum.clear();
    cin >> n;
    int prv = -1, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(prv == x) cnt++;
        else 
        {
            if (cnt > 0) sum.emplace_back(cnt);
            cnt = 1, prv = x;
        }
    }
    sum.emplace_back(cnt);
    for(size_t i = 1; i < sum.size(); i++) sum[i] += sum[i-1];
}

bool good(int mid)
{
    int g = sum[0];
    int s_idx = upper_bound(sum.begin(), sum.begin()+mid+1, g*2) - sum.begin();
    if(s_idx == mid+1) return false;
    int s = sum[s_idx]-g;
    int b = sum[mid]-g-s;
    if(b <= g) return false;
    cout << g << " " << s << " " << b << endl;
    return true;
}

void process()
{
    int mid = upper_bound(sum.begin(), sum.end(), n/2) - sum.begin() - 1;
//    cout << n/2 << " " << mid << endl;
    bool ans = false;
    while(mid > 0)
    {
        if(good(mid)) { ans = true; break; }
        mid--;
    }
    if(ans == false) cout << 0 << " " << 0 << " " << 0 << endl;
}

