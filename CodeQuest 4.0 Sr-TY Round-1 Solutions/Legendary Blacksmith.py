t = int(input())
answers = []

for _ in range(t):
    l = int(input())
    dp = [i for i in range(l + 2)]

    for i in range(2, l + 1):
        dp[i + 1] = min(dp[i] + 1, dp[i + 1])
        cur = dp[i] + 4

        for j in range(i + i, l + 1, i):
            cur += 2
            dp[j] = min(dp[j], cur)

    answers.append(dp[l])

print("Answers")
for ans in answers:
    print(ans)
