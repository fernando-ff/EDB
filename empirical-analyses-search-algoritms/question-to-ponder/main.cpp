#include <iostream>
bool condition(int* value){
    return *value % 7 == 0;
}
int* bsearch(int* first, int*last, int*, bool(*fcnPtr)(int*) ){
    while(first != last){
        size_t size = last - first;
        int middle = (size-1)/2;
        if( fcnPtr(first+middle) ) return (first+middle);
        // else if(*(first+middle) < ) {
        //     first = (first+middle+1);
        // }
        // else {
        //     last = (first+middle);
        // }
        return bsearch((first+middle+1), last, &fcnPtr);
        return bsearch(first, (first+middle), &fcnPtr);


    }
    return last;
}
int main(int argc, char const *argv[])
{
    // int(*fcnPtr)(int) { }
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    
    int* result = bsearch(std::begin(A), std::end(A), &condition);
    return 0;
}
