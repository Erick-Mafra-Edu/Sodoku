#include<iostream>
#include<locale.h>
#define TAM 9
using namespace std;
int main(){
    int seletor,acertos=0;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
    int linha, coluna;
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
            seletor = rand() % 4;
            //matriz resultado do jogo
            int matrizJogo[TAM][TAM] = {
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
            /* jogo */
            //matriz para as respostas do jogador
            int matrizGabarito[TAM][TAM] = {};
            for (int i = 0; i < 41; i++) {
                linha = rand() % TAM;
                coluna = rand() % TAM;
                if (matrizGabarito[linha][coluna] == 0) {
                    matrizGabarito[linha][coluna] = matrizJogo[linha][coluna];
                }
                else {
                    i--;
                }
            }
            int entrada;
            do {
                /* code */
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        cout << matrizGabarito[i][j] << "\t";
                    }
                    cout << "\n";
                }
                cout << "Insira em qual linha e coluna você quer colocar\t";
                cin >> linha;
                cin >> coluna;
                if (matrizGabarito[linha - 1][coluna - 1] == 0) {
                    cin >> entrada;
                    if (entrada == matrizJogo[linha - 1][coluna - 1]) {
                        cout << "Acertou";
                        acertos++;
                        matrizGabarito[linha - 1][coluna - 1] = entrada;
                    } else {
                        cout << "Você errou";
                    }
                } else {
                    cout << "Este Local já está preenchido";
                }
                cout << "\n" << matrizGabarito[linha - 1][coluna - 1] << "\n\n";
            } while (acertos < 40);
        }
            break;
        case 2:
            cout << "Sobre";
            break;
        
        default:
            cout << "Opção Invalida";
            break;
        }
    }
     
}
