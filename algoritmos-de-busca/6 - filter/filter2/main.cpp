#include<iostream>
#include "filter2Config.h"

void filter(int left, int right){
    auto slow { left };
    auto fast { left };
    int var_aux{0};
    while(fast != right){
        if (fast > 0)
        {
            var_aux = slow;
            slow = fast;
            fast = var_aux;
            slow++;
        }
        fast++;      
    }
}

void version()
{
  std::cout << "Version : " << FILTER2_VERSION_MAJOR <<
    "." << FILTER2_VERSION_MINOR <<
    "." << FILTER2_VERSION_PATCH << std::endl;
} 

int main()
{
    version();
	int A[]{ -2,8,-5,2,0,7,9,-1 };
    size_t sz{ sizeof(A)/sizeof(A[0]) };
    filter( A[0], A[sz-1] );
    return 0;
}
