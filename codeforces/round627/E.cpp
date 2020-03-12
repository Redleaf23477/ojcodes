#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 2020;

int n, h, l, r;
int arr[N];
int bef[N], cur[N], nxt[N];

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
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool good(int t)
{
    return l <= t && t <= r;
}

void process()
{
    for(int i = 0; i < h; i++) bef[i] = -1;
    bef[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int t = 0; t < h; t++) cur[t] = -1;
        for(int t = 0; t < h; t++)
        {
            if(bef[t] >= 0)
            {
                for(int d = 0; d <= 1; d++)
                {
                    int nt = (t+arr[i]-d+h)%h;
                    if(good(nt))
                        cur[nt] = max(cur[nt], bef[t]+1);
                    else
                        cur[nt] = max(cur[nt], bef[t]);
                }
            }
        }
        /*
        cout << i << " : ";
        for(int t = 0; t < h; t++) cout << var(t) << cur[t] << " ";
        cout << endl;
        */
        for(int t = 0; t < h; t++)
            bef[t] = cur[t];
    }
    cout << *max_element(cur, cur+h) << endl;
}

