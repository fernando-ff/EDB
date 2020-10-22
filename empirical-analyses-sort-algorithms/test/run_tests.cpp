#include <iostream>

#include "../lib/test_manager.h"
#include "../include/sorting.h"

int main( void )
{
    TestManager tm {"Insertion Sort Test Suite"};
    
    {
        //===Test #1
        BEGIN_TEST(tm, "First Scneraio", "all elements in a array are in not decresncent order");
        
        unsigned int A[] { 1,1,2,3,3,3,3,3,4,4,4,10,10,15};
        unsigned int A_E[] { 1,1,2,3,3,3,3,3,4,4,4,10,10,15};
    
        std::sort( std::begin(A_E), std::end(A_E));
        sa::insertion(std::begin(A), std::end(A));
        size_t size { sizeof(A)/sizeof(A[0]) };
        bool test { true };
        for (size_t i { 0 }; i < size; i++)
        {
            if( A_E[i] != A[i] )
            {
                test = false;
            }
        }
        EXPECT_EQ( test, true );

    }
    {
        //===Test #2
        BEGIN_TEST(tm, "Second Scneraio", "all elements in a array are in not cresncent order");
        
        unsigned int A[] { 15,15,14,10,10,10,10,6,5,5,4,3,2};
        unsigned int A_E[] { 15,15,14,10,10,10,10,6,5,5,4,3,2};
    
        std::sort( std::begin(A_E), std::end(A_E));
        sa::insertion(std::begin(A), std::end(A));
        size_t size { sizeof(A)/sizeof(A[0]) };
        bool test { true };
        for (size_t i { 0 }; i < size; i++)
        {
            if( A_E[i] != A[i] )
            {
                test = false;
            }
        }
        EXPECT_EQ( test, true );

    }
    {
        //===Test #3
        BEGIN_TEST(tm, "Third Scneraio", "all elements in a array are randomics");
        

        unsigned int A[10] ;
        unsigned int A_E[10] ;

        scenario::third(std::begin(A), std::end(A));       
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort( std::begin(A_E), std::end(A_E));
        sa::insertion(std::begin(A), std::end(A));

        size_t size { sizeof(A)/sizeof(A[0]) };
        bool test { true };

        for (size_t i { 0 }; i < size; i++)
        {
            if( A_E[i] != A[i] )
            {
                test = false;
            }
        }
        EXPECT_EQ( test, true );

    }
    tm.summary();
    std::cout << std::endl;

    TestManager tm4 { "ShellSort"};
    {
        BEGIN_TEST(tm4, "Empty array", "Sort a empty array");
        unsigned int A[10];
        unsigned int A_E[10];
        
        // scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm4, "Equal elements", "all elements in a array are equal");
        unsigned int A[10] { 1,1,1,1,1,1,1,1,1,1};
        unsigned int A_E[10]{ 1,1,1,1,1,1,1,1,1,1};
        
        // scenario::third(std::begin(A), std::end(A));
        // std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm4, "First Scneraio", "all elements in a array are in not decresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::first(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm4, "Second Scneraio", "all elements in a array are in not cresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::second(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm4, "Third Scneraio", "all elements in a array are randomics");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm4, "Fourth Scneraio", " ");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fourth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm4, "Fifth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fifth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm4, "Sixth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::sixth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::shell(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    tm4.summary();
    
    TestManager tm5 { "QuickSort"};
    {
        BEGIN_TEST(tm5, "First Scneraio", "all elements in a array are randomic ");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::first(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::quicksort(std::begin(A), std::end(A));
        // render::array(std::begin(A), std::end(A));
    }
    
    TestManager tm6 { "MergeSort"};
    {
        BEGIN_TEST(tm6, "Empty array", "Sort a empty array");
        unsigned int A[10];
        unsigned int A_E[10];
        
        // scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm6, "Equal elements", "all elements in a array are equal");
        unsigned int A[10] { 1,1,1,1,1,1,1,1,1,1};
        unsigned int A_E[10]{ 1,1,1,1,1,1,1,1,1,1};
        
        // scenario::third(std::begin(A), std::end(A));
        // std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm6, "First Scneraio", "all elements in a array are in not decresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::first(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm6, "Second Scneraio", "all elements in a array are in not cresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::second(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm6, "Third Scneraio", "all elements in a array are randomics");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm6, "Fourth Scneraio", " ");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fourth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
        {
        BEGIN_TEST(tm6, "Fifth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fifth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
        {
        BEGIN_TEST(tm6, "Sixth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::sixth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::mergesort(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    tm6.summary();
    
    TestManager tm7 { "RadixSort"};
    {
        BEGIN_TEST(tm7, "Empty array", "Sort a empty array");
        unsigned int A[10];
        unsigned int A_E[10];
        
        // scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));
        render::array(A, A+10);

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm7, "Equal elements", "all elements in a array are equal");
        unsigned int A[10] { 1,1,1,1,1,1,1,1,1,1};
        unsigned int A_E[10]{ 1,1,1,1,1,1,1,1,1,1};
        
        // scenario::third(std::begin(A), std::end(A));
        // std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm7, "First Scneraio", "all elements in a array are in not decresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::first(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm7, "Second Scneraio", "all elements in a array are in not cresncent order");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::second(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
        
    }
    {
        BEGIN_TEST(tm7, "Third Scneraio", "all elements in a array are randomics");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::third(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm7, "Fourth Scneraio", " ");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fourth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm7, "Fifth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::fifth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    {
        BEGIN_TEST(tm7, "Sixth Scneraio", "");
        unsigned int A[10];
        unsigned int A_E[10];
        
        scenario::sixth(std::begin(A), std::end(A));
        std::copy(std::begin(A), std::end(A), std::begin(A_E));

        std::sort(std::begin(A_E), std::end(A_E));
        sa::radix(std::begin(A), std::end(A));

        bool test { true };
        for (short i{0}; i < 10; i++)
        {
            if(A[i] != A_E[i])
            {
                test = false;
                break;
            }
        }
        EXPECT_EQ(test, true);
    }
    tm7.summary();
    return 0;
}
