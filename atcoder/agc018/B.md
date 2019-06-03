# B - Sports Festival
from [agc018](https://atcoder.jp/contests/agc018/tasks)

## Observation

Initially, place everyone to their favorite sport.

Consider the case if we disable one sport, there will be 2 cases:

1. Disable the sport with maximum people : People in this sport will be distrubuted to their next favoirte sport.  Then we get a subproblem with **n-1** sports.

2. Disable a sport which doesn't have the maximum people : After distributing people in this sport, people in the sport with the most people will only increase.  Therefore we will not disable a sport that doesn't have maximum people.

When we split the problem into a subproblem with **n=1**, obviously there will be **N** people in the sport and this subproblem cannot be smaller.

## Implementation

1. Place everyone to their favorite sport.

2. Choose the sport with most people.  Record the number of people.

3. Disable this sport, distribute the people originally in this sport.

4. Do Step 2 again until we only have 1 sport left.

5. For all the people num we recorded, find the minimum and output

Time Complexity **O(nm + mm)**
