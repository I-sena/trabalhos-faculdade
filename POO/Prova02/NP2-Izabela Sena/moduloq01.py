import psycopg2

def BDconexion():
    host = "Localhost" # nome ou ip da máquina que tem o SGBD
    dbname = "company" # nome do banco de dados
    user = "postgres"  # nome do usuario
    password = "izabela16"  # senha
    #sslmode = "verify-full" #"require"

    # Construa a string de conexão
    #conn_string = \"host={0} user={1} dbname={2} password={3} sslmode={4}\".format(host, user, dbname, password, sslmode)
    conn_string = "host={0} user={1} dbname={2} password={3}".format(host, user, dbname, password)

    # Executa a conexão com o banco
    conn = psycopg2.connect(conn_string) 
    print("Connection established")

    # Ponteiro para trabalhar com o banco de dados especificado
    cursor = conn.cursor()

    #Excluir tabelas anteriores com o mesmo nome se alguma existir",
    cursor.execute("DROP TABLE IF EXISTS product;")
    print("Finished dropping table (if existed)")

    # Cria uma tabela de nome product
    cursor.execute("CREATE TABLE product (description VARCHAR(180) PRIMARY KEY, quantity INTEGER);")
    print("Finished creating table")

    conn.commit()

    return conn, cursor

def BDdisconection(conn, cursor):
    # Fecha a conexão com o banco
    cursor.close()
    conn.close()
    print("Connection closed")

def novoProduto(conn, cursor):
    descrição = input("Digite a descrição do produto: ").lower()
    quant = input("Digite a quantidade do produto: ")

    # Insere alguns dados na tabela
    cursor.execute("INSERT INTO product (description, quantity) VALUES (%s, %s);", (descrição, quant))

    # Confirma a gravação dos dados
    conn.commit()

    input("\nDados Inseridos com Sucesso - Tecle <Enter> para Continuar")

def novoProdutoNoEstoque(conn, cursor,stock:list): 
    produto = input("Qual produto deseja adicionar ao estoque: ").lower()

    # Insere alguns dados na tabela
    cursor.execute("SELECT quantity FROM product WHERE description = '{}';".format(produto))

    Prows = cursor.fetchall()
    produtoEstoque = {"NOME":produto,
                      "QTY": Prows[0]}

    stock.append(produtoEstoque)

    conn.commit()

    input("\nDados Inseridos com Sucesso - Tecle <Enter> para Continuar")

    return stock

def consultartodos(cursor):
    # Recupera todas as linhas da tabela product
    cursor.execute("SELECT * FROM product;")

    # Recupera todas as linhas de dados do cursor
    rows = cursor.fetchall()

    # Imprime todas as linhas
    print("-"*50)
    print("LISTA DE PRODUTOS".center(50))
    print("-"*50)
    cont = 1
    for row in rows:
        print(f"[{cont}] -> Descrição = {str(row[0])}, Quantidade = {str(row[1])} ")
        cont += 1
    print("-"*50)
    input("\nTecle <Enter> para Continuar")    

def excluir(conn, cursor):
    nome = input("Digite o nome do produto a apagar:").lower()
 
    # Apaga a linha de dados da tabela
    cursor.execute("DELETE FROM product WHERE description = %s;", (nome,))
    print("Deleted 1 row of data")
 
    # Confirma a gravação dos dados
    conn.commit()

    input("\nTecle <Enter> para Continuar")

def retirarEstoque(conn, cursor, stock):
    nome = input("Digite o nome do produto que deseja retirar:").lower()
    
    achou = False
    cont = 0
    for produto in stock:
        if produto["NOME"] == nome:
            achou = True
            break
        cont += 1

    if not achou:
        print("Produto Inexistente no estoque!")
        return stock

    qty = int(input("Quantidade que deseja retirar: "))
    
    cursor.execute("SELECT quantity FROM product WHERE description = '{}';".format(nome))
    qtyProduto = cursor.fetchall()
    intqty = qtyProduto[0]
    intqty = int(intqty[0])

    if intqty < qty or intqty == 0:
        print("Não é possível fazer a saída de estoque – quantidade menor que o valor desejado.")
        return stock

    cursor.execute("UPDATE product SET quantity = %s WHERE description = %s;", ((intqty - qty), nome))
    stock[cont]["QTY"] = (intqty - qty)
    
    conn.commit()

    input("\nTecle <Enter> para Continuar")

    return stock