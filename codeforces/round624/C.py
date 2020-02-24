for _ in range(int(input())):
    n, m = list(map(int, input().split()))
    s = input()
    seq = list(map(int, input().split()))
    for c in range(0, 26, 1):
        pre = [0]*(n+1)
        for i in range(0, n, 1):
            if ord(s[i])-ord('a') == c:
                pre[i+1] = 1
        for i in range(1, n+1, 1):
            pre[i] += pre[i-1]
        ans = pre[n]
        for x in seq:
            ans += pre[x]
        print(ans, end=" ")
    print("")
