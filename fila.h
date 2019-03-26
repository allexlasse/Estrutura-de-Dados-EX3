#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
template <typename Tipo>


struct Fila{

    Tipo *P;
    int Tamanho, Quantidade, Inicio, Fim;

    //Construtores

    Fila(int tamanho){
        Tamanho = tamanho;
        P = new Tipo[tamanho];
        Quantidade = 0;
        Inicio = 0;
        Fim = -1;
    }

    ~Fila(){
        delete P;
    }

    //Metodos

    void Add(Tipo t){
        Fim++;
        if(Fim == Tamanho){
            Fim = 0;
        }
        P[Fim] = t;
        Quantidade ++;
    }

    Tipo Remove(){
        Tipo aux = P[Inicio];
        Inicio ++;
        if(Inicio == Tamanho){
            Inicio = 0;
        }
        Quantidade --;
        return aux;
    }

    void AdicionaAoInicio(Tipo t){
        Inicio--;
        if(Inicio < 0)
            Inicio = Tamanho - 1;
        P[Inicio] = t;
        Quantidade ++;
    }

    Tipo RemoveDoFim(){
        if(Fim < 0)
            Fim = Tamanho - 1;
        Tipo aux = P[Fim];
        Fim--;
        Quantidade --;
        return aux;
    }

    bool filaCheia(){
        return Quantidade == Tamanho;
    }

    bool filaVazia(){
        return Quantidade == 0;
    }
};

#endif // FILA_H_INCLUDED
