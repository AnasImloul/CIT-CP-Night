from math import pi


def calculate_missed_throws(n):
    probability_missed = 1 - 2 / pi
    return round(n * probability_missed)


for _ in range(int(input())):
    n = int(input())
    result = calculate_missed_throws(n)
    print(result)
