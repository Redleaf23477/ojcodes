//
#include <bits/stdc++.h>

//#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> Seg;
#define l first
#define r second

const int N = 1030;

int n, b, f;
int retsz;
int segStart[N];         // 1=start
int segEnd[N];           // 1=end
Seg arr[N];
vector<Seg> toGuess;

void init();
void process();

int32_t main()
{
//    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    cin >> n >> b >> f;
    retsz = n-b;
    for(int i = 0; i < n; i++) 
    {
        arr[i] = make_pair(0, n-1);
        segStart[i] = segEnd[i] = 0;
    }
}

void firstGuess()
{
    // generate guess string
    string str(n, '0'), res;
    for(int i = 0; i < n; i += 16)
    {
        if(i/16%2 == 0) continue;
        else for(int j = i; j < i+16 && j < n; j++) str[j] = '1';
    }
    cout << str << endl;

    // deal with result
    cin >> res;
    Seg s(0, min(15ll, n-1)); char ch = '0'; int cnt = 0;
    segStart[0] = 1;
    for(int i = 0; i < retsz; i++)
    {
        if(res[i] != ch) 
        {
            segStart[i] = 1;
            if(i != 0) segEnd[i-1] = 1;
            if(cnt == 16)
            {
                for(int j = i-16, k = s.l; j < i; j++, k++)
                {
                    arr[j].l = arr[j].r = k;
                }
            }
            else
            {
                toGuess.push_back(s);
                for(int j = i-cnt; j < i; j++)
                {
                    arr[j] = s;
                }
            }
            s.l += 16, s.r = min(s.r+16, n-1), ch = '0'+'1'-ch;
            cnt = 0;
        }
        cnt++;
    }
    // remainder parts
    segEnd[retsz-1] = 1;
    if(cnt == n%16)
    {
        for(int j = retsz-cnt, k = s.l; j < retsz; j++, k++)
        {
            arr[j].l = arr[j].r = k;
        }
    }
    else
    {
        toGuess.push_back(s);
        for(int j = retsz-cnt; j < retsz; j++)
        {
            arr[j] = s;
        }
    }

    /*
    // debug print
    for(int i = 0; i < retsz; i++)
    {
        cout << i << " : " << arr[i].l << " " << arr[i].r << endl;
    }
    */
}

void guess()
{
    /*
    for(auto s:toGuess)
    {
        cout << "toGuess : " << s.l << " " << s.r << endl;
    }
    */

    // generate guess string
    string guess(n, '0');
    for(auto s:toGuess)
    {
        int mid = (s.l+s.r)/2;
        for(int i = mid+1; i <= s.r; i++) guess[i] = '1';
    }
    cout << guess << endl;

    // deal with result
    toGuess.clear();
    string res; cin >> res;
    int chg = 0, L = 0;
    for(int i = 0; i < retsz; i++)
    {
        if(arr[i].l == arr[i].r) continue;
        if(segStart[i] == 1) L = i, chg = 0;
        if(res[i] == '1' && chg == 0)
        {
            int mid = (arr[L].l+arr[L].r)/2;
            Seg s(arr[L].l,mid);
            for(int j = L; j < i; j++)
                arr[j] = s;
            chg = 1;
            segStart[i] = 1;
            if(i != 0) segEnd[i-1] = 1;
            if(s.l != s.r) toGuess.push_back(s);
            if(mid+1 < arr[i].r) toGuess.emplace_back(mid+1, arr[i].r);
        }
        if(segEnd[i] == 1 && chg == 0)
        {
            int mid = (arr[L].l+arr[L].r)/2;
            Seg s(arr[L].l,mid);
            for(int j = L; j <= i; j++)
                arr[j] = s;
            chg = 1;
            segStart[i] = 1;
            if(i != 0) segEnd[i-1] = 1;
            if(s.l != s.r) toGuess.push_back(s);
            if(mid+1 < arr[i].r) toGuess.emplace_back(mid+1, arr[i].r);
        }
        if(res[i] == '1')
        {
            int mid = (arr[i].l+arr[i].r)/2;
            arr[i] = make_pair(mid+1, arr[i].r);
        }
    }

    /*
    // debug print
    for(int i = 0; i < retsz; i++)
    {
        cout << i << " : " << arr[i].l << " " << arr[i].r << endl;
    }
    */
}

void report()
{
    int gg = 0;
    vector<int> ans;
    for(int i = 0; i < retsz; i++, gg++)
    {
        while(gg != arr[i].l) ans.push_back(gg++);
    }
    while(gg < n) ans.push_back(gg++);
    cout << ans[0];
    for(size_t i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
}

void process()
{
    firstGuess();
    for(int i = 1; i < f && toGuess.size(); i++)
    {
        guess();
    }
    report();
    int res; cin >> res;
    if(res == -1) exit(0);
}

