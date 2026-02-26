def Merge_sorted_arr(seq1, seq2):
    seq3 = []
    for i in range(0,len(seq2)):
        seq1.append(seq2[i])
    seq1 = sorted(seq1)
    return seq1
    



n = int(input('Enter length sequence 1: '))
seq1 = []

for i in range(n):
    a = int(input('Enter sorted sequence numbers: '))
    seq1.append(a)

n2 = int(input('Enter length sequence 2: '))
seq2 = []

for i in range(n2):
    a2 = int(input('Enter sorted sequence numbers: '))
    seq1.append(a2)

sc_max = Merge_sorted_arr(seq1,seq2)
print("All Merged:", sc_max)