//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
const int N = 2510;
int n, len;
bool valid;
string str[N];
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
   valid = true;
   cin >> n >> len;
   int used[26] = {0};
   cin >> str[0]; for(auto c:str[0]) used[c-'a']++;
   for(int i = 1; i < n; i++)
   {
      int tmp[26] = {0};
      cin >> str[i];
      for(auto c:str[i]) tmp[c-'a']++;
      for(int i = 0; i < 26; i++) if(used[i] != tmp[i]) valid = false;
   }
}

bool ok(const string &sa, const string &sb)
{
   int diff = 0;
   for(int i = 0; i < len; i++)
   {
      if(sa[i] != sb[i]) diff++;
      if(diff > 2) return false;
   }
   if(diff == 1) return false;
   return true;
}

void process()
{
   srand(9487+7122+time(NULL));
   int rd = (rand()%n+1)%n; if(rd == 0) rd++;
   string tocmp = str[rd];
   int diff = 0;
   vector<int> notsame;
   for(int i = 0; i < len; i++)
   {
      if(str[0][i] != tocmp[i]) 
      {
         diff++;
         notsame.push_back(i);
      }
      if(diff > 4) valid = false;
   }
   if(diff == 1) valid = false;
   if(!valid) 
   {
      cout << -1 << endl; return;
   }
   for(int a = 0; a < notsame.size(); a++)
   {
      for(int b = a+1; b < notsame.size(); b++)
      {
         int i = notsame[a], j = notsame[b];
         string test = str[0];
         char tmp = test[i]; test[i] = test[j]; test[j] = tmp;
         bool nice = true;
         for(int t = 1; t < n && nice; t++)
         {
            nice = ok(test, str[t]);
         }
         if(nice) 
         {
            cout << test << endl;
            return;
         }
      }
   }
   cout << -1 << endl;
}

