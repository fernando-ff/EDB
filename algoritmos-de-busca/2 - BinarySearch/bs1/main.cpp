#include <iostream>

int binarySearch( int left,int right,int target,int size ){	
	
	while(left != right){
		size = size/2;
		if (target == left+size)	return left+size;
		else if (target < left+size)	right = right+size-1;
		else	left = left+size+1;	
	}
	return 0;
}
int main(void)
{
	int array[]{ 8,12,17,20,23,27,31,34,41,48 };
	int target{ 48 };
	int size{ sizeof(array)/sizeof(array[0]) };
	int result = binarySearch( array[0],array[size],target,size );
	if (result != 0)
	{
		std::cout<<result<<std::endl;
	}
	else
	{
		std::cout<<"Valuer not find"<<std::endl;
	}

	return 0;
}