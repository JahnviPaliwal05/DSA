def ReverseWords(string):
    ls = list(string.split(" "))
    strnew = ""
    for i in ls:
        strnew+=i[::-1]
        strnew+=" "
    return strnew

sent = input("Enter a sentence:")
rev_sent = ReverseWords(sent)
print("The string with reversed words are:",rev_sent)