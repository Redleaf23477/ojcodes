for T in range(int(input())):
    print('Case #{}:'.format(T+1))
    N, M, K, S = map(int, input().split())
    P = list(map(int, input().split()))
    AP, BP, CP, DP = map(int, input().split())
    Q = list(map(int, input().split()))
    AQ, BQ, CQ, DQ = map(int, input().split())

    for i in range(K, N):
        P.append((AP*P[i-2] + BP*P[i-1] + CP) % DP + 1)
    for i in range(K, M):
        Q.append((AQ*Q[i-2] + BQ*Q[i-1] + CQ) % DQ + 1)

    P.sort(), Q.sort()


    print('P = ', P)
    print('Q = ', Q)
