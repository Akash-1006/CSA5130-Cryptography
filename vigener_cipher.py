s=input("Enter a string")
key=input("Enter the key")
key=key.upper()
s=s.upper()
string=""
string1=""
ki=0
print(key)
length=len(key)
print(length)
for char in s:
    key_char=key[ki%length]
    ki+=1
    res=chr((ord(char)-65+ord(key_char))%26+65)
    string+=res
    
print("Encrypted Msg "+string)
ki=0
for char in string:
    key_char=key[ki%length]
    ki+=1
    res=chr((ord(char)-65-ord(key_char))%26+65)
    string1+=res
print("Decrypted Msg "+string1)
