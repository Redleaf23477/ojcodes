from itertools import permutations


ns_per_s = 10**9
s_per_hr = 3600
s_per_min = 60
min_per_hr = 60
tick_per_round = 12 * 360 * 10**10

def extgcd(a, b):
    d = a
    if b != 0:
        d, y, x = extgcd(b, a%b)
        y -= a // b * x
    else:
        x, y = 1, 0
    return d, x, y

def mod_inverse(a, m):
    d, x, y = extgcd(a, m)
    return (m + x % m) % m

def run(arr):
    for p in permutations(arr):
        rot = (12 * p[0] % tick_per_round - p[1] + tick_per_round) % tick_per_round * mod_inverse(11, tick_per_round) % tick_per_round
        ns = (p[0] - rot + tick_per_round) % tick_per_round
        _ns = ns % ns_per_s
        ns -= _ns

        h = ns // ns_per_s // s_per_hr
        m = ns // ns_per_s // s_per_min % min_per_hr
        s = ns // ns_per_s % s_per_min

        m2 = ((p[1] - rot - _ns * 12) % tick_per_round + tick_per_round) % tick_per_round // (12 * ns_per_s) // s_per_min % min_per_hr
        s2 = ((p[2] - rot - _ns * 720) % tick_per_round + tick_per_round) % tick_per_round // (720 * ns_per_s) % s_per_min

        if m != m2: continue
        if s != s2: continue

        return h, m, s, _ns
    return -1, -1, -1, -1

for t in range(int(input())):
    arr = sorted(list(map(int, input().split())))
    ans = run(arr)
    print("Case #{}:".format(t+1), *ans)


