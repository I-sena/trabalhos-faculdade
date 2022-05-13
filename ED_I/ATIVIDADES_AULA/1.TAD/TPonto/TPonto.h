#ifndef TPONTO_H
#define TPONTO_H

typedef struct ponto Ponto;
//Cria um novo ponto, passando floats x e y
Ponto* Ponto_create(float, float);
//Remove
void Ponto_delete(Ponto*);
//Imprime um dado ponto
void Ponto_print(const Ponto*);
//Access values x and y
//Retorna 1 se foi sucesso, ou 0 caso contrario.
int Ponto_getxy(const Ponto*, float*, float*);
//Set values x and y to a point
//Retorna 1 se for sucesso, ou 0 em caso contrario
int Ponto_setxy(Ponto*, float, float);
//Calcula a distancia euclidiana entre dois pontos
double Ponto_distance(const Ponto*, const Ponto*);

#endif