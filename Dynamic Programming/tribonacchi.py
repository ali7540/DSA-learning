def tri(n):
    # Write your code here
    if n < 2:
        return n 
    if n == 2:
        return 1 
    
    a, b, c = 0, 1, 1
    for _ in range(3, n + 1):
        s = a + b + c 
        a, b, c = b, c, s 

    return c
