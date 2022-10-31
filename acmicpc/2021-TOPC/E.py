def sum5(D):
    return (2 * D**6 + 6 * D**5 + 5 * D**4 - D**2) // 12

def get_day(p, q):
    for d in range(1, 100):
        if q * sum5(d) >= p * d: 
            return d
    return 48763

def get_x(p, q):
    D = get_day(p, q)
    x = p * D - sum5(D-1) * q
    return x

def ok(y, x, p, q):
    return x - p * y + q * sum5(y) >= 10**99

def get_y(x, p, q):
    low = 0
    high = 10**20
    ans = 0
    while low <= high:
        mid = (low + high) // 2
        if ok(mid, x, p, q):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

if __name__=='__main__':
    p, q = map(int, input().split())
    x = get_x(p, q)
    y = get_y(x, p, q)
    print(x, y)
