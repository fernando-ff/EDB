#include <iostream>
#include "../include/sorting.h"
#include "../include/text_color.h"

namespace render
{

    void intro()
    {
        std::string input;
        std::cout << "==========================================================" << std::endl;
        std::cout << "  Welcome to Empirical Analyses" << std::endl;
        std::cout << "  October 2020, made by Fernando Ferreira and Victor Hugo" << std::endl;
        std::cout << "==========================================================\n" << std::endl;
        std::cout << "Press enter to start." << std::endl;
        std::getline(std::cin, input);
    }
   
    void array(array_type * first, array_type * last)
    {
        std::cout << "A = [ ";
        while(first != last)
        {
            std::cout << *first << " ";
            first++;
        }
        std::cout << "];"<< std::endl;
    }

    void guide()
    {
        std::cout << "-------[ALGORITHMS GUIDE LINE]---------\n" << std::endl;
        std::cout << "      0 - Insertion Sort" << std::endl;
        std::cout << "      1 - Selection Sort" << std::endl;
        std::cout << "      2 - Bubble Sort" << std::endl;
        std::cout << "      3 - Shell" << std::endl;
        std::cout << "      4 - Quick Sort" << std::endl;
        std::cout << "      5 - Merge Sort" << std::endl;
        std::cout << "      6 - Radix Sort" << std::endl;    
        std::cout << "      8 - Exit the analyses" << std::endl;
        std::cout << "------------------------------------" << std::endl;   
        std::cout << "\nEnter with a value[0,8] > ";
    }

    void open_file_guide()
    {
          std::cout << "\nBy default the file that stores the data DON'T will be open," << std::endl;
        std::cout << "so if you want open it,enter with 'y' \n" << std::endl;
        std::cout << "The reason for this is because if you open the file" << std::endl;
        std::cout << "the data that it stores will be delete, and so the new data" << std::endl;
        std::cout << "will be store, so just open the file if you run the analyses to the end" << std::endl;
        std::cout << "\nOpen file[y/N]>";
    }
    void header(unsigned short function_idx,unsigned short indx_scn )
    {
        if(function_idx == 0)
        {
            std::cout <<
                ">>> "<< Color::tcolor("Insertion Sort ", Color::GREEN) << 
                "result in the " << 
                Color::tcolor(std::to_string(indx_scn+1), Color::YELLOW) << 
                Color::tcolor("º scneario", Color::YELLOW)
        << std::endl;
        }
    }
    
    void body(  unsigned long int sample,std::chrono::duration<double> result, std::string function, unsigned short int epoch, unsigned short int scn)
    {
        
            std::cout <<
                "      " << Color::tcolor((function), Color::GREEN) <<"    " <<
                "Sample:" << Color::tcolor(std::to_string(sample), Color::BLUE) <<
                Color::tcolor("     scenario ", Color::YELLOW) << scn <<
                "   epoch #" << epoch ;
                if(epoch < 10)
                    std::cout <<" ";

                std::cout << "     Time taken: " <<Color::tcolor(std::to_string(std::chrono::duration <double, std::milli> (result).count()), Color::RED) << Color::tcolor(" ms", Color::RED)   
            << std::endl;
    }

    void help()
    {
        std::cout << "Usage: timing_template [<limit_sample>]" << std::endl;
        std::cout << "By default the sample is equal to 10.000 " << std::endl;
        std::cout << "So if you don't input value the sample limit will be 10.000" << std::endl;
        std::cout << "  Analyses options:" << std::endl;
        std::cout <<"     --help         Print this help text." << std::endl;
    }

} // namespace name


namespace sa {
    value_type * partition(value_type * first, value_type * last)
    {
        // last--;
        value_type * pivot{ last-1 };
        // std::cout << "pivot value: " << *(pivot) << std::endl;
        value_type i{0}, j{1};
        while(first+j != last)
        {
            // render::array(first, last);
            if(*(first+i) < *pivot)
            {
                i++;
            }
            if(*(first+j) < *pivot)
            {
                std::iter_swap(first+i, first+j);
            }            
            j++;
        } 
        std::iter_swap(pivot, first+i);
        // render::array(first, last);

        return first+i;


    }

    void insertion( value_type * first, value_type * last)
    {
        long int size { last - first};
        for (long int i{1}; i < size; i++)
        {   
            value_type key = *(first+i);
            long int j{i-1};
            for (; j>= 0 and *(first+j)> key; j --)
            {
                *(first+j+1) = *(first+j);
            }
            *(first+j+1) = key;
        }
        

    }


  
    void selection( value_type * first, value_type * last)
    {
        for ( auto i = first; i != last - 1; i++) // this first loop go through all elements
        {
            auto min{i}; //the min variable will receive the address and value of each value in the array
            *min = *i;

            for ( auto j = i + 1; j != last; j++) //this second loop gonna go through the array skipping the first one (we assumed this is the lower)
            {
                //if ( cmp( *j, *min ) ) // using the compare function if the value j (remainder of the array) is less than the min
                if ( *j < *min )
                {
                    min = j; //the min receveis j (possible min)
                }
            }//after loop the last min is the lower value of the remainder of the arry

            if (min != i) //if min == i means the element i is the lower in the ramainder array
                std::iter_swap(min, i); //now we swap the min with the first element
        }
    }

    void bubble( value_type * first, value_type * last)
    {
        for ( auto i = first; i != last; i++ ) //go through all elements
        {
            for ( auto j = i + 1; j != last; j++) //compares the element i with all remainders
            {
                //if ( cmp(*j, *i) ) //if the value with the lowset postion in the array is greater swap them
                if (*j < *i)
                {
                    std::swap( *i, *j );
                }
            }
        }
    }

