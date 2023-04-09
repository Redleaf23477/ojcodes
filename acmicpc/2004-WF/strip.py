import sys

M = int(sys.argv[1])

while True:
    n = int(input())
    if n == 0:
        break
    if n == M:
        print(n)
    for _ in range(n):
        data = input()
        if n == M:
            print(data)

print(0)
