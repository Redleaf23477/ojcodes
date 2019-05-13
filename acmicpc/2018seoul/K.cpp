#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int, int> P;
#define idx first
#define color second 

const int N = 100005, K = 5003;
const int R = 0, B = 1;

int n, k;
P input[N][3];
bool vis[2*K];
vector<int> arr[2][K]; // graph[color][pos] = {people}
vector<int> fail[2*K];   // 0~K-1 R, K~2K-1 B

void init()
{
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int idx; char ch; cin >> idx >> ch;
            input[i][j].idx = idx-1, input[i][j].color = (ch == 'R'? R : B);
            arr[input[i][j].color][input[i][j].idx].push_back(i);
        }
    }
    for(int i = 0; i < k; i++)
    {
        // i R
        int idx = i;
        for(auto x:arr[B][i])
        {
            for(int j = 0; j < 3; j++)
            {
                if(input[x][j].idx == i) continue;
                fail[idx].push_back(K*input[x][j].color + input[x][j].idx);
            }
        }

        // i B
        idx = K+i;
        for(auto x:arr[R][i])
        {
            for(int j = 0; j < 3; j++)
            {
                if(input[x][j].idx == i) continue;
                fail[idx].push_back(K*input[x][j].color + input[x][j].idx);
            }
        }
    }
}

bool poke(int idx)
{
    vis[idx] = true;
    for(auto x:fail[idx])
    {
        int oppo = (x >= K? x-K : x+K);
        if(vis[oppo]) 
        {
            vis[idx] = false;
            return false;
        }
        if(vis[x] == false)
        {
            if(poke(x) == false)
            {
                vis[idx] = false;
                return false;
            }
        }
    }
    return true;
}

void process()
{
    /*
       for(int i = 0; i < k; i++)
       {
       cout << i+1 << "R : ";
       for(auto x:fail[i])
       {
       if(x >= K) cout << x-K+1 << " B" << ", ";
       else cout << x+1 << " R" << ", ";
       }
       cout << endl;

       cout << i+1 << "B : ";
       for(auto x:fail[i+K])
       {
       if(x >= K) cout << x-K+1 << " B" << ", ";
       else cout << x+1 << " R" << ", ";
       }
       cout << endl;
       }
       */
    for(int i = 0; i < k; i++)
    {
        if(vis[i] || vis[i+K]) continue;

        if(poke(i) == false)  // i R
        {
            if(poke(i+K) == false)
            {
                cout << -1 << endl;
                return void();
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        if(vis[i] == true) cout << "R";
        else cout << "B";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); 
    init();
    process();
    cout.flush();
} 
