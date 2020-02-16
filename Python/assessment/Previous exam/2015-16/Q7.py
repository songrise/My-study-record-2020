"""
Base cases:
- newFib(0) = 0
- newFib(1) = 1
- newFib(2) = 1

Inductive step: 
For n > 2, we have
- newFib(n) = newFib(n-1) + the number of pairs born in n-2
- newFib(n) = newFib(n-1) + newFib(n-2) – newFib(n-3).
Therefore, newFib(n) = newFib(n-1) + newFib(n-2) - newFib(n-3).

Alternatively,
Base cases: newFib(0) = 0, newFib(1) = 1.
Inductive step: For n > 1, newFib(n) = newFib(n-2) + 1.
"""
