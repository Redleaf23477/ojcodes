//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, h;
int low, high, q;

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
    cin >> n >> h >> low >> high >> q;
}

void process()
{
    while(q--)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) cout << abs(y1-y2) << endl;
        else if(low <= y1 && y1 <= high) cout << abs(x2-x1) + abs(y2-y1) << endl;
        else 
        {
            // low
            int path1 = abs(y1-low) + abs(x2-x1) + abs(y2-low);
            // high
            int path2 = abs(y1-high) + abs(x2-x1) + abs(y2-high);
            cout << min(path1, path2) << endl;
        }
    }
}

