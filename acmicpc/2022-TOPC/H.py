N = int(input())
ans = 0
pw = 500000
while pw > 0:
    div = 6 ** pw
    while N > div:
        ans += pw
        N //= div
    pw //= 10
while N > 0:
    ans += 1
    N //= 6

if ans == 0:
    ans = 1
print(ans)

