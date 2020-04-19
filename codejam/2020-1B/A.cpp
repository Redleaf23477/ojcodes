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

ll _X, _Y; 
ll X, Y;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> _X >> _Y;
    X = abs(_X), Y = abs(_Y);
}

void process()
{
    if(X%2 == Y%2)
    {
        cout << "IMPOSSIBLE" << endl; return;
    }
    string ans;
    while(X || Y)
    {
        if(X == 1 && Y == 0)
        {
            ans.push_back(_X>0? 'E':'W');
            break;
        }
        else if(X == 0 && Y == 1)
        {
            ans.push_back(_Y>0? 'N':'S');
            break;
        }
        if(X%2 == 1)
        {
            if((X-1)/2%2 != Y/2%2)
            {
                ans.push_back(_X>0? 'E':'W');
                X = (X-1)/2;
                Y = Y/2;
            }
            else
            {
                ans.push_back(_X>0? 'W':'E');
                X = (X+1)/2;
                Y = Y/2;
            }
        }
        else
        {
            if((Y-1)/2%2 != X/2%2)
            {
                ans.push_back(_Y>0? 'N':'S');
                X = X/2;
                Y = (Y-1)/2;
            }
            else
            {
                ans.push_back(_Y>0? 'S':'N');
                X = X/2;
                Y = (Y+1)/2;
            }
        }
        /*
        if((X-1)%2 != 1 && (X-1)/2%2 != Y/2%2)
        {
            ans.push_back(_X>0? 'E':'W');
            X = (X-1)/2;
            Y = Y/2;
        }
        else if((Y-1)%2 != 1 && X/2%2 != (Y-1)/2%2)
        {
            ans.push_back(_Y>0? 'N':'S');
            X = X/2;
            Y = (Y-1)/2;
        }
        else if((X+1)%2 != 1 && (X+1)/2%2 != Y/2%2)
        {
            ans.push_back(_X>0? 'W':'E');
            X = (X+1)/2;
            Y = Y/2;
        }
        else if((Y+1)%2 != 1 && X/2%2 != (Y+1)/2%2)
        {
            ans.push_back(_Y>0? 'S':'N');
            X = X/2;
            Y = (Y+1)/2;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl; return;
        }
        */
    }
    cout << ans << endl;
}

