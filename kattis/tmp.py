s = input()

ans = s
for i in range(1, len(s)-1):
    for j in range(i+1, len(s)):
        tmp = reversed(s[:i])+reversed(s[i:j])+reversed(s[j:])
        if tmp < ans: ans = tmp
print(ans)
