//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
   ios::sync_with_stdio(false); cin.tie(0);
   int T; cin >> T;
   while(T--)
   {
      process();
   }
   cout.flush();
   return 0;
}

void init()
{
}

void process()
{
   int x; cin >> x;
   bool flg = false;
   for(int a = 0; a <= x/3 && !flg; a++)
   {
      if((x-3*a)%7 == 0) flg = true;
   }
   if(flg) cout << "YES" << endl;
   else cout << "NO" << endl;
}

