#include <iostream>
#include <fstream>
#include "../include/KenoBet.h"
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]){


  KenoBet keno;
  std::string rodadas, dinheiro, num_aposta;
  int i, irodadas, total = 20, minimo = 1, maximo = 80;
  stringstream ss1, ss2, ss3;
  float aux, dinheiro_por_rodada;

  const double PAYOFF_TABLE[15][16] = {
  {0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
  {0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
  {0, 1, 2, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
  {0, 0.5, 2, 6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12},
  {0, 0.5, 1, 3, 15, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50},
  {0, 0.5, 1, 2, 3, 30, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75},
  {0, 0.5, 0.5, 1, 6, 12, 36, 100, 100, 100, 100, 100, 100, 100, 100, 100},
  {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720, 720, 720, 720, 720, 720, 720, 720},
  {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200, 1200, 1200, 1200, 1200, 1200, 1200},
  {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800, 1800, 1800, 1800, 1800, 1800},
  {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000, 3000, 3000, 3000, 3000},
  {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000, 4000, 400, 4000},
  {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000, 6000, 6000},
  {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500, 7500},
  {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};

	std::ifstream arquivo_entrada(argv[1]);
	
  cout << ">>> Lendo arquivo de apostas " << argv[1] << ", por favor, aguarde..." << endl;
  cout << "--------------------------------------------------------------" << endl;

  if(!arquivo_entrada.is_open()){ //! Testa se o arquivo existe ou não
    std::cout << ">>> Arquivo não existe." << std::endl;

    return 1;
  }

  else{

    for(i = 0; i < 3; i++){ //! For 3 vezes, pois o arquivo só possui 3 linhas de entrada

      if(i == 0){
        
        /*!
        * ... Lê a primeira linha do arquivo e armazena em uma variável auxiliar e...
        * ....testa se a aposta é válida.
        */

        getline(arquivo_entrada, dinheiro); //!      
        ss1 << dinheiro;
        ss1 >> aux;

        if(keno.set_wage(aux) == true){
          cout << ">>> Aposta lida com sucesso!"<< endl;
          cout << " Você apostará um total de R$" << keno.get_wage() << " créditos." << endl;
        } 

        else{
           cout << " Aposta inválida (R$0.00)" << endl;
           return 1;
        }
       
      }

      else if(i == 1){// 2 linha do arquivo
        /*!
        ... Lê a segunda linha do arquivo, armazena em uma variável e faz o calculo de quanto
            por rodada o jogador vai gastar...
        */
        getline(arquivo_entrada, rodadas);
        ss2 << rodadas;
        ss2 >> irodadas;
        dinheiro_por_rodada = keno.get_wage() / irodadas;

        cout << " Jogará um total de "<< irodadas << " rodadas, apostando R$" << dinheiro_por_rodada << " créditos por rodada." << endl;
      }

      else if(i == 2){// 3 linha do arquivo
        
         /*!
        ... Lê a terceira linha do arquivo, armazena cada valor em uma variável e vai adicionando
            ao vetor através da função add_number...
        */
        getline(arquivo_entrada, num_aposta);
        ss3 << num_aposta;
        
        for(i = 0; i < 15; i++) {
          unsigned short int x = 0;

          ss3 >> x;
          
          keno.add_number(x);
        }

        
      }
    }


    cout << " Sua aposta tem " << keno.size() << " números e eles são [ ";
    keno.print(keno.get_spots()); 
    cout << "]" << endl;

    cout << "--------+--------" << endl;
    cout << "HITS  |  RETORNO" << endl;

    for(size_t j = 0; j <= keno.size(); j++){
      cout << j << "     |  " << PAYOFF_TABLE[keno.size() - 1][j] << endl;
    }
    cout << "------------------------"<< endl;

    for(i = 1; i <= irodadas; i++){
      cout << " Essa é a rodada #" << i << " de " << irodadas << ", sua aposta é R$" << dinheiro_por_rodada << ". Boa sorte!"<< endl;
      cout << " Os números sorteados são: " << endl;
      keno.vec_rand(total, minimo, maximo); 
      keno.print(keno.get_random());
      keno.reset_random();
      cout << endl;
    }
    
    

    cout << "------------------------"<< endl;
    cout << "===== Sumário =====" << endl;
    cout << ">>> Você gastou um total de R$"<< keno.get_wage() << " créditos." << endl;
    cout << ">>> Hooray! você ganhou R$ xxxx" << " créditos." << endl;
    cout << ">>> Você está saindo do jogo com um total de R$ xxx" << " créditos." << endl;
  }



  arquivo_entrada.close();



	return 0;
}




