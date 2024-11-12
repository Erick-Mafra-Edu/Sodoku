#include<iostream>
#include<locale.h>
#include <time.h>
#define TAM 9
using namespace std;
int main(){
    int color = 93;
    int seletor,acertos;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
    int linha, coluna;
    int matrizJogo[TAM][TAM];
    int matrizMestra[TAM][TAM] = {
        4,9,5,2,8,7,3,6,1,
        7,2,8,6,1,3,4,9,5,
        3,6,1,9,5,4,7,2,8,
        6,5,3,8,4,9,2,1,7,
        9,8,4,1,7,2,6,5,3,
        2,1,7,5,3,6,9,8,4,
        1,3,2,4,6,5,8,7,9,
        5,4,6,7,9,8,1,3,2,
        8,7,9,3,2,1,5,4,6,
    };
    //menuloop
    while (option != 3){
        cout << "\033c";
        cout << "Selecione uma das opções a seguir: \n 1 • Jogar \n 2 • Sobre \n 3 • Fim \n";
        cin >> option;
        switch (option){
        case 1:{
            //case jogo 
            seletor = rand() % 4 + 1;
            acertos = 0;
            //matriz resultado do jogo
            switch (seletor){
        case 1:
            //Sem modificação apenas copia os valores
            for (int i = 0; i < TAM; i++){
                for (int j = 0; j < TAM; j++){
                    matrizJogo[i][j] = matrizMestra[i][j];
                }
            }break;
        case 2:
            //transposta
            for (int i = 0; i < TAM; i++){
                for (int j = 0; j < TAM; j++){
                    matrizJogo[i][j] = matrizMestra[j][i];
                }
            }break;
        case 3:
            //INVERTIDA POR LINHA
            for (int i = 0; i < TAM; i++){
                for (int j = 0; j < TAM; j++){
                    matrizJogo[i][j] = matrizMestra[8-i][j];
                }
            }break;
        case 4:
            // INVERTIDA POR COLUNA
            for (int i = 0; i < TAM; i++){
                for (int j = 0; j < TAM; j++){
                    matrizJogo[i][j] = matrizMestra[i][8-j];
                }
            }break;
        }
            //matriz para as respostas do jogador
            int matrizGabarito[TAM][TAM] = {};
            for (int i = 0; i < 41; i++) {
                linha = rand() % TAM;
                coluna = rand() % TAM;
                if (matrizGabarito[linha][coluna] == 0) {
                    matrizGabarito[linha][coluna] = matrizJogo[linha][coluna];
                } else {
                    i--;
                }
            }
            //variavel pro numero a ser colocado pelo usuario
            int entrada;
            do {
                cout<<"  1 2 3 4 5 6 7 8 9\n"
                <<" +-----+-----+-----+\n";
                for (int i = 0; i < TAM; i++) {
                    cout<<i+1<<"|";
                    for (int j = 0; j < TAM; j++) {
                        //essa linha de baixo provavelmente será retirada adiciona cor usando ASCII o código para chamar ASCII foi passado mas não exatamente as cores
                        
                        if (j<3 && i<3 || j<3 && i>5 || j>5 && i>5 || j>5 && i<3 || j>2 && j<6 && i>2 && i<6){
                            cout<<"\033["<<color<<"m";
                        }else{
                            cout<<"\033["<<0<<"m";
                        }
                        cout << matrizGabarito[i][j];
                        if ((j+1)%3==0){
                            cout<<"\033["<<0<<"m"<<"|";
                        }else{
                            cout<<" ";
                        }

                    }
                    cout << "\n";
                    if ((i+1)%3==0){
                        cout<<" +-----+-----+-----+\n";
                    }

                }
                cout << "Insira em qual linha e coluna você quer colocar\t";
                cin >> linha;
                cin >> coluna;
                if (matrizGabarito[linha - 1][coluna - 1] == 0) {
                    cin >> entrada;
                    if (entrada == matrizJogo[linha - 1][coluna - 1]) {
                        cout << "Acertou"<< "\nPara seguir o jogo pressione Enter";
                        cin.ignore();
                        cout<< cin.get();
                        cout<<"\033c";
                        acertos++;
                        matrizGabarito[linha - 1][coluna - 1] = entrada;
                    } else {
                        cout << "Você errou"
                        << "\nPara seguir o jogo pressione Enter";
                        cin.ignore();
                        cout<< cin.get();
                        cout<<"\033c";
                    }
                } else {
                    cout << "Este Local já está preenchido"<<"\nPara seguir o jogo pressione Enter";
                        cin.ignore();
                        cout<< cin.get();
                        cout<<"\033c";
                }
                //aqui era debug pra ver o que tinha nesse campo da matriz
                //cout << "\n" << matrizGabarito[linha - 1][coluna - 1] << "\n\n";
            } while (acertos < 40);
            if (acertos==40){
                cout<<"Meus Parabéns você venceu!!!"<<"\nPara ir ao menu pressione Enter";
                cin.ignore();
                cout<< cin.get();
                cout<<"\033c";
            }

        }
            break;
        case 2:
            cout<<"\033c";
            cout<<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|                                |                                                           |\n";
            cout<<"|"<<" Esse jogo foi desenvolvido por "<<"|"<<" Regras do jogo                                            "<<"|\n"
            <<"|                                |                                                           |\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|"<<"  Andrey Felsky                 "<<"| Preencher a grade quadriculada com os números de 1 a 9    "<<"|\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|"<<"  Bruno Dalbosco Rover          "<<"|"<<" Não repetir números nas linhas horizontais, verticais ou  "<<"|\n"
            <<"|"<<"                                "<<"|"<<" nos blocos quadrados                                      "<<"|\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|"<<"  Rodrigo Buratto Ribas         "<<"|"<<" O jogo termina quando todas as casas estão preenchidas    "<<"|\n"
            <<"|"<<"                                "<<"|"<<" corretamente                                              "<<"|\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|"<<"  Wallacy Alvarenga             "<<"|"<<"                                                           "<<"|\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n"
            <<"|"<<"  Erick Marlon Mafra            "<<"|"<<"                                                           "<<"|\n"
            <<"+--------------------------------+-----------------------------------------------------------+\n\n\n";
            cout << "Data: novembro/2024 \n"
            << "Professor: Rafael Ballottin Martins / Algoritmos e Programação(24/2) \n"
            << "Para voltar ao menu pressione Enter";
            cin.ignore();
            cout<< cin.get();
            cout<<"\033c";
            break;
        case 3:
            cout<<"Até a proxima :)";
            break;
        default:
            cout << "Opção Inválida";
            break;
        }
    }

}
