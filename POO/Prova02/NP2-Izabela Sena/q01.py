from moduloq01 import*

conn, cursor = BDconexion()
stock = []
while True:

    print("-"*50)
    print("Menu de Opções".center(50))
    print("1-Incluir Novo Produto")
    print("2-Listar todos os Produtos")
    print("3-Adicionar ao estoque")
    print("4-retirar do estoque")
    print("5-Excluir Produto")
    print("6-Sair\n"+"-"*50)
    opcao = int(input("Digite a opção desejada ==> "))
    if opcao == 6:
        break
    if opcao == 1:
        novoProduto(conn, cursor)
    elif opcao == 2:
        consultartodos(cursor)
    elif opcao == 3:
        novoProdutoNoEstoque(conn, cursor,stock)
    elif opcao == 4:
        retirarEstoque(conn, cursor,stock)
    elif opcao == 5:
        excluir(conn, cursor)

BDdisconection(conn, cursor)  