//pB
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void process();

int main()
{
   ios::sync_with_stdio(false); cin.tie(0);
   process();
   cout.flush();
   return 0;
}

void process()
{
   ll a, b; cin >> a >> b;
   const ll md = 10;
   ll rem = 1;
   for(ll c = 0, n = a+1; c < 10 && n <= b; c++, n++)
   {
      rem = (rem*(n%md))%md;
   }
   cout << rem << endl;
}
