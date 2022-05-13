from moduloq01 import Pais

def linha(type = "*",size = 40):
    return type*size

def menu(opçoes):
    cont = 1
    for op in opçoes:
        print(f"[{cont}] - {op}")
        cont += 1
    print(linha())

def menuDados(operacao):
    opdados = []
    print(linha("-")+"\n"+"TIPOS DE DADOS".center(40))
    menu(["NOME","CODIGO","DIMENSÃO","POPULAÇÃO"])
    print(f"+ Qual/quais dados deseja {operacao}:")
    i = 1
    while True:
        if i == 5:
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
    return opdados


ListOfContries = []
while True:

    print(linha())
    print(" MENU DE OPÇÕES ".center(40))
    print(linha())

    while True:
        menu(["Criar um novo País","Manipular/Consultar dados de um País existente","Encerrar consulta"])
        op = int(input("- Qual opção deseja? "))
        if op >= 1 and op <= 3:
            break
        else:
            print("+ Opção invalida, escolha novamente!\n")

    if (op == 3):
        print("Encerrando Consulta ...")
        break
    
    nome = str(input("+ Digite o nome do País: ")).upper()
    if (op == 1):
        while True:
            codigo = str(input("+ Digite codigo do país: ")).upper()
            if not len(codigo) == 3:
                print("+++++ Codigo invalido, codigo deve conter 3 letras! +++++")
            else:
                while True:
                    dimensao = input("+ Digite a dimensão do país: ")    
                    if not dimensao.isdecimal():
                        print("+++++ ERRO, dimensão deve ser valor um numerico. ++++")
                    else:
                        new = Pais(codigo,nome,int(dimensao))
                        ListOfContries.append(new)
                        break
                break

    elif (op == 2):
        cont = 0
        achou = False
        for pais in ListOfContries:
            if pais.nome == nome:  
                achou = True  
                break   
            cont += 1
        if not achou:
            print("+++| País não encontrado. |+++")
        else:
            while True :
                print("\n"+linha())
                print("OPERAÇÕES".center(40))
                print(linha())
                menu(["Atualizar/Registrar/Consultar dado","Adicionar novo país vizinho","Verificar igualdade entre dois países","País limitrofe","Densidade Populacional","Vizinhos em comum","Países vizinhos em ordem alfabetica"])
                op2 = int(input("- Qual operação deseja? "))
                
                if (op2 < 1 or op2 > 7):
                    print(linha("-")+"\nOPÇÃO INVALIDA! DIGITE NOVAMENTE.".center(40)+"\n"+linha("-"))
                else: 
                    if (op2 == 1):
                        while True:
                            AorR = int(input("+ DESEJA:".center(40)+"\n[1] Atualizar dado.\n[2] Registrar novo dado\n[3] Visualizar dado\n-- "))
                            if AorR > 3 or AorR < 1:
                                print("+ Opção invalido, digite novamente!\n")
                                linha("-")
                            else:
                                if AorR == 3:
                                    opdados = menuDados("visualizar")
                                elif AorR == 1:
                                    opdados = menuDados("atualizar")
                                elif AorR == 2:
                                    opdados = menuDados("registrar")

                                for i in range(4):
                                    if opdados[i] == "S":
                                        if i == 0:
                                            if AorR == 3:
                                                print(f"NOME DO PAÍS: {ListOfContries[cont].nome}")
                                            else:
                                                Nnome = str(input("+ NOVO NOME: ")).upper()
                                                ListOfContries[cont].nome = Nnome
                                        elif i == 1:
                                            if AorR == 3:
                                                print(F"CODIGO DO PAÍS: {ListOfContries[cont].codigo}")
                                            else:
                                                Ncod = str(input("+ NOVO CODIGO: ")).upper()
                                                ListOfContries[cont].codigo = Ncod
                                        elif i == 2:
                                            if AorR == 3:
                                                print(F"DIMENSÃO DO PAÍS: {ListOfContries[cont].dimensao}")
                                            else:
                                                Ndim = int(input("+ NOVA DIMENSÃO: "))
                                                ListOfContries[cont].dimensao = Ndim
                                        elif i == 3:
                                            if AorR == 3:
                                                print(F"POPULAÇÃO DO PAÍS: {ListOfContries[cont].populacao}")
                                            else:
                                                Npop = int(input("+ NOVA POPULAÇÃO: "))
                                                ListOfContries[cont].populacao = Npop 
                                break

                    if op2 == 2:
                        print(f"+++++ INFORMAÇÕES DO PAÍS VIZINHO DO/DA {ListOfContries[cont].nome.upper()} +++++".center(40))
                        nomeNovoPais = str(input("+ Nome do País: ")).upper()
                        codigoNovoPais = str(input("+ Codigo do País: ")).upper()
                        dimensaoNovoPais = int(input("+ Dimensão do País: "))
                        print(linha("+"))                        
                        ListOfContries[cont].vizinho = Pais(codigoNovoPais,nomeNovoPais,dimensaoNovoPais)

                    elif op2 == 3:
                        if ListOfContries[cont].paisesIguais(str(input("+ Digite o codigo do pais para comparação: ")).upper()):
                            print(f"+++ Os dois paises são iguais! +++")
                        else:
                            print(f"+++ Os países não são os mesmos. +++")

                    elif op2 == 4:
                        if ListOfContries[cont].paisesLimitrofe(str(input("+ Digite o codigo do pais para comparação: ")).upper()):
                            print(f"São limítrofes, Os países fazem fronteira um com o outro!")  
                        else:
                            print("Os países não são limítrofes. Eles não fazem fronteira!")
                   
                    elif op2 == 5:
                        densidade = ListOfContries[cont].densidade()
                        if densidade is False:
                            print("ERROr!! Densidade registrada com valor 0 e/ou População ainda não registrada!")
                        else:
                            print(f"A densidade populacional do/da {ListOfContries[cont].nome.capitalize()} é de aprox. {densidade:.2f} Habitantes por Km^2")
                    
                    elif op2 == 6:
                        print("+++ PAÍSES JA CADASTRADOS +++".center(40))
                        cc = 1
                        print(linha())
                        for pais in ListOfContries:
                            print(f"[{cc}] - {pais.nome}")
                            cc += 1
                        print(linha())
                        selec = int(input("-QUAl DESSES PAÍS DESEJA PARA FAZER A COMPARAÇÃO? "))
                        paisesC = ListOfContries[cont].paisesVizinhos(ListOfContries[selec-1].vizinho)
                        cc = 0
                        print(linha("*")+f"\nPAISES VIZINHOS EM COMUM ENTRE {ListOfContries[cont].nome.upper()} E {ListOfContries[selec-1].nome.upper()}")
                        for pais in paisesC:
                            print(f"[{cc+1}]- {pais}")
                            cc += 1
                        if cc == 0:
                            print(f"[!!!] {ListOfContries[cont].nome.upper()} E {ListOfContries[selec-1].nome.upper()} NÃO TEM VIZINHOS EM COMUM.")

                    elif op2 == 7:
                        linha("+")
                        print(f"Países vizinhos á {ListOfContries[cont].nome.capitalize()} em ordem alfabetica:")
                        listaA = ListOfContries[cont].paisesOrdemAlfabetica()
                        cont = 1
                        for pais in listaA:
                            print(f"[{cont}]- {pais}")
                            cont += 1
                        print(linha("+"))        
                     
                    break

    while True:
        quitWhile = str(input("\n+ DESEJA FAZER NOVA OPERAÇÃO? [S/N] ")).upper()[0]
        if quitWhile in "SN":
            break
        print("ERRO! DIGITE 'S' OU 'N'.")
    print()
    if quitWhile == 'N':
        print("Encerrando Consulta ...")
        break