    #include "../include/KenoBet.h"
    using namespace std;
    #include <ostream>
    #include <iostream>
    #include <vector>
    #include <algorithm>



    float KenoBet::get_wage( void ) const{  // OK

        return m_wage;

    }


    bool KenoBet::set_wage( float wage_ ){
        m_wage = wage_;

        if(m_wage > 0){

        return true;

        }

        else{
            return false;
        }
    }

    std::vector <unsigned short int> KenoBet::get_spots( void ) const{ 
       
        return m_spots;
    }


    std::vector<unsigned short int> KenoBet::vetor_random(int quantidade,int min, int max) { // gerar o vetor de numeros aleatorios
        std::vector<unsigned short int> random;
        int i = 0, num_rand = 0;
        srand(time(NULL));

        while (i < quantidade) {

            num_rand = rand() % (max - min + 1) + min;
            random.push_back(num_rand);
            i++;
        }

        return random;
    }


    size_t KenoBet::size( void ) const{  // retorna o tamanho do vetor m_spots
      return m_spots.size();
    }   

    /*      Adiciona um número aos pontos apenas se o número ainda não estiver lá.
            spot_ é o número que desejamos incluir na aposta.
            return T se o número escolhido for inserido com sucesso; 'F' caso contrário. */

    bool KenoBet::add_number( unsigned short int spot_ ){
        if(spot_ >= 1 && spot_ <= 80){
            if (std::find(m_spots.begin(), m_spots.end(), spot_) != m_spots.end()){
               
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


    // Redefine uma aposta para um estado vazio.
    void KenoBet::reset( void ){
        m_spots.clear();
    }


    /*Determine quantos pontos correspondem aos acertos passados como argumento.
    @param hits_ Lista de ocorrências escolhidas aleatoriamente pelo computador.
    @return Um vetor com a lista de ocorrências. */
    std::vector <unsigned short int>
    KenoBet::get_hits( const std::vector <unsigned short int> & hits_ ) const{

        return m_spots;
    }


    void KenoBet::print( std::vector <unsigned short int> m_spots){ // função pra printar um vector

        for(auto i:m_spots){
            cout << i <<" ";
        }

    }
