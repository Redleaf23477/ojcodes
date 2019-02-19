//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define val first
#define pos second

bool cmp(const P &lhs, const P &rhs)
{
    return lhs.val > rhs.val || (lhs.val == rhs.val && lhs.pos < rhs.pos);
}

const int N = 200005;

ll n, mnlen, groupNum;
ll arr[N];
P srt[N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> mnlen >> groupNum;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        srt[i] = make_pair(arr[i], i);
    }
    sort(srt, srt+n, cmp);
}

void process()
{
    vector<ll> ans;
    vector<bool> goodPos(n, false);
    ll sum = 0;
    for(int i = 0; i < groupNum*mnlen; i++) 
    {
        sum += srt[i].val;
        goodPos[srt[i].pos] = true;
    }
    cout << sum << endl;
    for(int i = 0, len = 0, cnt = 0; i < n; i++)
    {
        if(goodPos[i] == true) len++;
        if(len == mnlen)
        {
            cout << i+1 << " ";
            len = 0;
            cnt++;
        }
        if(cnt == groupNum-1) break;
    }
    cout << endl;
}

