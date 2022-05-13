class BatimentosCardiacos:
    
    anoAtual = 2021
    frequenciaCardiacaMaxima = 220
    nome = ""
    sobrenome = ""
    dia = 0
    mes = 0
    ano = 0

    def __init__(self,nome,sobrenome,datadenascimento) -> None:
        self.nome = nome
        self.sobrenome = sobrenome
        self.dia = datadenascimento[0]
        self.mes = datadenascimento[1]
        self.ano = datadenascimento[2]

#--------- GETTERS E SETTERS  ----------#
    def getnome(self):
        return self.nome
   
    def setnome(self,nome):
        self.nome = nome

    def getsobrenome(self):
        return self.sobrenome

    def setsobrenome(self,sobrenome):
        self.sobrenome = sobrenome
    
    def getdia(self):
        return self.dia
    
    def setdia(self,dia):
        self.dia = dia

    def getmes(self):
        return self.mes
    
    def setmes(self,mes):
        self.mes = mes
    
    def getano(self):
        return self.ano
    
    def setano(self,ano):
        self.ano = ano

#------------- DEMAIS METODOS -------------#
    
    def CalculaIdade(self):
        return self.anoAtual - self.ano

    def FrequenciaMaxima(self):
        return self.frequenciaCardiacaMaxima - self.CalculaIdade()

    def FrequenciaAlvo(self):
        fcm = self.FrequenciaMaxima()
        cinquenta = (50/100)*fcm
        oitenta = (80/100)*fcm
        return cinquenta, oitenta
