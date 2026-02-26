def second_largest(seq):
    list2 = []
    maximum1 = max(seq)
    for i in seq:
        list2.append(i)
        if i == maximum1:
            list2.pop(seq.index(i))

    return max(list2)

n = int(input('Enter length sequenece:'))
seq = []
for i in range(0,n):
    a = int(input('Enter sequenece numbers:'))
    seq.append(a)
    i+=1

sc_max = second_largest(seq)
print("Seconf max num",sc_max)