    void shell( value_type * first, value_type * last)
    {
        value_type aux;
        for (value_type gap = (last-first)/2;  gap > 0; gap/=2)
        {
            for (value_type i = gap; i < (last-first); i++)
            {

                aux = *(first+i);
                value_type j = i;
                while(j >= gap and *(first+(j-gap)) > aux )
                {
                    *(first+j) = *(first+(j-gap));
                    j-=gap;
                }
                *(first+j) = aux;
            }      
        }    
    }
    
    void quicksort( value_type * first, value_type * last)
    {
        if( first != last)
        {
            value_type * middle =  sa::partition(first, last);
            quicksort(first, middle);
            quicksort(middle+1, last);
        }

    }
    void merge(
            value_type *first_1,
            value_type *last_1,
            value_type * first_2,
            value_type * last_2
        )
    {
        // if (first_1 == last_1 or first_2 == last_2)
        //     return ;
        value_type l_size = last_1-first_1;
        value_type r_size= last_2-first_2;
        value_type *L = new value_type[l_size];
        value_type *R = new value_type[r_size];

        for (short i{0}; first_1+i != last_1; i++)
        {
            L[i] = *(first_1+i);
        }
        for (short i{0}; first_2+i != last_2; i++)
        {
            R[i] = *(first_2+i);
        }
        
        value_type l{0}, r{0}, k{0};
        while(l < l_size && r < r_size)
        {
            if(L[l] <= R[r])
            {
                *(first_1+k) = L[l];
                l++;
            }
            else
            {
                *(first_1+k) = R[r];
                r++;
            }
            k++;
        }

        while(l < l_size)
        {
            *(first_1+k) = L[l];
            l++;
            k++;
        }
        while(r < l_size)
        {
            *(first_1+k) = R[r];
            r++;
            k++;
        }
        delete L;
        delete R;
    }
    
    void mergesort( value_type * first, value_type * last)
    {

        if((last - first) > 1)
        {
            value_type middle = ((last - first)/2);

            mergesort(first, first+middle);

            mergesort(first+middle, last);

            merge(first, first+middle, first+middle, last);
        }
    }

    void radix(value_type *first, value_type *last)
    {
        value_type  max { *first };
        for (short i{1}; i < (last-first); i++)
        {
            // std::cout << *(first+i) << std::endl;
            if(*(first+i) > max)
                max = *(first+i);
        }

        for (value_type exp = 1; (max/exp) > 0 and exp > 0; exp*=10)
        {
            value_type output[last-first];
            value_type count[10]{0,0,0,0,0,0,0,0,0,0};
            value_type i;
            for ( i = 0; i < last - first; i++)
            {
                count[(*(first+i)/exp)%10]++;   
            }

            for ( i = 1; i < 10; i++)
            {
                count[i] += count[i -1];
            }
            for (value_type i = last - first -1; i >= 0; i--)
            {
                if(i > last - first)
                    break;
                int index= (*(first+i)/ exp)%10 ;
                output[count[index] -1] = *(first+i);
                count[index] --;
            }

            for ( i = 0; i < last-first; i++)
            {
                *(first+i) = output[i];
            }
        }                
    }


}

namespace scenario
{
    void first( array_type *first, array_type * last)
    {
        for (unsigned int i = 0; first+i != last; i++)
        {
            *(first+i) = i;

        }
        
    }
    
    void second( array_type * first, array_type * last)
    {
        for ( unsigned int  i = 0; first != last; i++)
        {
            last--;
            *last = i;
        }
        
    }
    
    void third( array_type * first, array_type * last)
    {
        srand (time(NULL));
        int randomic_value;
        while(first != last)
        {
            randomic_value = rand() % 100000;
            randomic_value -= 10000;
            *first = randomic_value;
            first++;
        }

    }
    
    void fourth( array_type * first, array_type * last)
    {
        scenario::first(first, last);
        long int size { last - first };
        // std::cout << "SIZE:" << size << std::endl;;
        // array_type * I = new array_type[size];
        array_type I[size];

        // render::array(I, I+10);
        
        std::copy(first, last, I);
        // render::array(I, I+10);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(I, I+size, g);
        
        // render::array(I, I+10);
   
        for (long int i = 0; i < (0.25*size); i+= 2)
        {
            std::iter_swap( (first+(I[i])) , (first+(I[i+1])) );
        }
        
        
    }
    
    void fifth ( array_type * first, array_type * last)
    {
        scenario::first(first, last);
        long int size { last - first };
        // std::cout << "SIZE:" << size << std::endl;;
        // array_type * I = new array_type[size];
        array_type I[size];

        // render::array(I, I+10);
        
        std::copy(first, last, I);
        // render::array(I, I+10);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(I, I+size, g);
        
        // render::array(I, I+10);
   
        for (long int i = 0; i < (0.75*size); i+= 2)
        {
            std::iter_swap( (first+(I[i])) , (first+(I[i+1])) );
        }
        
    }
    
    void sixth( array_type * first, array_type * last)
    {
        scenario::first(first, last);
        long int size { last - first };
        // std::cout << "SIZE:" << size << std::endl;;
        // array_type * I = new array_type[size];
        array_type I[size];

        // render::array(I, I+10);
        
        std::copy(first, last, I);
        // render::array(I, I+10);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(I, I+size, g);
        
        // render::array(I, I+10);
   
        for (long int i = 0; i < (0.5*size); i+= 2)
        {
            std::iter_swap( (first+(I[i])) , (first+(I[i+1])) );
        }
    }
} // namespace name
