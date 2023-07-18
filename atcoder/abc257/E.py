N = int(input())
C = list(map(int, input().split()))

dp = [0] * (N + 1)

for i in range(N, 0, -1):
    for c in range(1, 10, 1):
        if i - C[c - 1] >= 0:
            dp[i - C[c - 1]] = max(dp[i - C[c - 1]], dp[i] * 10 + c);

print(dp[0])
