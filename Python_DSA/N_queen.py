def Place(k, i):
    for j in range(1, k):
        if x[j] == i or abs(x[j] - i) == abs(j - k):
            return False
    return True


def NQueen(k, n):
    while k > 0:
        x[k] += 1

        while x[k] <= n and not Place(k, x[k]):
            x[k] += 1

        if x[k] <= n:
            if k == n:
                print("Solution:", x[1:n+1])
            else:
                k += 1
                x[k] = 0
        else:
            x[k] = 0
            k -= 1


# Main
n = 4
x = [0] * (n + 1)
NQueen(1, n)

