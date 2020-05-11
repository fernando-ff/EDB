#include <iostream>

void merge( int arr[], int l, int m, int r ){

	int i,j,k;

	int n1 =  m - l +1;//n1 armazena o tamanho do primeiro sub array.
	int n2 = r - m;// n2 armazena o tamanho do segundo sub array.

	int L[n1], R[n2];//Cria dois sub array temporarios,
					// L é o primeiro sub array, de tamanho n1,
					// e R é o segundo sub array, de tamanho n2.

	
	//Copia os valores correspondentes para cada sub array do array arr.
	for (i = 0; i < n1; ++i)
		L[i] = arr[l+i];
	for (j = 0; j < n2; ++j)
		R[j] = arr[m+1+j];
	

	i = 0;
	j = 0;
	k = l;
	//Funde os sub arrays dentro de arr de forma crescente.
	while(i < n1 && j < n2){
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//Copia os valores restantes de L e R, caso existentes, para arr.
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort( int arr[], int left, int right ){

	if (left < right)
	{
		int middle { left+(right-left)/ 2 };//Armazena o index do elemento central.
		//Executa novamente a função, mas com o intervalo de valores entre
		//[left, middle] 
		mergeSort( arr, left, middle);
		//Executa novamente a função, mas com o intervalo de valores entre
		//[middle+1, right]
		mergeSort( arr, middle+1, right);
		//Ordena os valores 
		merge( arr, left, middle, right );
	}
}

void print( int arr[], int size ){
    std::cout << "arr = [ " << arr[0];
    for (int i{1}; i < size; i++)
    {
        std::cout << ", " << arr[i];
    }
    std::cout <<" ]" << std::endl;
    
}
int main(void){

    int arr[] { 38, 27, 43, 3, 9, 82, 10 };
    int size { sizeof(arr)/sizeof(arr[0]) };
    mergeSort( arr, 0, size );
    print( arr, size );
    return 0;
}