#!/usr/bin/env python
# coding: utf-8

# In[ ]:


class aluno:
    nome=""
    idade=0
    anoingresso=0
    numperiodos=0
    mediaporperiodo=[]
    
    def __init__(self):
        self.nome=""
        self.idade=0
        self.anoingresso=0
        self.numperiodos=0
        self.mediaporperiodo=[]
        
    def ledadosaluno(self):
        self.nome=input("Digite o nome do aluno:")
        self.idade=int(input("Digite a idade do aluno:"))
        self.anoingresso=int(input("Digite o ano de ingresso do aluno:"))
        self.numperiodos=int(input("Digite o número de períodos do aluno:"))
        for i in range(1,self.numperiodos+1):
            msg="Digite a média do período "+str(i)+":"
            media=float(input(msg))
            self.mediaporperiodo.append(media)
            
    def mostradadosaluno(self):
        print("Nome={}, idade={}, ano de ingresso={} e número de períodos={}".format(self.nome,self.idade,self.anoingresso,self.numperiodos))
        for i in (range(len(self.mediaporperiodo))):
            print("Media do periodo {}={}".format(i+1,self.mediaporperiodo[i]))
            
    def calculamediageral(self):
        media=0
        for i in (range(len(self.mediaporperiodo))):
            media=media+self.mediaporperiodo[i]
            
        media=media/len(self.mediaporperiodo)
        
        return media
        

