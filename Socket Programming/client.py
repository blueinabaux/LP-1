import socket
import threading

SERVER_IP = '127.0.0.1'
HOST = 5000

def recieve_message(client_socket):
    
    while True:
        try:
            message = client_socket.recv(1024)
            print(message.decode())
        except:
            print("Connection with server is closed !")
            client_socket.close()
            break

def main():

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((SERVER_IP, HOST))

    recieve_thread = threading.Thread(target=recieve_message, args=(client, ))
    recieve_thread.start()

    while True:
        message =  input("Enter a message: ")
        if(message.lower() == "quit"):
            break
        client.send(message.encode())
    client.close()

if __name__ == '__main__':
    main()