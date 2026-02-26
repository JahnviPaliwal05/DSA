def removeDuplicate(seq):
    if len(seq) == 0:
        return []

    list2 = [seq[0]]  

    for i in range(1, len(seq)):
        if seq[i] != seq[i - 1]:
            list2.append(seq[i])

    return list2


n = int(input('Enter length sequence: '))
seq = []

for i in range(n):
    a = int(input('Enter sorted sequence numbers: '))
    seq.append(a)

sc_max = removeDuplicate(seq)
print("All duplicates removed:", sc_max)