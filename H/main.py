def parse_time(str_time):
    h, m = str_time.split(':')
    return int(h) * 60 + int(m)


def build_availability(schedules):
    available = [0 for _ in range(1440)]
    for schedule in schedules:
        start, end = map(parse_time, schedule.split('-'))
        available[start] += 1
        if end + 1 != 1440:
            available[end + 1] -= 1

    for i in range(1, 1440):
        available[i] += available[i - 1]

    return available


def is_possible(availability_a, availability_b):
    for i in range(1440 - 30):
        j = i
        while j <= i + 30 and j < 1440 and availability_a[j] and availability_b[j]:
            j += 1
        if j == i + 31:
            return True
    return False


def main():
    for _ in range(int(input())):
        n = int(input())
        availability_a = build_availability(input().split())
        m = int(input())
        availability_b = build_availability(input().split())
        print("YES" if is_possible(availability_a, availability_b) else "NO")


if __name__ == '__main__':
    main()