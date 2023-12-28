def max_goldbars():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    La, Ra, Lb, Rb = list(map(lambda x: int(x)-1, input().strip().split()))
    if Ra < Lb:
        return sum(A[i] for i in range((Ra+Lb)//2+1))
    if Rb < La:
        return sum(A[i] for i in range((Rb+La+1)//2, N))
    result, total, curr = 0, sum(A), sum(A[i] for i in range(max(La, Lb)))
    for i in range(max(La, Lb), min(Ra, Rb)+1):
        curr += A[i]
        if Lb <= i+1 <= Rb and Lb <= i-1 <= Rb:
            result = max(result, min(curr, total-(curr-A[i])))
        elif Lb <= i+1 <= Rb:
            result = max(result, curr)
        elif Lb <= i-1 <= Rb:
            result = max(result, total-(curr-A[i]))
    return result

answer=[]
for case in range(int(input())):
    answer.append(max_goldbars())
print("Answers")
for ans in answer:
    print(ans)
