//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll hp1, atk1, p1;
ll hpm, atkm;

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
   cin >> hp1 >> atk1 >> p1 >> hpm >> atkm;
}

void process()
{
   ll curhp = hp1;
   queue<char> log;
   while(hpm > 0)
   {
      if(atk1 >= hpm)
      {
         log.push('S');
         hpm -= atk1;
         break;
      }
      if(curhp > atkm)
      {
         log.push('S');
         hpm -= atk1;
      }
      else
      {
         log.push('H');
         curhp += p1;
      }
      curhp -= atkm;
   }
   cout << log.size() << endl;
   while(!log.empty())
   {
      char ch = log.front(); log.pop();
      if(ch == 'S') cout << "STRIKE" << endl;
      else cout << "HEAL" << endl;
   }
}

