import numpy as np
import matplotlib.pyplot as mat

def GaussElimination(A, b):
    n = len(b)

    # Create augmented matrix
    augmented_matrix = np.hstack((A, b.reshape(n, 1)))

    # Forward Elimination
    for i in range(n):
        # Swap rows to get the largest pivot element
        max_row = np.argmax(np.abs(augmented_matrix[i:, i])) + i
        augmented_matrix[[i, max_row]] = augmented_matrix[[max_row, i]]

        # Check if the pivot is zero (matrix is singular)
        if np.abs(augmented_matrix[i, i]) < 1e-12:
            raise ValueError("Matrix is singular")

        # Eliminate all entries below the pivot
        for j in range(i + 1, n):
            factor = augmented_matrix[j, i] / augmented_matrix[i, i]
            augmented_matrix[j, i:] -= factor * augmented_matrix[i, i:]

    # Back Substitution
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (augmented_matrix[i, -1] - np.dot(augmented_matrix[i, i+1:n], x[i+1:])) / augmented_matrix[i, i]

    return x

# Computes value for x from polynomial from coefficients
def polynomial(x, coeff):
    return sum([coeff[i] * x**i for i in range(len(coeff))])

def LeastSquareApprox(x, f, n):
    X = np.column_stack([x**i for i in range(n + 1)])
    XT = X.T
    XT_X = XT @ X
    XT_X_inv = np.linalg.inv(XT_X)
    XT_f = XT @ f
    coeff = XT_X_inv @ XT_f

    print(f"Coefficients of polynomial: {coeff}")
    return coeff

xs = np.linspace(-np.pi, np.pi, 51)
ys = np.cos(xs)

poly = LeastSquareApprox(xs, ys, 5)

poly_ys = [polynomial(x, poly) for x in xs]
mat.title("Cos vs Cos approx")
mat.plot(xs, ys)
mat.scatter(xs, poly_ys)
mat.savefig("cosvapprox.png")
