# taking input of the number of testcases
t = int(input())
for _ in range(t):
    n, h = map(int, input().split())

    # taking input for the attack strikes
    a = list(map(int, input().split()))

    # setting limits for binary search between maximum limit and minimum limit for the value of poison damage (according to constraints)
    l, r = 1, 10**18
    while l <= r:
        m = (l + r) // 2
        s = m
        for i in range(n - 1):
            s += min(m, a[i + 1] - a[i])
        if s < h:
            l = m + 1
        else:
            r = m - 1
    print(r + 1)
