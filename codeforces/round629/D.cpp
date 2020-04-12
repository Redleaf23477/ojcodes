// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

int n;
vector<int> arr;

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
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    if(*max_element(arr.begin(), arr.end()) == *min_element(arr.begin(), arr.end()))
    {
        cout << 1 << endl;
        for(int i = 0; i < n; i++) cout << 1 << " ";
        cout << endl;
    }
    else if(n%2 == 0 || (n%2 == 1 && arr.front() == arr.back()))
    {
        cout << 2 << endl;
        for(int i = 0; i < n; i++)
        {
            cout << i%2+1 << " ";
        }
        cout << endl;
    }
    else
    {
        int l = -1, r = -1;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] == arr[i-1])
            {
                l = i-1, r = i; break;
            }
        }
        if(l == -1)
        {
            cout << 3 << endl;
            cout << 3 << " ";
            for(int i = 1; i < n; i++) cout << i%2+1 << " ";
            cout << endl;
        }
        else
        {
            cout << 2 << endl;
            int color = 0;
            for(int i = 0; i < n; i++)
            {
                cout << color+1 << " ";
                if(i != l) color = 1-color;
            }
            cout << endl;
        }
    }
}

