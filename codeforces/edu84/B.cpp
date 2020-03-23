// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

const int N = 100005;

int n;
vector<int> arr[N];

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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        arr[i].resize(x);
        for(int j = 0; j < x; j++) 
        {
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }
}

void process()
{
    int lg = -1, lb = -1;
    vector<int> girl(n, -1), boy(n, -1);
    for(int g = 0; g < n; g++)
    {
        for(auto b : arr[g])
        {
            if(boy[b] == -1)
            {
                girl[g] = b;
                boy[b] = g;
                break;
            }
        }
        if(girl[g] == -1) lg = g;
    }
    for(int i = 0; i < n; i++)
        if(boy[i] == -1)
            lb = i;
    if(lg == -1 && lb == -1)
        cout << "OPTIMAL" << endl;
    else
        cout << "IMPROVE" << endl << lg+1 << " " << lb+1 << endl;
}

