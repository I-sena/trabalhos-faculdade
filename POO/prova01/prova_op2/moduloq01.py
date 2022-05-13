class Pais:
    
    codigo = ""
    nome = ""
    dimensao = 0
    populacao = 0
    vizinho = []

    def __init__(self, codigo, nome, dimensao):
        self._codigo = codigo
        self._nome = nome
        self._dimensao = dimensao
        self._populacao = None
        self._vizinho = []
   
# ---------- GETTERS E SETTERS ----------- #
    @property
    def codigo(self):
        return self._codigo

    @codigo.setter
    def codigo(self,codigo):
        if len(codigo) == 3:
            self._codigo = codigo
        else:
            raise ValueError("Codigo invalido! Codigo deve conter 3 letras.")

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self,nome):
            self._nome = nome


    @property
    def populacao(self):
        return self._populacao
        
    @populacao.setter
    def populacao(self,populacao):
        if isinstance(populacao,int):
            self._populacao = populacao
        else:
            raise TypeError


    @property
    def dimensao(self):
        return self._dimensao
        
    @dimensao.setter
    def dimensao(self,dimensao):
        if isinstance(dimensao, int):
            self._dimensao = dimensao
        else:
            raise TypeError
    

    @property
    def vizinho(self):
        return self._vizinho

    @vizinho.setter
    def vizinho(self,vizinho):
        if isinstance(vizinho, Pais):
            self._vizinho.append(vizinho)
        else:
            raise TypeError

# ------------- DEMAIS METODOS -------------- #

    def paisesIguais(self, codigo):                                             #Questão C 
        if self._codigo == codigo:
            return True
        else:
            return False


    def paisesLimitrofe(self, codigo):                                          #Questão D 
        for i in range(len(self._vizinho)):
            if codigo == self._vizinho[i].codigo:
                return True
        return False


    def densidade(self):
        if self._populacao is not None and self._dimensao != 0: 
            a = self._populacao/self._dimensao                                                       # Questão E 
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
        for pais in self._vizinho:
            nameList.append(pais.nome)
        return sorted(nameList)