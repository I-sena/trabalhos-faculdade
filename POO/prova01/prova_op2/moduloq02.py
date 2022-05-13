
class Continente:

    nome = ""
    paises = []
    
    def __init__(self, nome : str):
        self.nome = nome
        self._paises = []

    @property
    def paises(self):
        return self._paises

    @paises.setter                                          # B) ADICIONAR PAÍS AO CONTINENTE
    def paises(self ,novoPais):
        if isinstance(novoPais, dict):
            self._paises.append(novoPais)
        else:
            raise TypeError

    def dimensaoContinente(self):                           #C) DIMENSÃO DO CONTINENTE
        Total = 0
        TodosPaises = self._paises.copy()
        for i in range(len(TodosPaises)):
            Total += TodosPaises[i]["DIMENSÃO"]
        return Total
            
    def populacaoContinente(self):                          # D (e E??) POPULAÇÃO TOTAL
        Total = 0
        TodosPaises = self._paises.copy()
        for pais in TodosPaises:                                   
            Total += pais["POPULAÇÃO"]
        return Total

    def paisMaisPopuloso(self):                             # F) PAÍS MAIS POPULOSO
        TodosPaises = self._paises.copy()
        MaisPopuloso = 0
        Nome = str
        for pais in TodosPaises:
            if pais["POPULAÇÃO"] > MaisPopuloso:
                MaisPopuloso = pais["POPULAÇÃO"]                
                Nome = pais["NOME"]
        return Nome, MaisPopuloso

    def paisMenosPopuloso(self):                                # G) PAÍS MENOS POPULOSO
        TodosPaises = self._paises.copy()
        menosP = TodosPaises[0]["NOME"]
        população = TodosPaises[0]["POPULAÇÃO"]
        for pais in TodosPaises:
            if pais["POPULAÇÃO"] < população:
                população = pais["POPULAÇÃO"]
                menosP = pais["NOME"]
        return menosP, população

    def paisMaiorTerritorio(self):                              # H) PAIS MAIOR DIMENSÃO
        TodosPaises = self._paises.copy()
        MaiorPais = 0
        Nome = str
        for pais in TodosPaises:
            if pais["DIMENSÃO"] > MaiorPais:
                MaiorPais = pais["DIMENSÃO"]
                Nome = pais["NOME"]
        return Nome, MaiorPais

    def menorTerritorio(self):                                   # I) MENOR DIMENSÃO
        TodosPaises = self._paises.copy()
        Nome = TodosPaises[0]["NOME"]
        MenorPais = TodosPaises[0]["DIMENSÃO"]
        for pais in TodosPaises:
            if pais["DIMENSÃO"] < MenorPais:
                MenorPais = pais["DIMENSÃO"]
                Nome = pais["NOME"]
        return Nome, MenorPais

    def razaoTerritorial(self):                                 #j) RAZÃO TERRITORIAL MAIOR PAIS EM RELAÇÃO AO MENOR
        nome, maior = self.paisMaiorTerritorio()
        nome1, menor = self.menorTerritorio()
        return maior - menor

