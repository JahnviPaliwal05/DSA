def ArrangePositiveNegative(seq):
    positives = []
    negatives = []
    

    for num in seq:
        if num >= 0:
            positives.append(num)
        else:
            negatives.append(num)
    
    result = []
    i = 0
    
  
    while i < len(positives) and i < len(negatives):
        result.append(positives[i])
        result.append(negatives[i])
        i += 1
    
  
    result.extend(positives[i:])
    result.extend(negatives[i:])
    
    return result


n = int(input('Enter length sequence: '))
seq = []

for i in range(n):
    a = int(input('Enter sequence numbers (Positive as well as negative): '))
    seq.append(a)

sc_max = ArrangePositiveNegative(seq)
print("Re-arranged array:", sc_max)