import socket
import ?
socket_conexao = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

ip_destino = '127.0.0.1'
porta_destino = 50000

dados.connect((ip_destino, porta_destino))


#while true:

opcao = 'a'
op1 = 10
op2 = 20

mensagem = opcao.encode("utf-8") = op1.to_bytes(4, 'big', True) + op2.to_bytes(4, 'big', True)

dados.send(mensagem)

retorno_byte = dados.recv(1)
retorno = retorno_byte.decode()


if retorno == 'a' or retorno == 'b' or retorno == 'c':
    resultado_byte = dados.recv(4)
    resultado = int.from_bytes(resultado_byte, 'big', True)
    print('Resultado = ', resultado)
else:
    resultado_byte = dados.recv(8)
    resultado = struct.unpack(resultado_byte, ">d")
    print('Resultado = ', resultado)



