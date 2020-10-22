/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>

#include "../include/sorting.h"

using namespace sa;
using namespace scenario;

int main(int argc, char* argv[])
{
    unsigned int limit_sample { 100000 };// limit sample

    if(argc > 1)
    {
        if(strcmp(argv[1],"--help") == 0)// Reading command line arguments
        {
            render::help();
            return EXIT_SUCCESS;
        }
        else
            limit_sample = std::stoi(argv[1]);
    }

    unsigned int* arr = new unsigned int[1000000]; //array that will contain the samples
    // unsigned long int sample { 10000 }; // default sample value
    unsigned long int sample { 1000 };
    unsigned long int sample_backup { sample };
    unsigned short int indx_algth { 0 };//index of algorithm analyses
    unsigned short int indx_scn { 0 };// index of scenario analyses
    
    std::chrono::duration<double> avarege_time;
    std::chrono::duration<double> avarege_time_backup;

    std::string file_path[6]
    {
        "../data/1-scenario/",
        "../data/2-scenario/",
        "../data/3-scenario/",
        "../data/4-scenario/",
        "../data/5-scenario/",
        "../data/6-scenario/"
    };
    std::string files_name[7]
    {
        "insertion_sort.data",
        "selection_sort.data",
        "bublle_sort.data",
        "shell_sort.data",
        "quick_sort.data",
        "merge_sort.data",
        "radix sort"

    };

    unsigned short int execution { 1 };// counter of executions

    std::string algorithm_name[7] 
    {
        "Insertion Sort",
        "Selection Sort",
        "Bubble Sort",
        "Shell Sort",
        "Quick Sort",
        "Merge Sort",
        "Radix Sort"
    };
    
    void (*scenario_functions[6]) (array_type * first, array_type *last);
        scenario_functions[0] = first;
        scenario_functions[1] = second;
        scenario_functions[2] = third;
        scenario_functions[3] = fourth;
        scenario_functions[4] = fifth;
        scenario_functions[5] = sixth;
    
    void (*sort_algorithms[7]) (value_type *first, value_type * last);
        sort_algorithms[0] = insertion;
        sort_algorithms[1] = selection;
        sort_algorithms[2] = bubble;
        sort_algorithms[3] = shell;
        sort_algorithms[4] = quicksort;
        sort_algorithms[5] = mergesort;
        sort_algorithms[6] = radix;
    
    bool open_file { false };
    char input_file;
    unsigned short input;
    render::intro();

    while (true)
    {
        render::guide();
        std::cin.clear();
        std::cin >> input;
        indx_algth = input;

        if(indx_algth == 8)
            break;
        render::open_file_guide();
        std::cin.clear();
        std::cin>> input_file;

        if(input_file == 'y')
            open_file = true;
        else
            open_file = false;
        
        auto start_all_analyses = std::chrono::steady_clock::now();
        
        indx_scn = 0;
        std::ofstream file;

        while(indx_scn < 6)
        {
            if(open_file)
            {
                file.open(file_path[indx_scn] + files_name[indx_algth]);
                std::cout << ">>> File name: " << file_path[indx_scn] + files_name[indx_algth] << std::endl; 
                if(file.is_open())
                {
                    std::cout << ">>> Open with sucess!" << std::endl;
                    std::cout << "This will cost a time, so... make a coffe, read a book! And after look  here!" << std::endl;
                }
                else
                {
                    std::cout << ">>> We cannot open this file, I'm sorry" << std::endl;
                    std::cout << " Try again!" << std::endl;
                    return EXIT_SUCCESS;            
                }
            }
            sample = sample_backup;
            while( sample <= limit_sample)
            {
                avarege_time = avarege_time_backup;
                execution = 1;
                while(execution <= 50)
                {
                    (*scenario_functions[indx_algth]) (arr, arr+sample);
            
                    auto start = std::chrono::steady_clock::now();
            
                        (*sort_algorithms[indx_algth]) (arr, arr+sample);
            
                    auto end = std::chrono::steady_clock::now();        
            
                    std::chrono::duration<double> time_taken = end - start;
            
                    // render::body( sample,time_taken, algorithm_name[indx_algth], execution, indx_scn+1);
                         
                    avarege_time += ((time_taken - avarege_time)/execution);
                    execution++;
                }
                render::body( sample,avarege_time, algorithm_name[indx_algth], execution, indx_scn+1);
                file << sample << "\t" << std::chrono::duration <double, std::milli> (avarege_time).count() << std::endl;;
                sample +=  4 * 1000;
            }
            file.close();
            indx_scn++;
        }
        auto end_all_analyses = std::chrono::steady_clock::now();  
        std::chrono::duration<double> time_taken_all_analyses = end_all_analyses - start_all_analyses;
        std::cout << "\nAll analyses costed [" << std::chrono::duration <double, std::milli> (time_taken_all_analyses).count() << "]" << std::endl;
        std::cout << "Inital Sample: " << sample << "     " << " Limit Sample: " << limit_sample <<"\n"<< std::endl;
       
        std::cin.sync();
    }

    std::cout << "\nBye bye! ;D" << std::endl;

    return EXIT_SUCCESS;
}
