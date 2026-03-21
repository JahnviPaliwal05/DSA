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
    

def groupAnagrams(ls):
    temp_list = []
    for i in ls:
        for j in range(ls.index(i)+1,len(ls)):
            if IfAnagram(i,ls[j]):
                temp_var = [i,ls[j]]
                temp_list.append(temp_var)
            
    return temp_list

list1 = ["abc", "bca", "cab"]
longest = groupAnagrams(list1)
print("\nGropus of angrams:", longest,"\n")
