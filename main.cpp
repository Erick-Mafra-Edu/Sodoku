#include<iostream>
#include<locale.h>
#define TAM 9
using namespace std;
int main(){
    int seletor;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
    bool tabelaPreenchida = true;
    int cord[2] = {};
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
        cout << "Selecione uma das poções a seguir: \n 1 • Jogar \n 2 • Sobre \n 3 • Fim \n";
        cin >> option;
        switch (option){
        case 1: {
            seletor = rand() % 4;
            //matriz resultado do jogo
            int matrizGabarito[TAM][TAM] = {};
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
                for (int i = 0; i < 41; i++) {
                    int linha = rand() % TAM;
                    int coluna = rand() % TAM;
                    if (matrizGabarito[linha][coluna] == 0) {
                        matrizGabarito[linha][coluna] = matrizJogo[linha][coluna];
                    }
                    else {
                        i--;
                    }
                }
            while (tabelaPreenchida) {
                /* code */
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        cout << matrizGabarito[i][j] << "\t";
                    }
                    cout << "\n";
                }
                cout << "Insira em qual linha e coluna você quer colocar\t";
                cin >> cord[0];
                cin >> cord[1];
                cout << "\n" << matrizGabarito[cord[0]-1][cord[1]-1] << "\n\n";
            }
        }
            break;
        case 2:
            /* sobre */
            break;
        
        default:
            /* opção errada */
            break;
        }
    }
     
}