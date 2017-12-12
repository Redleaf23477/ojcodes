//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 5010;
int n;
int arr[N];
int box[N];

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
   int idx = 0;
   map<int, int> mp;
   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   sort(arr, arr+n);
   for(int i = 0; i < n; i++)
   {
      if(mp.count(arr[i]) == 0) mp[arr[i]] = 0;
      mp[arr[i]] = idx++;
   }
   for(int i = 0; i < n; i++)
   {
      arr[i] = mp[arr[i]];
      box[arr[i]]++;
   }
}

void process()
{
   int accu = box[0];
   for(int i = 1; i < N; i++)
   {
      accu -= box[i]; if(accu < 0) accu = 0;
      accu += box[i];
   }
   cout << accu << endl;
}

