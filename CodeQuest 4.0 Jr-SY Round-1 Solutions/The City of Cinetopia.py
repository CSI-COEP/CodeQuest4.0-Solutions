t = int(input())
for _ in range(t):
    n, m, d = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    s = set()
    cur_sum = 0

    for i in range(n):
        cur = cur_sum + a[i] - d * (i + 1)
        ans = max(ans, cur)

        if a[i] > 0:
            s.add((a[i], i))
            cur_sum += a[i]

            if len(s) >= m:
                cur_sum -= min(s)[0]
                s.remove(min(s))

    print(ans)