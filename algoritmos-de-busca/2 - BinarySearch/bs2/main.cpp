#include <iostream>

int* binarySearch(int* first, int* last, int target, size_t sz)
{ 
	sz = (sz-1)/2;
	std::cout<<"--- Start the binary Search ---"<<std::endl;
	int* mid;
	int i{1};
	while(first <= last)
	{
		mid = first + sz;
		std::cout<<"The loop #"<<i<<std::endl;
		std::cout<<"The value mid is:"<<*(mid)<<std::endl;
		if (*(mid) == target)
		{
			return mid;
		}
		else if (*(mid) < target)
		{
			first = mid+ 1;
		}
		else
		{
			last = mid -1;
		}
		sz = sz/2;
		i++;
		if ( i == 10)
		{
			break;
		}
	}
	return 0;
}
int main()
{
	int array[10]{ 8,12 ,17 ,20 ,23 ,27 ,31 ,34 ,41 ,48 };//stores the data
	int* first;//
	int* last;
	int target{ 48 };//the value to be found
	int* result;
	size_t sz{sizeof(array)/sizeof(array[0])};
	first = array;
	last = array + sz;
	result = binarySearch(first,last,target,sz);
	if (result != 0)
	{
		std::cout<<*(result)<<std::endl;
	}
	else
	{
		std::cout<<"Valuer not find"<<std::endl;
	}
	return 0;
}