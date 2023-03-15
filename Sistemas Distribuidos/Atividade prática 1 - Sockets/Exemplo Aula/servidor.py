import socket

def tratamento_cliente(socket_dados):
    funcao = (socket_dados.recv(1)).decode()
    op1 = int.from_bytes((socket_dados.recv(4)),"big", True)
    op2 = int.from_bytes((socket_dados.recv(4)),"big", True)
    if(funcao == 'a'):
        resultado = op1 + op2
    elif(funcao == 'b'):
        resultado = op1 - op2
    elif(funcao == 'c'):
        resultado = op1 * op2
    else:
        resultado = op1 / op2

    if (funcao in ('a', 'b', 'c')):
        resposta = funcao.encode() + resultado.to_bytes(4, "big", True)
    else:
        

socket_conexao = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

ip = '127.0.0.1'
porta = 50000

destino = (ip, porta)
socket_conexao.bind(destino)

while True:
    socket_conexao.listen(1)

    socket_dados, info_cliente = socket_conexao.accept()

    tratamento_cliente(socket_dados)

    
    

