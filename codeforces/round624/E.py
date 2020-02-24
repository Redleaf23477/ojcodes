def solve():
    vn, D = list(map(int, input().split()))
    if D > vn*(vn-1)//2:
        print("NO")
        pass
    dsum = 0
    pa = [0]*vn
    tree = []
    cursor = []
    # build complete binary tree
    d = 0
    use = 0
    while use < vn:
        thisLv = min(1<<d, vn-use)
        tmp = []
        for i in range(thisLv):
            pa[use+i] = (use+i-1)//2
            tmp.append(use+i)
        tree.append(tmp)
        if thisLv > 1:
            cursor.append(d)
        use += thisLv
        dsum += d * thisLv
        d += 1
    # if D too small return false
    if D < dsum:
        print("NO")
        return
    # move until good
    while dsum < D:
        d = cursor[-1]
        v = tree[d][-1]
        tree[d].pop()
        if len(tree[d]) == 1:
            cursor.pop()
        if len(tree) == d+1:
            tree.append([])
        tree[d+1].append(v)
        if len(tree[d+1]) > 1:
            cursor.append(d+1)
        pa[v] = tree[d][len(tree[d+1])//2-1]
        dsum += 1
    print("YES")
    print(*list(map(lambda x : x+1, pa[1:vn])))


for _ in range(int(input())):
    solve()
