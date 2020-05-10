#include <iostream> //std::cin,std::cout
/*Def :=Dado um arranjo S qualquer.
**Filter forma um subarranjo de S,Q talque Q = {x; x >= 0}.
**De forma mais informal: A função separa o arranjo em subarranjos baseados em um predicado,
**nesse caso o predicado é: se um elemento for menor ou igual a zero deve ser filtrado, ou seja,
**separe os elementos menores ou iguais a zero dos que são maiores.
*/
int* filter(int* first, int* last){
	/*First:= Delimitador,tem sua posição fixada na 1ª do arranjo.
	**Last:= Delimitador, tem sua posição fixada pós ultima posição do arranjo.
	**[first,first+step):= Os que passaram na verificação.
	**[first+step,first+i]:= Os que foram rejeitados na verificação.
	**[first+i,last):= Não processados. 
	*/
	short step{0};//Delimitador.
	short i{0};//Delimitador.
	int var_aux;//Variavél que auxilia na troca dos valores.
	while( first+i != last){// Repita enquanto first+i não é igual a last.

		if (*(first+i) > 0)//Se first+i for maior que zero, execute a seguinte sequência de comandos:
		{
			var_aux = *(first+step);//1.Atribua o valor de first+step a variavel auxiliar,var_aux.
			*(first+step) = *(first+i);//2.Atribua o valor de first+i a first+step.
			*(first+i) = var_aux;//3.Atribua o valor de var_aux a fist+i.
			step++;//4.Incremente step.
		}
		i++;//Incremente i.
	}
	return first;//Retorna o endereço de memoria de first.
}
int main(){
	int array[]{-2,8,-5,2,0,7,9,-1};
	size_t sz{ sizeof(array)/sizeof(array[0]) };//Atribui o tamanho do array a sz.
	int* first = filter( array,array+sz );
	while (*(first) >0 )//Imprime os valores positivos existentes no array após filtragem.
	{
		std::cout << *first <<" ";
		first++;
	}
	std::cout<<"\n";
	return 0;
}
