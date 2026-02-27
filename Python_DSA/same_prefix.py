def same_prefix(s1, s2, s3):
    strl=""
    for i in range(0,len(s1)):
        if s1[i] == s2[i]:
            if s2[i]==s3[i]:
                strl+=s1[i]
            else:
                break
        else:
            break
    return strl

s1 = input("Enter first string:")
s2 = input("Enter second string:")
s3 = input("Enter third string:")
strgi = same_prefix(s1,s2,s3)
print(strgi)