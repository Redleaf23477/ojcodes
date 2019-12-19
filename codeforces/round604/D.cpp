//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define num first
#define cnt second

queue<P> q, tmp;

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
    for(int i = 0; i < 4; i++)
    {
        int x; cin >> x;
        if(x > 0) 
        { 
            q.emplace(i, x);
//            cout << i << " " << x << endl;
        }
    }
    tmp = q;
}

void run(bool fs_first, bool &good, vector<int> &buff)
{
    P fs = q.front(), fb;
    q.pop();
    while(!q.empty())
    {
        if(fs.cnt == 0) { fs = q.front(); q.pop(); }
        if(q.empty()) break;
        fb = q.front(); q.pop();
//        cout << "fs = (" << fs.num << ", " << fs.cnt << ")" << endl;
//        cout << "fb = (" << fb.num << ", " << fb.cnt << ")" << endl;
        if(fs.num != fb.num-1) { good = false; break; }
        if(buff.empty())
        {
            // try fs first
            if(fs_first)
            {
                while(fb.cnt > 0 && fs.cnt > 0)
                {
                    buff.push_back(fs.num);
                    buff.push_back(fb.num);
                    fb.cnt--, fs.cnt--;
                }
            }
            // try fb first
            else
            {
                while(fb.cnt > 0 && fs.cnt > 0)
                {
                    buff.push_back(fb.num);
                    buff.push_back(fs.num);
                    fb.cnt--, fs.cnt--;
                }
            }
        }
        else
        {
            if(buff.back() == fs.num)
            {
                while(fb.cnt > 0 && fs.cnt > 0)
                {
                    buff.push_back(fb.num);
                    buff.push_back(fs.num);
                    fb.cnt--, fs.cnt--;
                }
            }
            else
            {
                while(fb.cnt > 0 && fs.cnt > 0)
                {
                    buff.push_back(fs.num);
                    buff.push_back(fb.num);
                    fb.cnt--, fs.cnt--;
                }
            }
        }
//        cout << "fs = (" << fs.num << ", " << fs.cnt << ")" << endl;
//        cout << "fb = (" << fb.num << ", " << fb.cnt << ")" << endl;
//        cout << "---" << endl;
        if(fs.cnt == 0) fs = fb;
    }
    if(!buff.empty() && fs.cnt > 0 && (fs.num != buff.back()+1 && fs.num != buff.back()-1)) good = false;
    if(good == false) return;
    if(fs.cnt == 0) return;
    if(fs.cnt == 1 && buff.back() != fs.num) { buff.push_back(fs.num); return; }
    good = false;
}

void process()
{
    if(q.size() == 0) { cout << "NO" << endl; return; }
    if(q.size() == 1)
    {
        P f = q.front(); q.pop();
        if(f.cnt == 1)
        {
            cout << "YES" << endl;
            cout << f.num << endl;
            return;
        }
        else
        {
            cout << "NO" << endl; return;
        }
    }
    bool good = true;
    vector<int> buff;

    run(true, good, buff);
    if(good == false)
    {
        good = true;
        buff.clear();
        q = tmp;
        run(false, good, buff);
    }

    if(good)
    {
        cout << "YES" << endl;
        for(auto x : buff) cout << x << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
}

