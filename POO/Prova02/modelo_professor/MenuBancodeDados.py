import psycopg2

def BDconexion():
    host = "Localhost" # nome ou ip da máquina que tem o SGBD\n,
    dbname = "company" # nome do banco de dados\n",
    user = "postgres"  # nome do usuario\n",
    password = "izabela16"  # senha\n",
    #sslmode = "verify-full" #"require"

    # Construa a string de conexão",
    #conn_string = \"host={0} user={1} dbname={2} password={3} sslmode={4}\".format(host, user, dbname, password, sslmode)\n",
    conn_string = "host={0} user={1} dbname={2} password={3}".format(host, user, dbname, password)

    # Executa a conexão com o banco\n",
    conn = psycopg2.connect(conn_string) 
    print("Connection established")

    # Ponteiro para trabalhar com o banco de dados especificado\n",
    cursor = conn.cursor()

    return conn, cursor

def BDdisconection(conn, cursor):
    # Fecha a conexão com o banco\n",
    cursor.close()
    conn.close()
    print("Connection closed")

def include(conn, cursor):
    nome=input("Digite o nome do produto")
    quant=input("Digite a quantidade do produto")

    # Insere alguns dados na tabela\n",
    cursor.execute("INSERT INTO inventory (name, quantity) VALUES (%s, %s);", (nome, quant))

    # Confirma a gravação dos dados\n",
    conn.commit()

    input("Dados Inseridos com Sucesso - Tecle <Enter> para Continuar")

def consultartodos(conn, cursor):
    # Recupera todas as linhas da tabela inventory\n",
    cursor.execute("SELECT * FROM inventory;")

    # Recupera todas as linhas de dados do cursor\n",
    rows = cursor.fetchall()

    # Imprime todas as linhas\n",
    for row in rows:
        print("Data row = (%s, %s, %s)" %(str(row[0]), str(row[1]), str(row[2])))
    input("Tecle <Enter> para Continuar")    

def consultarpornome(conn, cursor):
    nome=input("Digite o nome do produto a pesquisar:")

    # Recupera todas as linhas da tabela inventory\n",
    cursor.execute("SELECT * FROM inventory WHERE name = '{}';".format(nome))
  
    # Recupera todas as linhas de dados do cursor\n",
    rows = cursor.fetchall()
   
    # Imprime todas as linhas\n",
    for row in rows:
        print("Data row = (%s, %s, %s)" %(str(row[0]), str(row[1]), str(row[2])))
 
    input("Tecle <Enter> para Continuar")

def alterar(conn, cursor):

    nome=input("Digite o nome do produto")
    quant=input("Digite a quantidade do produto")

    # Atualizar uma linha de dados na tabela\n",
    cursor.execute("UPDATE inventory SET quantity = %s WHERE name = %s;", (quant, nome))
    print("Updated 1 row of data")
   
    # Confirma a gravação dos dados\n",
    conn.commit()

    input("Tecle <Enter> para Continuar")

def excluir(conn, cursor):
    nome=input("Digite o nome do produto a apagar:")
 
    # Apaga a linha de dados da tabela\n",
    cursor.execute("DELETE FROM inventory WHERE name = %s;", (nome,))
    print("Deleted 1 row of data")
 
    # Confirma a gravação dos dados\n",
    conn.commit()

    input("Tecle <Enter> para Continuar")


conn, cursor = BDconexion()


while True:
    #clear_output()
    print("Menu de Opções")
    print("1-Incluir")
    print("2-Consultar Todos")
    print("3-Consultar pelo Nome")
    print("4-Alterar")
    print("5-Excluir")
    print("6-Sair")
    opcao = int(input("Digite a opção desejada ==> "))
    if opcao == 6:
        break
    if opcao == 1:
        include(conn, cursor)
    if opcao == 2:
        consultartodos(conn, cursor)
    if opcao == 3:
        consultarpornome(conn, cursor)
    if opcao == 4:
        alterar(conn, cursor)
    if opcao == 5:
        excluir(conn, cursor)

BDdisconection(conn, cursor)   