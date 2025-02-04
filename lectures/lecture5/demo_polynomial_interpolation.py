import numpy as np


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

# Matching Pairs
xs = [-0.1, -0.02, 0.02, 0.1]
A = np.array([[x**(3 - p) for p in range (0, 4)] for x in xs])
b = np.array([np.cos(x) for x in xs])

result = GaussElimination(A, b)
expected = np.linalg.solve(A, b)
print("A:")
print(A)
print("b:")
print(b)
print("My solution:")
print(result)
print("Numpy solution:")
print(expected)
