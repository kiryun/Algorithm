def POW(a, n, m):
    if n == 0:
        return 1
    return (a * (a + POW(a, n-1, m))) % m

a = input()
n = input()
m = input()

print(POW(a, n, m))