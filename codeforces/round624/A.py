T = int(input())
for t in range(T):
    a, b = list(map(int, input().split()))
    diff = b-a
    if diff == 0:
        print(0)
    elif diff < 0:
        if diff % 2 == 0:
            print(1)
        else:
            print(2)
    else:
        if diff % 2 == 1:
            print(1)
        else:
            print(2)

