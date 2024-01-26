


def isFibonacciNumber(n):
    a, b = 0, 1
    while b < n:
        a, b = b, b + a 
    
    return b == n

print(isFibonacciNumber(10))
