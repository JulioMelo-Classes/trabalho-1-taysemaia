    #include "../include/KenoBet.h"
    using namespace std;
    #include <ostream>
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <bits/stdc++.h>


    /*!
    * ... Aqui temos as implementações dos métodos da classe KenoBet ...
    */



    /*! Recupera o salário do jogador nesta aposta.
        @return o valor do salário. */
    float KenoBet::get_wage( void ) const{  // OK

        return m_wage;

    }

    /*! Define a quantidade de dinheiro que o jogador está apostando.
        @param wage_ O salário.
        @return True se tivermos um salário acima de zero; caso contrário, false. */
    bool KenoBet::set_wage( float wage_ ){
        m_wage = wage_;

        if(m_wage > 0){

        return true;

        }

        else{
            return false;
        }
    }
    /*! Retorne um vetor com os pontos que o jogador escolheu até agora.
        @return O vetor com os pontos do jogador escolhidos até agora.*/
    std::vector <unsigned short int> KenoBet::get_spots( void ) const{ 
       
        return m_spots;
    }

    /*! Retorna o vetor aleatório gerado
        @return o vetor com os 20 numeros aleatorios. */
    std::vector <unsigned short int> KenoBet::get_random( void ) const{ 
       
        return random;
    }

    /*! Cria um vetor aleatorio 
        @param quantidade, quantos números aleatórios deseja criar
        @param min, o número minimo aleatorio possível
        @param max, o número máximo que se pode sortear */
    void KenoBet::vec_rand(int quantidade,int min, int max) { 
        int i = 0, num_rand = 0;
        srand(time(NULL));

        while(i < quantidade) {

            num_rand = rand() % (max - min + 1) + min;
            random.push_back(num_rand);
            i++;
        }
    }


    //! Redefine o vetor aleatório para um estado vazio.
    void KenoBet::reset_random( void ){
        random.clear();
    }


    /* retorna a quantidade de numeros da aposta do jogador
        @return O número da aposta */
    size_t KenoBet::size( void ) const{ 
      return m_spots.size();
    }   

    /*!Adiciona um número aos pontos apenas se o número ainda não estiver lá.
      @param spot_ O número que desejamos incluir na aposta.
      @return T se o número escolhido for inserido com sucesso; 'F' caso contrário. */
    bool KenoBet::add_number( unsigned short int spot_ ){
        std::vector<unsigned short int>::iterator it;
        if(spot_ >= 1 && spot_ <= 80){
            it = std::find(m_spots.begin(), m_spots.end(), spot_);
            if (it != m_spots.end()){

               return false;
               
            }
            else{
                m_spots.push_back(spot_);
               return true;
            }
        }
        else{

            return false;
        }
        
    }

    //! Redefine uma aposta para um estado vazio.
    void KenoBet::reset( void ){
        m_spots.clear();
    }


    /*! Determine quantos pontos correspondem aos acertos passados como argumento.
        @param hits_ Lista de ocorrências escolhidas aleatoriamente pelo computador.
        @return Um vetor com a lista de ocorrências. */
    std::vector <unsigned short int> KenoBet::get_hits( const std::vector <unsigned short int> & hits_ ) const{

        return m_spots;
    }

    //<! Função pra imprimir um vetor do tipo <unsigned short int>.
    void KenoBet::print( std::vector <unsigned short int> m_spots){ 

        for(auto i:m_spots){
            cout << i <<" ";
        }

    }
