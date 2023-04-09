def solve():
    n, M = map(int, input().split())
    ans, acc, s = -10**18, 0, 0
    for _ in range(n):
        # best
        val, cnt = map(int, input().split())
        ans = max(ans, s + val)
        if acc > 0 and acc + val * cnt < 0:
            d = -1 * acc // val
            ans = max(ans, s + acc * d + val * (1 + d) * d // 2)
        # end
        s += acc * cnt + val * (1 + cnt) * cnt // 2
        acc += val * cnt
        ans = max(ans, s)
    print(ans)

for __ in range(int(input())):
    solve()
