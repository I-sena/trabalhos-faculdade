import psycopg2

"# Informação da string de conexão ",
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

# Excluir tabelas anteriores com o mesmo nome se alguma existir\n",
cursor.execute("DROP TABLE IF EXISTS inventory;")
print("Finished dropping table (if existed)")

# Cria uma tabela de nome inventory",
cursor.execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);")
print("Finished creating table")

# Insere alguns dados na tabela\n",
cursor.execute("INSERT INTO inventory (name, quantity) VALUES (%s, %s);", ("banana", 150))
cursor.execute("INSERT INTO inventory (name, quantity) VALUES (%s, %s);", ("orange", 154))
cursor.execute("INSERT INTO inventory (name, quantity) VALUES (%s, %s);", ("apple", 100))
print("Inserted 3 rows of data")

# Confirma a gravação dos dados\n"
conn.commit()

# Fecha a conexão com o banco\n",
cursor.close()
conn.close()

''' ----------------------------------------------------
 Informação da string de conexão    '''

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

# Recupera todas as linhas da tabela inventory\n",
cursor.execute("SELECT * FROM inventory;")

# Recupera todas as linhas de dados do cursor\n",
rows = cursor.fetchall()

# Imprime todas as linhas\n",
for row in rows:
    print("Data row = (%s, %s, %s)" %(str(row[0]), str(row[1]), str(row[2])))

# Confirma a gravação dos dados\n",
conn.commit()

# Fecha a conexão com o banco\n",
cursor.close()
conn.close()

''' ----------------------------------------------------
 Informação da string de conexão    '''
 
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

# Atualizar uma linha de dados na tabela\n",
cursor.execute("UPDATE inventory SET quantity = %s WHERE name = %s;", (200,"banana"))
print("Updated 1 row of data")

# Confirma a gravação dos dados\n",
conn.commit()

# Fecha a conexão com o banco\n",
cursor.close()
conn.close()

''' ----------------------------------------------------
 Informação da string de conexão    '''
 
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

# Apaga a linha de dados da tabela\n",
cursor.execute("DELETE FROM inventory WHERE name = %s;", ("orange",))
print("Deleted 1 row of data")

# Confirma a gravação dos dados\n",
conn.commit()

# Fecha a conexão com o banco\n",
cursor.close()
conn.close()

''' ----------------------------------------------------
 Informação da string de conexão    '''
 
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

quant = input("Digite a quantidade da qual deseja apresentar os produtos=")

# Recupera todas as linhas da tabela inventory\n",
cursor.execute("SELECT * FROM inventory WHERE quantity >= {};".format(quant))

# Recupera todas as linhas de dados do cursor\n",
rows = cursor.fetchall()

# Imprime todas as linhas\n",
for row in rows:
    print("Data row = (%s, %s, %s)" %(str(row[0]), str(row[1]), str(row[2])))

# Confirma a gravação dos dados\n",
conn.commit()

# Fecha a conexão com o banco\n",
cursor.close()
conn.close()