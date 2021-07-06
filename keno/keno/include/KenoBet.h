#ifndef KENOBET_H
#define KENOBET_H
#include <vector>


class KenoBet {


    private:
        std::vector <unsigned short int> m_spots;  //<! os numeros da aposta
        float m_wage;  //dinheiro

    public: //wage = remuneração
        //! Creates an empty Keno bet.
        KenoBet( ) : m_wage(0)
        { /* empty */ };

        /*!Adiciona um número aos pontos apenas se o número ainda não estiver lá.
      	@param spot_ O número que desejamos incluir na aposta.
     	@return T se o número escolhido for inserido com sucesso; 'F' caso contrário. */
        bool add_number( unsigned short int spot_ );

        /*! Define a quantidade de dinheiro que o jogador está apostando.
             @param wage_ O salário.
             @return True se tivermos um salário acima de zero; caso contrário, false. */
        bool set_wage( float wage_ ); //ok

        //! Redefine uma aposta para um estado vazio.
        void reset( void );

        /*! Recupera o salário do jogador nesta aposta.
             @return O valor do salário. */
        float get_wage( void ) const; //ok

        /*! Retorna ao número atual de posições na aposta do jogador.
             @return Número de pontos presentes na aposta. */
        size_t size( void ) const; //ok

        /*! Determine quantos pontos correspondem aos acertos passados como argumento.
             @param hits_ Lista de ocorrências escolhidas aleatoriamente pelo computador.
             @return Um vetor com a lista de ocorrências. */
        std::vector <unsigned short int>
        get_hits( const std::vector <unsigned short int> & hits_ ) const;


        /*! Retorne um vetor <spot_type> com os pontos que o jogador escolheu até agora.
             @return O vetor <spot_type> com os pontos do jogador escolhidos até agora.*/
        std::vector <unsigned short int> get_spots( void ) const; //ok

           //<! o salário do jogador

        void print(std::vector <unsigned short int> );

        std::vector<unsigned short int> vetor_random(int quantidade,int min, int max);


     };


#endif