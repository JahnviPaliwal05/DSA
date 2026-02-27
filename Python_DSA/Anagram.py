"""Anagram is a word or phrase that is made by arranging the letters of another word or phrase in a different order"""

def IfAnagram(s1,s2):
    truelist = []
    visited = []
    for i in s1:
        if i not in visited:
            if i in s2:
                truelist.append(1)
                visited.append(i)
            else:
                truelist.append(0)
                visited.append(i)
    # print(truelist)
    if len(truelist) == len(s1):
        if 0 in truelist:
            return False
        else:
            return True
    else:
        return False
    
    

s1 = input("Enter 1st string:")
s2 = input("Enter 2nd string:")

print(IfAnagram(s1,s2))


            
        
        