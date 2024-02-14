def fac(b):
    if b == 1:
        return 1
    else:
        return b * fac(b - 1)


def combinations(n, k):
    result = (fac(n)) / (fac(k) * fac(n - k))
    return result


n = 10
k = 2

print(combinations(n, k))
