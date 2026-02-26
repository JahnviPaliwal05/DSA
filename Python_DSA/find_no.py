def find_no(seq):
    n = len(seq)
    missing = []
    for i in range(1,n+1):
        if i not in seq:
            missing.append(i)
    return missing

n = int(input('Enter length of sequence: '))
seq = []

for i in range(1,n):
    a = int(input('Enter sequence numbers: '))
    seq.append(a)

sc_max = find_no(seq)
print("The duplicate number is:", sc_max)