import math

def sqrtIter(x, S: float) -> float:
    return 0.5 * (x + S/x)

# Takes the square root of a number using iterative method
# Uses sqrtIter as a helper function to perform one iteration
def sqrt(num: float) -> float:
    x0 = 600
    x_next = x0
    while True:
        x_old = x_next
        x_next = sqrtIter(x_next, num)
        # Checks that algorithm is complete if previous round is less than delta
        if abs(x_old - x_next) < 1.0e-14:
            break
    
    return x_next

# factorial
def factorial(x: int) -> int:
    acc = 1
    # Multiplies each iteration index
    for i in range(1, x+1):
        acc *= i
    return acc

# e^x
def exp(x: float) -> float:
    acc = 1.0
    i = 1
    # Implements e^x taylor series estimation:
    # 1 + x + x^2/2 + x^3/6 + ...
    while True:
        acc_old = acc
        acc += (x**i) / float(factorial(i))
        if abs(acc - acc_old) < 1e-14:
            break
        i+=1
    return acc

def ln(x: float) -> float:
    s = x
    i = 0
    # Implements ln(x) taylor series estimation:
    # Sum_k=1->inf((-1)^k(-1 + x)^-k/k)
    while True:
        s_old = s
        s = s - 1 + x * exp(-s) 
        if abs(s - s_old) < 1e-14:
            break
    return s

print(f"sqrt(10): Expected: {math.sqrt(10)} Implementation: {sqrt(10)}")
print(f"factorial(10): Expected: {math.factorial(10)} Implementation: {factorial(10)}")
print(f"ex(3): Expected: {math.exp(3)} Implementation: {exp(3)}")
print(f"ln(3): Expected: {math.log(3, math.e)} Implementation: {ln(3)}")
