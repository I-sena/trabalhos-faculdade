class Pais:
    
    codigo = ""
    nome = ""
    dimensao = 0
    populacao = 0
    vizinho = []

    def __init__(self, codigo, nome, dimensao):
        self.codigo = codigo
        self.nome = nome
        self.dimensao = dimensao
        self.populacao = None
        self.vizinho = []
   
# ---------- GETTERS E SETTERS ----------- #
    
    def getcodigo(self):
        return self.codigo

    
    def setcodigo(self,codigo):
        self.codigo = codigo

    
    def getnome(self):
        return self.nome

    
    def setnome(self,nome):
        self.nome = nome


    def getpopulacao(self):
        return self.populacao
        
   
    def setpopulacao(self,populacao):
        self.populacao = populacao


    def getdimensao(self):
        return self.dimensao
        
    def setdimensao(self,dimensao):
        self.dimensao = dimensao

# ------------- DEMAIS METODOS -------------- #

    def paisesIguais(self, codigo):                                             #Questão C 
        if self.codigo == codigo:
            return True
        else:
            return False


    def paisesLimitrofe(self, codigo):                                          #Questão D 
        for i in range(len(self.vizinho)):
            if codigo == self.vizinho[i].codigo:
                return True
        return False


    def densidade(self):                                                        # Questão E 
        if self.populacao is not None and self.dimensao != 0: 
            a = self.populacao/self.dimensao                                                       
            return a
        else:
            return False

    def paisesVizinhos(self,P2vizinho):                                         # Questão F 
        comuns = []
        for pais1 in self.vizinho:
            for pais2 in P2vizinho:
                if pais2.codigo == pais1.codigo:
                    comuns.append(pais1.nome)
                    break
        return comuns
    

    def paisesOrdemAlfabetica(self):                                            #Questão G 
        nameList = []
        for pais in self.vizinho:
            nameList.append(pais.nome)
        return sorted(nameList)