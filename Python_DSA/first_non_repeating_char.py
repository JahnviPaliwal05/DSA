def NonRepeatingChar(strings):
    Num = ''
    for i in range(0,len(strings)):
        count = 0
        for j in range(0,len(strings)):
            if i!=j:
                if strings[j]!= strings[i]:
                    count+=1
                else:
                    break
        
        if count == len(strings)-1:
            Num = strings[i]
            break
    print("The character is :",Num)

   
state = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
NonRepeatingChar(state)