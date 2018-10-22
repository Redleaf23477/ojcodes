//
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

const double g = 10;

int n;
double h, r, t;

void init();
void process();

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    scanf("%d %lf %lf %lf", &n, &h, &r, &t);
    r /= 100.0;
}

void process()
{
    vector<double> pos;
    for(int i = 0; i < n; i++)
    {
        double startingHeight = h;
        if(t <= i) 
        {
            pos.push_back(startingHeight);
            continue;
        }
        double dropDuration = sqrt(2.0*startingHeight/g);
        double maxVelocity = sqrt(2.0*g*startingHeight);
        double movingTime = t-i;
        int turns = movingTime/dropDuration;
        double finalMovingTime = movingTime - dropDuration*turns;
        bool direction = turns%2; // 0: falling ,1: rising
        if(direction == 0) // falling from startingHeight
        {
            pos.push_back(startingHeight - 0.5*g*finalMovingTime*finalMovingTime);
        }
        else // rising from ground
        {
            pos.push_back(maxVelocity*finalMovingTime - 0.5*g*finalMovingTime*finalMovingTime);
        }
    }
    sort(pos.begin(), pos.end());
    for(int i = 0; i < n; i++) printf("%.2lf%c", pos[i]+i*2*r, " \n"[i==n-1]);
}

