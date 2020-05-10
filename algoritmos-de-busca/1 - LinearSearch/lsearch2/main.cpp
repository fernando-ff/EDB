#include <iostream>
int linearSearch( int A[], size_t left, size_t right, int target){
    while ( left <= right ){
        if( A[left] == target ) return left;
        left++;
    }
    return -1;
    
}
int main() {
    int V[]{ 9, 2, 1, 4, -2, 0, 5, 12 }; // The data array.
    size_t n = sizeof(V)/sizeof(V[0]); // Find out the array length.

    int target{ 12 };// The target we are looking for.

    // ===== Execute the linear search on the entire array.
    int idx = linearSearch( V, 0, n-1 , target );
    // =====

    // Evaluate the result.
    if ( idx == -1 ) std::cout << "Could no find target!\n";
    else std::cout << "Find target at " << idx << "\n";

    return 0;
}
