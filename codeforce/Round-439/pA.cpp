//pA
int n;
int arra[2000], arrb[2000];
map<int, bool> mp;

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
   for(int i = 0; i < n; i++) cin >> arra[i], mp[arra[i]] = true;
   for(int i = 0; i < n; i++) cin >> arrb[i], mp[arrb[i]] = true;
}

void process()
{
   ll cnt = 0;
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
      {
         int xn = arra[i]^arrb[j];
         if(mp.count(xn) != 0) 
         {
//            cout << "(" << i << "," << j << ")" << endl;
            cnt++;
         }
      }
   }
//   cout << cnt << endl;
   if(cnt%2==0) cout << "Karen" << endl;
   else cout << "Koyomi" << endl;
}
