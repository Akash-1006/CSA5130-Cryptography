s=input("Enter a string")
key=int(input("ENter eh key"))
s=s.upper()
string=""
string1=""

for char in s:
    res=chr(ord(char)+key)
    if ord(res)>90:
        res=chr(ord(res)-26)
    string+=res
    
print("Encrypted Msg "+string)
for char in string:
    res=chr(ord(char)-key)
    if ord(res)<65:
        res=chr(ord(res)+26)
    string1+=res

print("Decrypted Msg "+string1)
