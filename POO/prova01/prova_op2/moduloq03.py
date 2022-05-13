class BatimentosCardiacos:
    
    anoAtual = 2021
    frequenciaCardiacaMaxima = 220
    nome = ""
    sobrenome = ""
    dia = 0
    mes = 0
    ano = 0

    def __init__(self,nome,sobrenome,datadenascimento) -> None:
        self._nome = nome
        self._sobrenome = sobrenome
        self._dia = datadenascimento[0]
        self._mes = datadenascimento[1]
        self._ano = datadenascimento[2]

#--------- GETTERS E SETTERS  ----------#
    @property
    def nome(self):
        return self._nome
   
    @nome.setter
    def nome(self,nome):
        self._nome = nome


    @property
    def sobrenome(self):
        return self._sobrenome

    @sobrenome.setter
    def sobrenome(self,sobrenome):
        self._sobrenome = sobrenome
    

    @property
    def dia(self):
        return self._dia
    
    @dia.setter
    def dia(self,dia):
        self._dia = dia


    @property
    def mes(self):
        return self._mes
    
    @mes.setter
    def mes(self,mes):
        self._mes = mes
    

    @property
    def ano(self):
        return self._ano
    
    @ano.setter
    def ano(self,ano):
        self._ano = ano

#------------- DEMAIS METODOS -------------#
    
    def CalculaIdade(self):
        return self.anoAtual - self._ano

    def FrequenciaMaxima(self):
        return self.frequenciaCardiacaMaxima - self.CalculaIdade()

    def FrequenciaAlvo(self):
        fcm = self.FrequenciaMaxima()
        cinquenta = (50/100)*fcm
        oitenta = (80/100)*fcm
        return cinquenta, oitenta
