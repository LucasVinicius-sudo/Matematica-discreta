import sys
alphabet = {'A' : 2, 'B' : 3, 'C' : 4, 'D' : 5, 'E' : 6,'F' : 7, 'G' : 8, 'H' : 9, 'I' : 10, 'J' : 11, 'K' : 12, 'L' : 13, 'M' : 14, 'N' : 15, 'O' : 16, 'P' : 17, 'Q' : 18, 'R' : 19, 'S' : 20, 'T' : 21, 'U' : 22, 'V' : 23, 'W' : 24, 'X' : 25, 'Y' : 26, 'Z' : 27, ' ' : 28}
#Alfabeto para transformar


def creatarqkey(n,e,p,q):#criando a chave publuica
    try:
        file = open("Keypublic.txt","w")
        file.write(str(n))
        file.write(" ")
        file.write(str(e))
        file.close()
    except FileNotFoundError:
        print("Erro ao criar arquivo")


def prime(x):#Dizer se é primo ou não
    tot = 0
    for num in range(1,x+1):
        if x % num == 0:
            tot = tot + 1


    if(tot > 2):
        return 0#nao primo
    else:
        return 1#primo




def mdc(a,b):#funcao para calcular MDC maneira euclidiana

    if(a%b == 0):
        return b
    else:
        mdc(b,a%b)

def find_d(z,e,d):
    i = 1
    for i in range(100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000):
        if(i*e % z == 1):
            d = i
            return d
            break

def key():#funcao principal pedindo o p,q,e

    print("Digite o numero p")
    p = int(input())
    print("Digite o numeor q")
    q = int(input())
    print("Digite o Numero e")
    e = int(input())
    n = p*q
    z = (p-1)*(q-1)
    d = find_d(z,e,0)
    #print(d)
    if prime(p) == 0 or prime(q) == 0:
        print("Um dos numeros digitados não é primo")
    elif n < 26:
        print("O N tem que ser maior que 26")
    elif mdc((p-1)*(q-1),e) ==1:
        print("O e não é coprimo")
    elif(find_d(z,e,0))!= d:
        print("d não encontrado")
    else:
        creatarqkey(n,e,p,q)
        print("Chave publica gerada com sucesso")

#'''
def cript(msg,k1,k2):
    tamanho = len(msg)
    criptmsg = ""
    for i in range(tamanho):
        arr = msg[i]
        criptmsg += str(pow(alphabet[arr],k2,k1))
        if(i + 1 < tamanho):
            criptmsg += ' '
    try:
        x = criptmsg
        cript_file = open("Encripttext.txt","w")
        cript_file.write(criptmsg)
        cript_file.close()

        return x
    except FileNotFoundError:
        print("Não foi gerado o arquivo")
        return -1
        #'''
def descript(msg2,k1,k2):
    print(k2)
    print(k1)
    descriptmsg = str(pow(msg2,k2,k1))
    try:
        descript_file = open("Descripttxt.txt","w")
        descript_file.write(descriptmsg)
        descript_file.close()
        return 1
    except FileNotFoundError:
        print("Não foi gerado o arquivo")
        return -1



def init_cript():
    print("Digite a mensagem de texto a Encriptar")
    msg = input()
    print("Digite o primeiro numero do par da chave recebido anteriormente")
    k1 = int(input())
    print("Digite o segundo numero do par da chave recebido anteriormente")
    k2 = int(input())
    if(cript(msg,k1,k2)!=-1):
        print("Ok")



def init_descript():
    print("Digite o numero p")
    p = int(input())
    print("Digite o numeor q")
    q = int(input())
    print("Digite o Numero e")
    e = int(input())
    n = p*q
    z = (p-1)*(q-1)
    print("Digite a mensagem criptografada")
    mensagem = int(input())
    d = find_d(z,e,0)
    descript(mensagem,n,d)





def main():
    print("Digite um numero sobre o que vc deseja: 1-Gerar chave 2-Encriptar mensagem 3-Desencriptar")
    x = int(input())
    if(x == 1):

        key()
    elif(x == 2):
        print("Se deseja gerar uma chave digite a palavra 'key' , caso contrario ja tiver a chave digite a palavra direct")
        word = input()
        if(word == 'key'):
            key()
        elif(word == 'direct'):
            init_cript()


    elif(x == 3):
        init_descript()
main()
