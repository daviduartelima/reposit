#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct FilaDeBanco
{
    int idade;
    string cpf;
    int sexo;
    bool gravida = false;
    struct Lista *prox, *ant; *prio; *novo;

    FilaDeBanco* proximo = NULL;  FilaDeBanco* anterior = NULL;
};

int lerInteiro(string campo){
    int valor;
    cout << "\nDigite " << campo << ": ";
    cin >> valor;
    return valor;
}
string lerString(string campo){
    string valor;
    cout << "\nDigite " << campo << ": ";
    cin >> valor;
    return valor;
}
void printFilaDeBanco(FilaDeBanco FilaDeBanco){
    cout << "\nIdade: " << FilaDeBanco.idade << endl;
    cout << "CPF: " << FilaDeBanco.cpf << endl;
    if (FilaDeBanco.sexo == 1)  {
        cout << "Sexo: Feminino\n";
    if (FilaDeBanco.gravida == true){
        cout << "Gravida: Sim\n";
    }
    else
    {
       cout << "Gravida: Nao\n";
    }
    }
    else
    {
        cout << "SEXO: Masculino\n";
    }
}
int main()
{
FilaDeBanco* inicioLista = NULL; FilaDeBanco* aux = NULL;  FilaDeBanco* fimLista = NULL;
   
int opcao = 0;
while (opcao != 4)
    {
    cout << "\n1-Adicionar nova pessoa";
    cout << "\n2-Listar todas as pessoas";
    cout << "\n3-Proximo atendimento";
    cout << "\n4-Sair";
    cout << "\n\nEscolha Opcao: ";
    cin >> opcao;
        switch (opcao){
        case 1:{
        FilaDeBanco* novo = new FilaDeBanco;
        novo->idade = lerInteiro("idade");
        novo->cpf = lerString("cpf");
        novo->sexo = lerInteiro("sexo (1-Feminino 2-Masculino)");
       
        if (novo->sexo == 1){
        int gravida;
            cout << "\nVoce esta gravida? (1-SIM 2-NAO): ";
            cin >> gravida;
        if (gravida == 1){
        novo->gravida = true;}
        else{
        novo->gravida = false;} }
       
        if (novo->idade > 65 || novo->gravida == true) {
       
        if (inicioLista == NULL) {
        inicioLista = novo;
        fimLista = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;}
        else{
        novo->proximo = inicioLista;
        inicioLista->anterior = novo;
        novo->anterior = NULL;
        inicioLista = novo;   }
        }
        else
        {
        if (inicioLista == NULL)
        {
        inicioLista = novo;
        fimLista = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        }
        else
        {
        fimLista->proximo = novo;
        novo->anterior = fimLista;
        novo->proximo = NULL;
        fimLista = novo;  }
        }
        } break;
        case 2: {
        if (inicioLista == NULL) {
            cout << "\nLista Vazia" << endl;
        }
        else
        {
        aux = inicioLista;
        while (aux != NULL)
        {
        printFilaDeBanco(*aux);
        aux = aux->proximo; }
        }
        } break;
        case 3: {
        if (inicioLista == NULL) {
            cout << "\nLista Vazia" << endl;
        }
        else
        {
        aux = inicioLista;
        printFilaDeBanco(*aux);
        aux = aux->proximo;
        aux = inicioLista;
        inicioLista = inicioLista->proximo;
        delete(aux);
        aux = inicioLista;   }
        } break;
        }
    }
  return 0;
}

