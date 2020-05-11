#include<iostream>
#include <array>

void swap(  int* i,   int* j ){
	int k = *i;
	*i = *j;
	*j = k;

}

int partition(  int start,  int end, int arr[] ){
	
	int i { start -1 };
	int pivo{ arr[end] };
	for (int j { start }; j <= end-1; ++j)
	{
		if (arr[j] < pivo)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[end]);
	return(i+1);
}

void quickSort(  int start,  int end, int arr[] ){
	if( start < end){
		int pivo = partition( start, end, arr );

		quickSort( start, pivo-1,arr );
		quickSort( pivo+1, end,arr );
	}
}

void print( int arr[], size_t size ){
	std::cout <<" arr = [ ";
	for (size_t i {0}; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int main(){
	int arr[]{ 5, 1, 2, 4, 3 };
	size_t size { sizeof(arr)/sizeof(arr[0]) };
	quickSort(  0, size-1, arr );
	print( arr, size );

}