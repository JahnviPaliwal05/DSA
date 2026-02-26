seq = int(input("Enter Number to find its factorial:"))
prod = 1
for i in range(1,seq+1):
    prod = i*prod
print("Value of factorial of number", seq, "is", prod)

