def max_spanning_forest_prim(adj, nodes):  
    result = 0
    max_e = [0] * len(nodes)
    lookup = [False] * len(nodes)
    for _ in range(len(nodes)):
        u = -1
        for v in range(len(nodes)):
            if lookup[v]:
                continue
            if u == -1 or max_e[v] > max_e[u]:
                u = v
        lookup[u] = True
        result += max_e[u]
        for v in range(len(nodes)):
            if adj[nodes[u]][nodes[v]] > max_e[v]:
                max_e[v] = adj[nodes[u]][nodes[v]]
    return result

def checksum():
    N = int(input())
    A = [list(map(int, input().strip().split())) for _ in range(N)]
    B = [list(map(int, input().strip().split())) for _ in range(N)]
    R = list(map(int, input().strip().split()))
    C = list(map(int, input().strip().split()))

    total = 0
    adj = [[0] * (2 * N) for _ in range(2 * N)]
    nodes = set()
    for i in range(len(A)):
        for j in range(len(A[0])):
            if A[i][j] != -1:
                continue
            adj[i][j + N] = adj[N + j][i] = B[i][j]  
            nodes.add(i)
            nodes.add(j + N)
            total += B[i][j]
    return total - max_spanning_forest_prim(adj, list(nodes))
answer=[]
for case in range(int(input())):
    answer.append(checksum())
print("Answers")
for ans in answer:
    print(ans)
