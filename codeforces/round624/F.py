# BIT
def add(bit, x, v):
    while x < len(bit):
        bit[x] += v
        x += x & (-x)

def query(bit, x):
    ans = 0
    while x > 0:
        ans += bit[x]
        x -= x & (-x)
    return ans
def relabel(arr):
    srt = sorted(set(arr))
    mp = {v:k for k, v in enumerate(srt, 1)}
    arr = [mp[a] for a in arr]
    return arr
# main
n = int(input())
x = list(map(int, input().split()))
v = relabel(list(map(int, input().split())))
arr = sorted(list(zip(x, v)));
ans = 0
bitSum = [0]*(n+1)
bitCnt = [0]*(n+1)
for x, v in arr:
    ans += query(bitCnt, v)*x - query(bitSum, v)
    add(bitSum, v, x)
    add(bitCnt, v, 1)
print(ans)

