#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#definição da classe ponto 
class ponto:
    #definição dos atributos x e y da classe
    x=0
    y=0
    
    #definição do construtor da classe
    def __init__(self,x=None,y=None):
        if x is None:
            self.x=0
        else:
            self.x=x
        if y is None:
            self.y=0
        else:
            self.y=y    
    
    #definição do método ledados para leitura dos dados do ponto
    def ledados(self):
        self.x=int(input("Digite a coordenada x do ponto:"))
        self.y=int(input("Digite a coordenada y do ponto:"))
    
    #definição do método mostradados para mostrar os dados do ponto
    def mostradados(self):
        print("Coordenadas do ponto x={} e y={}".format(self.x,self.y))
        

