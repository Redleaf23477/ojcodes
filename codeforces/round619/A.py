T = int(input())
for t in range(T):
    a = input()
    b = input()
    c = input()
    ans = "YES"
    for i in range(len(a)):
        if not(a[i] == c[i] or b[i] == c[i]):
            ans = "NO"
    print(ans)
