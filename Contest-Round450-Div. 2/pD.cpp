//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
const int N = 200010;
int n;
ll arr[N];
ll sum[N];
map<ll, ll> cnt;

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
   cin >> n;
   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   sum[n-1] = arr[n-1];
   for(int i = n-2; i >= 0; i--)
   {
      sum[i] = arr[i]+sum[i+1]; //sum[1~n]
   }
}

void process()
{
   ll tot = 0;
   cnt[arr[n-1]] = 1;
   for(int i = n-2; i >= 0; i--)
   {
      ll kill = 0, killcnt = 0;
      if(cnt.count(arr[i]+1) != 0) kill += cnt[arr[i]+1]*(arr[i]+1), killcnt += cnt[arr[i]+1];
      if(cnt.count(arr[i]) != 0) kill += cnt[arr[i]]*(arr[i]), killcnt += cnt[arr[i]];
      if(cnt.count(arr[i]-1) != 0) kill += cnt[arr[i]-1]*(arr[i]-1), killcnt += cnt[arr[i]-1];
//      cout << "i " << i << " kill " << kill << " killcnt " << killcnt << endl;
      tot += sum[i+1]-kill+(killcnt-n+1+i)*arr[i];
      
      if(cnt.count(arr[i]) == 0) cnt[arr[i]] = 0;
      cnt[arr[i]]++;
   }
   cout << tot << endl;
}

