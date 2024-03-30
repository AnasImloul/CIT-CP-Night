from itertools import product


def longestIncreasingPath(matrix):
    n, m = len(matrix), len(matrix[0])

    memo = [[-1] * m for _ in range(n)]

    def dfs(y, x):
        if memo[y][x] != -1:
            return memo[y][x]

        memo[y][x] = 1
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            if y + dy >= n or y + dy < 0:
                continue
            if x + dx >= m or x + dx < 0:
                continue
            if matrix[y + dy][x + dx] <= matrix[y][x]:
                continue
            memo[y][x] = max(memo[y][x], 1 + dfs(y + dy, x + dx))

        return memo[y][x]

    return max(dfs(r, c) for r, c in product(range(n), range(m)))


def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        matrix = [list(map(int, input().split())) for _ in range(n)]
        result = longestIncreasingPath(matrix)
        print(result)


if __name__ == "__main__":
    main()
