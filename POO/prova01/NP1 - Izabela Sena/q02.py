from moduloq02 import Continente

def linha(type = "*",size = 40):
    return type*size

def menu(opçoes):
    cont = 1
    for op in opçoes:
        print(f"[{cont}] - {op}")
        cont += 1
    print(linha())


ListOfCont = []
while True:

    print(linha())
    print(" MENU DE OPÇÕES ".center(40))
    print(linha())

    while True:
        menu(["Criar um novo continente","Manipular dados de um continente existente","Encerrar consulta"])
        op = int(input("- Qual opção deseja? "))
        if op >= 1 and op <= 3:
            break
        else:
            print("+ Opção invalida, escolha novamente!\n")

    if (op == 3):
        print("\nEncerrando Consulta ...")
        break
    
    nome = str(input("+ Digite o nome do continente: ")).upper()
    if( op == 1):
        new = Continente(nome)
        ListOfCont.append(new)

    elif (op == 2):
        cont = 0
        achou = False
        for i in range(len(ListOfCont)):
            if ListOfCont[i].nome == nome:  
                achou = True  
                break   
            cont += 1
        if not achou:
            print("+++| Continente não encontrado. |+++")
        else:
            while True :
                print("\n"+linha())
                print("OPERAÇÕES".center(40))
                print(linha())
                menu(["Adicionar novo país","Dimensao total","População total","Pais mais populoso","País menos populoso","País com maior extensão territorial","País com menor extensão territirial","Razão territorial"])
                op2 = int(input("- Qual operação deseja? "))
                
                if not (op2 >= 1 and op2 <= 8):
                    print(linha("-")+"\nOPÇÃO INVALIDA! DIGITE NOVAMENTE.".center(40)+"\n"+linha("-"))
                
                else:
                    if op2 == 1:
                        print("+++++ INFORMAÇÕES DO PAÍS +++++".center(40))
                        nomeNovoPais = str(input("+ Nome do País: ")).upper()
                        dimensaoNovoPais = int(input("+ Dimensão do País: "))
                        populaçaoNovoPais = int(input("+ População do País: "))
                        print(linha("+"))
                        NovoPais = { "NOME": nomeNovoPais,
                                    "DIMENSÃO": dimensaoNovoPais,
                                    "POPULAÇÃO": populaçaoNovoPais }
                        ListOfCont[cont].paises.append(NovoPais)

                    elif op2 == 2:
                        total = ListOfCont[cont].dimensaoContinente()
                        print(f"A dimensão da {ListOfCont[cont].nome.capitalize()} é de {total} quilômetros quadrados.")
                    
                    elif op2 == 3:
                        total = ListOfCont[cont].populacaoContinente()
                        print(f"A população total da {ListOfCont[cont].nome.capitalize()} é de {total} Habitantes.")  

                    elif op2 == 4:
                        NomePmPais, população = ListOfCont[cont].paisMaisPopuloso()
                        print(f"O país mais populoso da {ListOfCont[cont].nome.capitalize()} é {NomePmPais.capitalize()} com {população} Habitantes.")
                    
                    elif op2 == 5:
                        NomePlPais, população = ListOfCont[cont].paisMenosPopuloso()
                        print(f"O país menos populoso da {ListOfCont[cont].nome.capitalize()} é {NomePlPais.capitalize()} com {população} Habitantes.")        
                    
                    elif op2 == 6:
                        NomePbPais, dimensao = ListOfCont[cont].paisMaiorTerritorio()
                        print(f"O maior país da {ListOfCont[cont].nome.capitalize()} é {NomePbPais.capitalize()} com {dimensao} Km^2 de dimensão.")        

                    elif op2 == 7:
                        NomePsais, dimensao = ListOfCont[cont].menorTerritorio()
                        print(f"O menor país da {ListOfCont[cont].nome.capitalize()} é {NomePsais.capitalize()} com {dimensao} Km^2 de dimensão.")
                    
                    else:
                        Razao = ListOfCont[cont].razaoTerritorial()
                        print(f"A razão territorial entre o maior e o menor país da {ListOfCont[cont].nome.capitalize()} é de {Razao}.")
                                           
                    break

    
    while True:
        quitWhile = str(input("\n+ DESEJA FAZER NOVA OPERAÇÃO? [S/N] ")).upper()[0]
        if quitWhile in "SN":
            break
        print("ERRO! DIGITE 'S' OU 'N'.")
    print()
    if quitWhile == 'N':
        print("\nEncerrando Consulta ...")
        break