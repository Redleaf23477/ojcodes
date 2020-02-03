//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<int> mx, mn;

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

bool ascend(vector<int> &seq)
{
    if(seq.size() == 1) return false;
    for(size_t i = 1; i < seq.size(); i++)
        if(seq[i] > seq[i-1]) return true;
    return false;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int len; cin >> len;
        vector<int> tmp(len);
        for(int j = 0; j < len; j++) cin >> tmp[j];
        int mxVal = *max_element(tmp.begin(), tmp.end());
        int mnVal = *min_element(tmp.begin(), tmp.end());
        if(!ascend(tmp)) 
        {
            mx.push_back(mxVal);
            mn.push_back(mnVal);
        }
    }
}

void process()
{
    sort(mx.begin(), mx.end());
    ll innerAsc = n - mx.size();
    ll ans = innerAsc * n;
//    cout << "innerAsc = " << innerAsc << endl;
    for(auto mnVal : mn)
    {
        int add = mx.end() - upper_bound(mx.begin(), mx.end(), mnVal);
//        cout << mnVal << " : " << add << endl;
        ans += add + innerAsc;
    }
    cout << ans << endl;
}

