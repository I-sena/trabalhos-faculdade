class ContaBanco:

    def __init__(self):
        self.__saldo = 0
        self.__status = False
        self.numConta = None
        self._tipoConta = None
        self.__dono = None

    def setnumConta(self,Nconta):
        self.numConta = Nconta
    def getnumConta(self):
        return self.numConta

    def getsaldo(self):
        return self.__saldo
    def setsaldo(self,Saldo):
        self.__saldo = Saldo

    def getStatus(self):
        return self.__status
    def setStatus(self,Status):
        self.__status = Status

    def getdono(self):
        return self.__dono
    def setDono(self,Dono):
        self.__dono = Dono

    @property
    def tipoConta(self):
        return self._tipoConta

    @tipoConta.setter
    def set_tipo(self,TipoC):
        self._tipoConta = TipoC

    def abrirConta(self,tipoConta,nome): 
        self.__dono = nome
        self.set_tipo(tipoConta)
        self.setStatus(True)
        if self._tipoConta == 'CC':
            self.__saldo = 50
        elif self._tipoConta == 'CP':
            self.__saldo = 150    

    def fecharConta(self):
        if self.__status is not True:
            return 'Conta ja esta fechada!'
        if self.__saldo == 0:
            self.__status = False
            return 'Conta fechada com sucesso!'
        elif self.__saldo > 0 :
            return 'Saque o saldo restante para poder fechar a conta!'
        elif self.__saldo < 0:
            return 'Debito pendente, pague para poder chegar a conta'

    def depositar(self, deposito):
        if self.__status is not True:
            return 'Conta fechada, nao é possivel depositar'
        self.__saldo += deposito

    def sacar(self, saque):
        if self.__status is not True:
            return 'Não se pode sacar de uma conta fechada!'
        if self.__saldo <= 0 or saque > self.__saldo:
            return 'Não a saldo suficiente!'
        self.__saldo -= saque

    def pagarMensal(self):
        if self._tipoConta == 'CC':
            self.__saldo -= 12
        elif self._tipoConta == 'CP':
            self.__saldo -= 20


C1 = ContaBanco()
C1.abrirConta('CC','Izabela')
C1.depositar(100)
C1.sacar(10)
C1.__saldo = 10
print(C1.sacar(2000))
print(C1.fecharConta())
