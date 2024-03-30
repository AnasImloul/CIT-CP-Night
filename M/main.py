import math


def calculate_missed_throws(N):
    probability_missed = 1 - 2/math.pi
    return round(N * probability_missed)


T = int(input())
for _ in range(T):
    N = int(input())
    result = calculate_missed_throws(N)
    print(result)
