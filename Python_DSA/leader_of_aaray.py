def leader(seq):
    leaders = []

    max_right = seq[-1]   
    leaders.append(max_right)

    for i in range(len(seq) - 2, -1, -1):
        if seq[i] > max_right:
            leaders.append(seq[i])
            max_right = seq[i]

    leaders.reverse()   
    return leaders


n = int(input('Enter length sequence: '))
seq = []

for i in range(n):
    a = int(input('Enter sequence numbers: '))
    seq.append(a)

sc_max = leader(seq)
print("Leaders:", sc_max)