from collections import deque
def isCyclic(n, edges):
    # your code here
    graph = {i : [] for i in range(n)}
    indegree = [0] * n 
    for u, v in edges:
        graph[u].append(v)
        # graph[v].append(u)
        indegree[v] += 1 
    # print(indegree)
    
    q = deque([])
    for i in range(n):
        if indegree[i] == 0:
            q.append(i)

    visited = 0
    while q:
        node = q.popleft()
        visited += 1
        for nei in graph[node]:
            indegree[nei] -= 1
            if indegree[nei] == 0:
                q.append(nei)
    
    return visited != n
