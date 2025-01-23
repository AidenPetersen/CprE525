def sqrtIter(x, S: float) -> float:
    return 0.5 * (x + S/x)

def sqrt(num: float) -> float:
    x0 = 600
    x_next = x0
    while True:
        x_old = x_next
        x_next = sqrtIter(x_next, num)
        if abs(x_old - x_next) < 1.0e-14:
            break
    
    return x_next

# factorial
def factorial(x: int) -> int:
    acc = 1
    for i in range(1, x+1):
        acc *= i
    return acc

# e^x
def ex(x: float) -> float:
    acc = 1.0
    i = 1
    while True:
        acc_old = acc
        acc += (x**i) / float(factorial(i))
        if abs(acc - acc_old) < 1e-14:
            break
        i+=1
    return acc

# log
def ln(x: float) -> float:
    s = x
    i = 0
    while True:
        s_old = s
        s = s - 1 + x * ex(-s) 
        if abs(s - s_old) < 1e-14:
            break
    return s

print(ln(123))
