import socket
import time
import pyautogui

HOST = "10.2.218.179"  # pc private ip
PORT = 50000    
print("Server started at this IP:", HOST)
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

conn1, addr1 = s.accept()
print(addr1)
m=20
#conn1.sendall(b'start') # data1 = conn1.recv(1).decode("utf-8")
while 1:
    print(conn1.recv(1024).decode("utf-8"))
    data=input("Send a message to esp8266:")
    conn1.sendall(data.encode("utf-8"))
    conn1.sendall("!".encode("utf-8"))
    

