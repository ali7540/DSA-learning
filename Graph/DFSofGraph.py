def dfsOfGraph(n, edges):
    graph = {i: [] for i in range(n)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    
    ans = []
    visited = [False] * n
    def dfs(i):
        ans.append(i)
        visited[i] = True
        for nei in graph[i]:
            if not visited[nei]:
                dfs(nei)
    
    for i in range(n):
        if not visited[i]:
            dfs(i)
    return ans
