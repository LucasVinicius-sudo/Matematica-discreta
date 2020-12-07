import sys
def creatarqkey(n,e,p,q):#criando a chave publuica
    try:
        file = open("Keypublic.txt","w")
        file.write(str(n))
        file.write("")
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

def main():#funcao principal pedindo o p,q,e

    print("Digite o numero p")
    p = int(input())
    print("Digite o numeor q")
    q = int(input())
    print("Digite o Numero e")
    e = int(input())
    n = p*q
    if prime(p) == 0 or prime(q) == 0:
        print("Um dos numeros digitados não é primo")
    elif n < 26:
        print("O N tem que ser maior que 26")
    elif mdc((p-1)*(q-1),e) ==1:

        print("O e não é coprimo")
    else:
        creatarqkey(n,e,p,q)
        print("Chave publica gerada com sucesso")



main()
