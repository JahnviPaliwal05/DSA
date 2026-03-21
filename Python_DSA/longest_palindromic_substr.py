def str_palindrome(string):
    if string[::-1]==string:
        return True
    else:
        False



def longest_palindromeic_subString(string):
    maximum =""
    for i in range(0,len(string)):
        for j in range(0,len(string)):
            if i<=j:
                temp=string[i:j]
                if str_palindrome(temp):
                    if len(temp)>len(maximum):
                        maximum = temp
    return maximum



strings = input("Enter any string to check It's longest palindromic substring:")
longest = longest_palindromeic_subString(strings)
print("\nLongest palindrome substring is :", longest,"\n")
