#include <iostream>

int linearSearch(int *A, size_t n, int target){
    size_t idx{0};
    while( idx != n  ) {
        if (A[idx] == target) return idx;
        idx++;   
    }
    return -1; 
}

int main(){
    int V[]{ 9, 2, 1, 4, -2, 0, 5, 12 }; // The data array.
    size_t n = sizeof(V)/sizeof(V[0]); // Find out the array length.

    int target{ -2 };// The target we are looking for.

    // ===== Execute the linear search on the entire array.
    int idx = linearSearch( V, n, target );
    // =====

    // Evaluate the result.
    if ( idx == -1 ) std::cout << "Could no find target!\n";
    else std::cout << "Find target at " << idx << "\n";

    return 0;

}