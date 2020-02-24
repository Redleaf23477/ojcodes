T = int(input())
for t in range(T):
    n, m = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    swp = list(map(int, input().split()))
    # weird bubble sort
    for mm in range(m):
        for pos in swp:
            if arr[pos] < arr[pos-1]:
                arr[pos], arr[pos-1] = arr[pos-1], arr[pos]
    if sorted(arr) == arr:
        print("YES")
    else:
        print("NO")
