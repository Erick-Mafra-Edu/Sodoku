//Executar em IDE linux (replit ou opengdb)
#include<iostream>
#include<locale.h>
#include <time.h>
#define TAM 9
using namespace std;
int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int seletorCheck, acertos, jogadas = 0, seletor = 1, color = 93, option = 0, linha, coluna, matrizJogo[TAM][TAM],matrizGabarito[TAM][TAM] = {} ,encontrados = 0, entrada,
    matrizMestra[TAM][TAM] = {
      {4, 9, 5, 2, 8, 7, 3, 6, 1},
      {7, 2, 8, 6, 1, 3, 4, 9, 5},
      {3, 6, 1, 9, 5, 4, 7, 2, 8},
      {6, 5, 3, 8, 4, 9, 2, 1, 7},
      {9, 8, 4, 1, 7, 2, 6, 5, 3},
      {2, 1, 7, 5, 3, 6, 9, 8, 4},
      {1, 3, 2, 4, 6, 5, 8, 7, 9},
      {5, 4, 6, 7, 9, 8, 1, 3, 2},
      {8, 7, 9, 3, 2, 1, 5, 4, 6}
    };
    //menuloop
    do{
        cout << "\033c";
        cout << "Selecione uma das opções a seguir: \n 1 • Jogar ▷\n 2 • Sobre ⁉️\n 3 • Fim 𝕏\n";
        cin >> option;
        switch (option){
        case 1:{
            //vertifica se a posição ja foi usada
            seletorCheck = rand() % 4 + 1;
            while (seletorCheck == seletor){
                seletorCheck = rand() % 4 + 1;
            }
            seletor = seletorCheck;
            acertos = 0;
            //matriz resultado do jogo
            switch (seletor){
                case 1:
                    //Sem modificação apenas copia os valores
                    for (int i = 0; i < TAM; i++){
                        for (int j = 0; j < TAM; j++){
                            matrizJogo[i][j] = matrizMestra[i][j];
                        }
                    }
                break;
                case 2:
                    //transposta
                    for (int i = 0; i < TAM; i++){
                        for (int j = 0; j < TAM; j++){
                            matrizJogo[i][j] = matrizMestra[j][i];
                        }
                    }
                break;
                case 3:
                    //INVERTIDA POR LINHA
                    for (int i = 0; i < TAM; i++){
                        for (int j = 0; j < TAM; j++){
                            matrizJogo[i][j] = matrizMestra[8-i][j];
                        }
                    }
                break;
                case 4:
                    // INVERTIDA POR COLUNA
                    for (int i = 0; i < TAM; i++){
                        for (int j = 0; j < TAM; j++){
                            matrizJogo[i][j] = matrizMestra[i][8-j];
                        }
                    }
                break;
            }

            //preenche a matriz para o jogo
            while(encontrados < 41){
                linha = rand() % TAM;
                coluna = rand() % TAM;
                if (matrizGabarito[linha][coluna] == 0) {
                    matrizGabarito[linha][coluna] = matrizJogo[linha][coluna];
                    encontrados++;
                }
            }

            do {
                cout<<"  0 1 2 3 4 5 6 7 8\n"
                <<" +-----+-----+-----+\n";
                for (int i = 0; i < TAM; i++) {
                    cout<<i<<"|";
                    for (int j = 0; j < TAM; j++) {
                        //muda a cor das matrizes
                        if ( (j < 3 && i < 3) || (j < 3 && i > 5) || (j > 5 && i > 5) || (j > 5 && i < 3) || ((j > 2) && (j < 6) && (i > 2) && ( i < 6))){
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
                //solicita a entrada dos valores
                cout << "Insira em qual linha você quer colocar\n";

                //define o valor da linha e valida se atende a matriz
                cin >> linha;
                while(linha >= TAM || linha < 0){
                    cout << "Valor para a linha digitada está invalida, por favor selecione um valor de 0 a " << (TAM - 1) << "\n";
                    cin >> linha;
                }
                cout << "Insira em qual coluna você quer colocar\n";

                //define o valor da coluna e valida se atende a matriz
                cin >> coluna;
                while(coluna >= TAM || linha < 0){
                    cout << "Valor para a coluna digitada está invalida, por favor selecione um valor de 0 a " << (TAM - 1) << "\n";
                    cin >> coluna;
                }

                //verifica se o valor da matriz ja foi preenchido
                if (matrizGabarito[linha][coluna] == 0) {
                    //define o valor a ser validade da matriz
                    cout << "Insira o valor que você quer colocar para: (" << linha << "X" << coluna << ") \t";
                    cin >> entrada;

                    //verificas se o valor digitado esta valido
                    if (entrada == matrizJogo[linha][coluna]) {
                        cout << "Acertou"<< "\nPara seguir o jogo pressione Enter";
                        cin.ignore();
                        cout<< cin.get();
                        cout<<"\033c";
                        acertos++;
                        matrizGabarito[linha][coluna] = entrada;
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
                jogadas++;
            } while (acertos < 40);
            cout<<"Meus Parabéns você venceu em "<< jogadas << " jogadas!!!"<<"\nPara ir ao menu pressione Enter";
            cin.ignore();
            cout<< cin.get();
            cout<<"\033c";
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
    }while (option == 3);

}

//Equipe de desenvolvimento

// Andrey Felsky
// 8273782
// andreyfelsky@edu.univali.br

// Bruno Dalbosco Rover
// 8314144
// bruno.8314144@edu.univali.br

// Erick Marlon Mafra 
// 8315728
// erick.8315728@edu.univali.br

// Rodrigo Buratto Ribas
// 8330999
// rodrigo.8330999@edu.univali.br

// Wallacy Alvarenga
// 6916694
// wallacyalvarenga@univali.br
