
X = input()
l = len(X)

f = [1]
for n in range(1, l+1):
    f.append(f[-1] * 10)

for n in range(1, l+1):
    f[n] += f[n-1]

ans = 0
for i in range(l):
    n = int(X[i])
    t = l - i - 1
    ans += n * f[t]
print(ans)
