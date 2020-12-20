/**
 * @file hashtbl.h
 * @author Fernando Ferreira 
 * @author Vitor Hugo
 * @brief Trabalho feito na disciplina de EDB 1 ministrada pelo professor SELAN
 * @version 0.1
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _HASHTBL_H_
#define _HASHTBL_H_

#include <iostream>
#include <forward_list> // forward_list
#include <exception>

using namespace std;

namespace ac {

    template<class KeyType, class DataType>
    class HashEntry
    {
        public:

            KeyType m_key;  // Armazena a chave associada a informcao
            DataType m_data;// A informacao.

            HashEntry( KeyType kt_, DataType dt_ ) 
                : m_key(kt_)
                , m_data(dt_)
            {/*Empty*/}
    };

    template< class KeyType, class DataType, typename keyHash = std::hash<KeyType>, typename keyEqual = std::equal_to<KeyType>>
    class HashTbl
    {
        public:
            // Aliases
            using entry_type = HashEntry<KeyType,DataType>;
            using list_type = std::forward_list< entry_type >;
            using size_type = std::size_t;
            /**
             * @brief Constroi um novo objeto Hash Tbl 
             * 
             * @param TableSz_ tamanho desejado da tabela 
             */
            explicit HashTbl( int TableSz_ = DEFAULT_SIZE ) 
                :m_size(TableSz_)
                ,m_count(0)
            { 
                while(not is_prime(m_size)) 
                    m_size++;
                m_data_table = new std::forward_list<entry_type>[m_size];
            }
            /**
             * @brief Constroi um novo objeto Hash Tbl 
             * 
             * @param other tabela que sera usada como modelo para con 
             */
            HashTbl( const HashTbl& other)
                :m_size(other.m_size)
                ,m_count(other.m_count)
                ,m_data_table(new std::forward_list<entry_type>[m_size])
            {   
                for(size_t i{0}; i<m_size; i++)
                    m_data_table[i] = other.m_data_table[i];
            }
            HashTbl( const std::initializer_list< entry_type >& il)
                :m_size(il.size())
                ,m_count(0)
                ,m_data_table(new std::forward_list<entry_type>[m_size])
            {
                for(auto it{il.begin()}; it != il.end(); it++)
                    insert(it->m_key, it->m_data);
            }
            /**
             * @brief copia a hash table 
             * 
             * @param other hash table que sera copiada
             * @return HashTbl& endereço de memoria para esta hash table
             */
            HashTbl& operator=( const HashTbl& other)
            {
                clear();
                delete[] m_data_table;

                m_size = other.m_size;
                m_count = other.m_count;
                m_data_table = new std::forward_list<entry_type>[m_size];

                for(size_t i{0}; i < m_size; i++)
                    m_data_table[i] = other.m_data_table[i];
                return *this;
            }
            /**
             * @brief copia a lista il para a tabela
             * 
             * @param il lista inicializadora
             * @return HashTbl& endereço de memoria para esta hash table
             */
            HashTbl& operator=( const std::initializer_list< entry_type > &il )
            {
                delete[] m_data_table;

                m_size = il.size();
                m_count=0;
                m_data_table = new std::forward_list<entry_type>[m_size];

                for(auto it=il.begin(); it != il.end(); it++)
                    insert(it->m_key, it->m_data);
                return *this;
            }
            /**
             * @brief Destruidor da classe que libera a mem´oria
             * 
             */
            virtual ~HashTbl() { delete[] m_data_table ;}
            /**
             * @brief Insere na tabela a informação contida em d_ e associada a uma chave k_ .
             * 
             * @param key  chave k_ .
             * @param data data que será inserido
             * @return true  Se a inserção foi realizada com sucesso
             * @return false  Se a inserção não foi realizada com sucesso
             */
            bool insert( const KeyType & key, const DataType & data )
            {
                keyHash hash_function;
                keyEqual equal_function;

                auto end = hash_function(key) % m_size;
                
                entry_type new_entry(key, data);

                for(auto it = m_data_table[end].begin(); it != m_data_table[end].end(); it++)
                {
                    if(equal_function(it->m_key, new_entry.m_key))
                    {
                        it->m_data = data;
                        return false;
                    }
                }
                m_count++;
                m_data_table[end].push_front(new_entry);
                return true;
            }
            /**
             * @brief Recupera em d_ a informação associada a chave k_ passada como argumento para o metodo. 
             * 
             * @param key a chave  passada como argumento para o metodo
             * @param data a informação associada a chave
             * @return true  Se a chave for encontrada o metodo
             * @return false Caso contrário
             */
            bool retrieve( const KeyType &key, DataType &data ) const
            {   
                keyHash hash_function;
                keyEqual equal_function;

                auto end = hash_function(key) % m_size;

                for(auto it = m_data_table[end].begin(); it != m_data_table[end].end(); it++)
                {
                    if(equal_function(it->m_key, key))
                    {
                        data = it->m_data;
                        return true;
                    }
                }
                return false;
            }
            /**
             * @brief Remove um item de tabela identificado por sua chave k_ .
             * 
             * @param key chave k_ 
             * @return true Se a chave for encontrada 
             * @return false Se a chave não for encontrada 
             */
            bool erase( const KeyType & key )
            {
                keyHash hash_function;
                keyEqual equal_function;

                auto begin = hash_function(key) % m_size; // Demarca ql posicao da array a key leva através do hashing

                for(auto &it : m_data_table[begin]) // Percorre a lista que esta dentro da posicao
                {
                    if(equal_function(it.m_key, key))
                    {
                        it.m_key = KeyType(); // limpa os valores colocando um valor "vazio" e "corrige o contador"
                        it.m_data = DataType();
                        m_count--;
                        return true;
                    }
                }

                return false;
            }
            /**
             * @brief Limpa (apaga) toda a memória associada às listas de colisão da tabela, removendo todos seus elementos
             * 
             */
            void clear()
            {
                for(size_t i{0}; i<m_size; i++)
                    m_data_table[i].clear();
                m_count = 0;
            }
            /**
             * @brief Retorna true se a tabela de dispersão estiver vazia, ou false caso contrário.
             * 
             * @return true se a tabela de dispersão estiver vazia
             * @return false caso não esteja vazia.
             */
            bool empty() const { return m_count == 0; }
            /**
             * @brief Retorna a quantidade de elemento atualmente armazenados na tabela.
             * 
             * @return size_type quantidade de elemento atualmente armazenados na tabela.
             */
            inline size_type size() const { return m_count; }
            /**
             * @brief Retorna uma referência para o dado associado a chave k_ fornecida.
             * 
             * @param key chave k_
             * @return DataType& referência para o dado associado a chave k_
             */
            DataType& at( const KeyType& key )
            {
                //instanciando função hash e função de comparação 
                keyHash hash_function;
                keyEqual equal_function;

                auto begin = hash_function(key) % m_size;//pegando a posição na tabela hash 

                //verificando cada elemento na posição da tabela hash
                for(auto &e : m_data_table[begin])
                {
                    if (equal_function(key, e.m_key))//caso exista algum elemento na "linha" com a chave igual a passada no parametro da função  
                        return e.m_data;//retorna o dado desse local de memoria
                }
                //em caso de não haver chave compativel retorna uma exception 
                throw std::out_of_range("out of range");
            }
            /**
             * @brief  Retorna uma referência para o dado associado a chave k_ fornecida, se existir
             * 
             * @param key chave k_
             * @return DataType& referência para o dado associado a chave k_
             */
            DataType& operator[]( const KeyType& key)
            {
                keyHash hash_functor;
                keyEqual equal_functor;

                auto end = hash_functor(key) % m_size;

                for(auto &e : m_data_table[end])
                {
                    if(equal_functor(e.m_key, key))
                        return e.m_data;
                }

                DataType dt = DataType();  
                entry_type entry(key, dt);

                m_count++;
                m_data_table[end].push_front(entry);

                return m_data_table[end].front().m_data;
                
            }
            /**
             * @brief Retorna a quantidade de elementos da tabela que est˜ao na lista de colis˜ao associada a chave k_ .
             * 
             * @param key chave k_
             * @return size_type quantidade de elementos da tabela que est˜ao na lista de colis˜ao associada a chave k_ .
             */
            size_type count( const KeyType &key ) const
            {
                keyHash hash_function;
                size_t count = 0;
                auto k_ = hash_function(key) % m_size;

                for ( auto it = m_data_table[k_].begin(); it != m_data_table[k_].end(); it++)
                {
                    count++;
                }

            return count;
            }
            /**
             * @brief método de depuração usado apenas para gerar uma representação textual da tabela e seus elementos
             * 
             * @param os_ ostream para 
             * @param ht_ tabela hash
             * @return std::ostream& 
             */
            friend std::ostream & operator<<( std::ostream & os_, const HashTbl & ht_ )
            {
                for (size_t i = 0; i < ht_.m_size; i++) // Acessa cada ponto do array
                {
                    std::cout << "[" << i << "] -> ";
                    if ( ht_.m_data_table[i].empty())
                        std::cout << " " <<std::endl;

                    else
                    {
                        for(auto &it : ht_.m_data_table[i]) // Acessa cada node list
                            os_ << it.m_data << " ";
                    }
                    std::cout << std::endl;

                }
                return os_;
            }

            int resize_as_prime(int size)
            {
                size = size * 2; // Dobra o tamanho pra depois procurar o primo mais proximo
                bool isPrime = false;
                while ( isPrime == false )
                {
                    int div_count = 0;
                    for (int i = 1; i < size; i++)
                    {
                        if (size % i == 0)
                            div_count++;
                    }
                    if (div_count == 1)
                        isPrime = true;
                    else
                        size++;
                }
                return size;
            }

            //=== Private methods
        private:
            /**
             * @brief Este método vai criar uma nova tabela cujo tamanho será igual ao menor número primo >= que o dobro do tamanho da tabela antes da chamada rehash()
             * 
             */
            void rehash()
            {
                int new_m_size = resize_as_prime(m_size);
                HashTbl< KeyType, DataType, keyHash, keyEqual > temp_hash_table{new_m_size}; // Cria tabela hash temproraria

                for (size_t i = 0; i < m_size; i++)
                {
                    for(auto &it : m_data_table[i])
                    {
                        temp_hash_table.insert(it.m_key, it.m_data); // Preenche a tabela temporaria
                    }

                }
                // Faz as trocas pra definitiva com novo tamanho deletando no final
                this->clear();
                delete[] m_data_table;
                m_data_table = temp_hash_table.m_data_table;
                m_size = new_m_size;
                m_count = temp_hash_table.m_count;
                delete[] temp_hash_table;
            }   
            //=== Private members
        private:

            unsigned int m_size;  //!< Tamanho da tabela.
            unsigned int m_count; //!< Numero de elementos na tabel. 
            std::forward_list< entry_type > *m_data_table; //!< Tabela de listas para entradas de tabela.
            // std::unique_ptr< std::forward_list< entry_type > [] > m_data_table;
            static const short DEFAULT_SIZE = 11;
            /**
             * @brief verifica se o valor passado é primo
             * 
             * @param tableSize_ valor que será verificado se é primo ou não
             * @return true caso seja primo
             * @return false caso não seja primo
             */
            bool is_prime(size_t tableSize_)
            {
                if(tableSize_ <= 1)
                    return false;
                for(size_t i{2}; i < tableSize_; i++)
                {
                    if(tableSize_ % i == 0)
                        return false;
                }

                return true;

            }
    };

} // MyHashTable
// #include "hashtbl.inl"
#endif











