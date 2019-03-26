#include <iostream>
#include "fila.h"
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    cout<<"***EXERCICIO FILA CIRCULAR DUPLA***"<<endl;

    int LineSize, valor;
    string wait;

    cout<<"Qual o tamanho da fila? ";
    cin>>LineSize;
    Fila<int> F(LineSize);
    bool exit = true;

    while(exit){
        system("CLS");
        cout<<"INFORMACOES DA FILA:"<<endl;
        cout<<"\nTamanho maximo: "<<LineSize<<endl;
        cout<<"Quantidade de elementos na fila: "<<F.Quantidade<<endl;
        cout<<"Posicao do inicio: "<<F.Inicio<<endl;
        cout<<"Posicao do fim: "<<F.Fim<<endl;
        cout<<"\nMENU\n"<<endl;
        cout<<"1-Adicionar\n2-Remover\n3-Exibir fila completa\n4-Adiciona ao Inicio\n5-Remove do Fim\n0-SAIR\n\nOpcao selecionada: ";
        int option;
        cin>>option;
        switch(option){
        //Adicionar
        case 1:
            if(F.filaCheia()){
                cout<<"Fila cheia. Aperte qualquer tecla para retornar ao MENU"<<endl;
                getch();
            }
            else{
                cout<<"Entre com o valor que deseja adicionar a fila: ";
                cin>>valor;
                F.Add(valor);
            }
            break;
        //Remover
        case 2:
            if(F.filaVazia()){
                cout<<"Fila vazia. Aperte qualquer tecla para retornar ao MENU"<<endl;
                getch();
            }
            else{
                F.Remove();
                cout<<"Remocao bem sucedida. Aperte qualquer tecla para retornar ao MENU"<<endl;
                getch();
            }
            break;
        //Exibicao
        case 3:
            if(F.filaVazia()){
                cout<<"Fila vazia. Aperte qualquer tecla para retornar ao MENU"<<endl;
                getch();
            }
            else{
                if(F.Inicio<=F.Fim){
                    cout<<"ELEMENTOS DA FILA: "<<endl;
                    for(int i = F.Inicio; i <= F.Fim; i ++){
                        cout<<F.P[i]<<" ";
                    }
                    cout<<"\nAperte qualquer tecla para retornar ao MENU"<<endl;
                    getch();
                }
                else{
                    cout<<"ELEMENTOS DA FILA: "<<endl;
                    for(int i = F.Inicio; i < LineSize; i++ ){
                        cout<<F.P[i]<<" ";
                    }
                    for(int j = 0; j <= F.Fim; j++){
                        cout<<F.P[j]<<" ";
                    }
                    cout<<"\nAperte qualquer tecla para retornar ao MENU"<<endl;
                    getch();
                }
            }
            break;
            //Adiciona ao inicio
            case 4:
                if(F.filaCheia()){
                    cout<<"Fila cheia. Aperte qualquer tecla para retornar ao MENU."<<endl;
                    getch();
                }
                else{
                    cout<<"Entre com o valor a ser adicionado: ";
                    cin>>valor;
                    F.AdicionaAoInicio(valor);
                }
                break;
                //Remover do fim
            case 5:
                if(F.filaVazia()){
                    cout<<"Fila vazia. Aperte qualquer tecla para retornar ao MENU."<<endl;
                    getch();
                }
                else{
                    F.RemoveDoFim();
                    cout<<"Removido com sucesso.Aperte qualquer tecla para retornar ao MENU."<<endl;
                    getch();
                }
                break;
            //SAIR
        case 0:
            cout<<"SAIR."<<endl;
            exit = false;
            break;
        default:
            cout<<"Comando invalido. Aperte qualquer tecla para retornar ao MENU."<<endl;
            getch();
            break;
        }
    }

    return 0;
}
