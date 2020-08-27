#include <iostream>
int* linearSearch( int *first, int *last, int target){
    short idx{0};
    while( first != last ){
        if (*first == target){
            *first = idx;
            return first;
        }
        idx++; 
        first++;
    }
    return nullptr;
}
int main() {
    int V[]{ 9, 2, 1, 4, -2, 0, 5, 12 }; // The data array.
    size_t n = sizeof(V)/sizeof(V[0]); // Find out the array length.

    int target{ 12 };// The target we are looking for.

    // ===== Execute the linear search on the entire array.
    int *idx = linearSearch( V, V+n, target );
    // =====

    // Evaluate the result.
    if ( idx == nullptr ) std::cout << "Could no find target!\n";
    else std::cout << "Find target at " << *idx << "\n";

    return 0;
}
