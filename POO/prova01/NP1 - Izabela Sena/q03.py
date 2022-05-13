from moduloq03 import BatimentosCardiacos

def LINHA(type = "*",size = 40):
    print(type*size)

def MENU(opçoes):
    cont = 1
    LINHA()
    for op in opçoes:
        print(f"[{cont}]- {op}")
        cont += 1
    LINHA()

def MENU_DE_DADOS(operacao):
    opdados = []
    LINHA("-")
    print("TIPOS DE DADOS".center(40))
    MENU(["NOME","SOBRENOME","DATA DE NASCIMENTO"])
    print(f"+ Qual/quais dados deseja {operacao}:")
    i = 1
    while True:
        if i == 4 :
            break
        a = str(input(f"OPÇÃO {i}: [S/N] ")).upper()
        if a in "SN":
            if a == "S":
                opdados.append("S")
            else:
                opdados.append("N")
            i += 1
        else:
            print("ERRO, DIGITE 'S' OU 'N'")
    LINHA("-")
    return opdados

def REGISTRAR(nome,Pessoas):
    sobrenome = str(input("+ Digite o sobrenome: ")).upper()
    dataDeNasc = str(input("+ Digite data de nascimento: [EX: 1/1/2021] -> "))
    dataDeNasc = dataDeNasc.rsplit("/")
    dataNasc = [int(dataDeNasc[0]),int(dataDeNasc[1]),int(dataDeNasc[2])]
    new = BatimentosCardiacos(nome,sobrenome,dataNasc)
    Pessoas.append(new)
    return Pessoas

def MANIPULAR(Pessoas,cont):
    while True:
        LINHA()
        print("OPERAÇÕES DISPONIVEIS".center(40))
        MENU(["Idade Pessoa","Frequência Cardiaca Maximo","Frequência Cardiaca-Alvo"])
        op = int(input("- Qual opção deseja: "))
        if op > 3 or op < 1:
            print("Opção invalida!")
        else:
            if op == 1:
                idade = Pessoas[cont].CalculaIdade()
                print(f"{Pessoas[cont].nome.capitalize()} {Pessoas[cont].sobrenome.capitalize()} tem {idade} anos")
            
            elif op == 2:
                Fcm = Pessoas[cont].FrequenciaMaxima()
                print(f"A frequência Cardiaca maxima de {Pessoas[cont].nome.capitalize()} {Pessoas[cont].sobrenome.capitalize()} é de {Fcm} batimentos por minutos.")
            
            else:
                minimo, maximo = Pessoas[cont].FrequenciaAlvo()
                print(f"A frequência cardiaca-alvo de {Pessoas[cont].nome.capitalize()} {Pessoas[cont].sobrenome.capitalize()} está em um intervalo de {minimo:.2f} a {maximo:.2f} batimentos por minuto.")
            return Pessoas

def DADOS_EXISTENTES(Pessoas,cont):
    while True:
        AorR = int(input("+ DESEJA:".center(40)+"\n[1] Atualizar dado.\n[2] Visualizar dado\n-- "))
        if AorR > 2 or AorR < 1:
            print("+ Opção invalido, digite novamente!\n")
            LINHA("-")
        else:
            if AorR == 2:
                opdados = MENU_DE_DADOS("visualizar")
            elif AorR == 1:
                opdados = MENU_DE_DADOS("atualizar")

            for i in range(3):
                if opdados[i] == "S":
                    if i == 0:
                        if AorR == 2:
                            print(f"NOME DA PESSOA: {Pessoas[cont].nome.upper()}")
                        else:
                            Nnome = str(input("+ NOVO NOME: ")).upper()
                            Pessoas[cont].nome = Nnome
                    elif i == 1:
                        if AorR == 2:
                            print(F"SOBRENOME DE {Pessoas[cont].nome.upper()}: {Pessoas[cont].sobrenome.upper()}")
                        else:
                            Ncod = str(input(F"+ NOVO SOBRENOME DE {Pessoas[cont].nome.upper()}: ")).upper()
                            Pessoas[cont].sobrenome = Ncod
                    elif i == 2:
                        if AorR == 2:
                            print(F"DATA DE NASCIMENTO DE {Pessoas[cont].nome.upper()} {Pessoas[cont].sobrenome.upper()}: {Pessoas[cont].dia}/{Pessoas[cont].mes}/{Pessoas[cont].ano}")
                        else:
                            dataDeNasc = str(input("+ NOVA DATA DE NASCIMENTO: [EX: 1/1/2021] -> "))
                            dataDeNasc = dataDeNasc.rsplit("/")
                            Pessoas[cont].dia = int(dataDeNasc[0])
                            Pessoas[cont].mes = int(dataDeNasc[1])
                            Pessoas[cont].ano = int(dataDeNasc[2])
            return Pessoas


Pessoas = []
while True:
    LINHA()
    print("MENU DE OPÇÕES".center(40))
    MENU(["Registrar nova pessoa","Atualizar/visualizar dados","Manipular dados de uma pessoa já existente","Encerrar consulta"])
    opçao = int(input("- Qual opção deseja: "))
    if opçao > 4 or opçao < 1:
        print("+++++ Opção invalida! +++++")
    else:
        if (opçao == 4):
            print("\nEncerrando Consulta ...")
            break

        nome = str(input("+ Digite o nome: ")).upper()
        if (opçao == 1):
            Pessoas = REGISTRAR(nome,Pessoas)

        else:
            cont = 0
            achou = False
            for i in range(len(Pessoas)):
                if Pessoas[i].nome == nome:
                    achou = True
                    break
                cont += 1

            if not achou:
                print("+++ Pessoa não encontrada +++")
            elif (opçao == 2):
                Pessoas = DADOS_EXISTENTES(Pessoas,cont)
            else:
                Pessoas = MANIPULAR(Pessoas,cont)
        while True:
            quitWhile = str(input("\n+ DESEJA FAZER NOVA OPERAÇÃO? [S/N] ")).upper()[0]
            if quitWhile in "SN":
                break
            print("ERRO! DIGITE 'S' OU 'N'.")
        print("")

        if quitWhile == 'N':
            print("Encerrando Consulta ...")
            break