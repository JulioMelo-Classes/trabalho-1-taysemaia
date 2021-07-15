#ifndef KENOBET_H
#define KENOBET_H
#include <vector>


class KenoBet {


    private:
        std::vector <unsigned short int> m_spots;  //! números da aposta 
        float m_wage;  //! dinheiro a ser apostado
        std::vector <unsigned short int> random; //! declaraçao para o vetor aleatório 

    public: 
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
        bool set_wage( float wage_ ); 

        //! Redefine uma aposta para um estado vazio.
        void reset( void );

        /*! Recupera o salário do jogador nesta aposta.
             @return o valor do salário. */
        float get_wage( void ) const; 

        /* retorna a quantidade de numeros da aposta do jogador
          @return O número da aposta */
        size_t size( void ) const; 

        /*! Determine quantos pontos correspondem aos acertos passados como argumento.
             @param hits_ Lista de ocorrências escolhidas aleatoriamente pelo computador.
             @return Um vetor com a lista de ocorrências. */
        std::vector <unsigned short int>
        get_hits( const std::vector <unsigned short int> & hits_ ) const;


        /*! Retorne um vetor com os pontos que o jogador escolheu até agora.
             @return O vetor com os pontos do jogador escolhidos até agora.*/
        std::vector <unsigned short int> get_spots( void ) const;

        //<! Função pra imprimir um vetor do tipo <unsigned short int>.
        void print(std::vector <unsigned short int> );

        /*! Retorna o vetor aleatório gerado
          @return o vetor com os 20 numeros aleatorios. */
        std::vector <unsigned short int> get_random( void ) const;


        /*! Cria um vetor aleatorio 
         @param quantidade, quantos números aleatórios deseja criar
         @param min, o número minimo aleatorio possível
         @param max, o número máximo que se pode sortear */
        void vec_rand(int quantidade,int min, int max);


        //! Redefine o vetor aleatório para um estado vazio.
        void reset_random( void );

};


#endif