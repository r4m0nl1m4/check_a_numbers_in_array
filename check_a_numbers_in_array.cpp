//Main for "check_a_numbers_in_array" C++ application
//Created by r4m0nl1m4 14/03/2020

#include <iostream>
#include <cstdlib>
#include <new>          // std::nothrow std::nullptr
#include <chrono> 

using namespace std::chrono;

//Ordenação

int* order_array(int* numbers, size_t n)
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            if (numbers[j] < numbers[i])
            {
                int tmp    = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = tmp;
            }

        }
    }
    return numbers;
}

//Busca

int find_t(int* numbers, size_t n, int t )
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        if ( numbers[i] == t )
        {    
            return 1;
        }
    }
    return 0;
}

int find_t_from_sum(int* numbers, size_t n, int t )
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            if ( numbers[i]+numbers[j] == t )
            {
                return 1;
            }
        }
    }
    return 0;
}

int find_t_better(int* numbers, int n, int t )
{
    int* array = order_array(numbers, n);

    unsigned int l = 0;
    unsigned int r = n - 1;
    int cursor = n / 2;

    if( array[l] < t ) return 0;

    while( l != r )
    {
        if( array[cursor] > t )
        {
            r = cursor;
        }
        else if( array[cursor] < t )
        {
            l = cursor;
        }
        else
        {
            return 1;
        }

        cursor = (r - l) / 2 ;
    }

    return 0;
}

int find_t_from_sum_better(int* ordered_numbers, int n, int t )
{
    unsigned int l = 0;
    unsigned int r = n - 1;
    
    if( ordered_numbers[l] >= t ) return 0;

    while( l != r )
    {   
        if( ordered_numbers[l] < t )
        {
            if ( ordered_numbers[l]+ordered_numbers[r] == t ) return 1;
            if ( ordered_numbers[l]+ordered_numbers[r] > t ) r--;
            else l++;
        } 
    }

    return 0;
}

//Aquisição aleatória

int* get_random_array(size_t n)
{
	int* numbers = new(std::nothrow) int[n];

	if (numbers == nullptr)
	{
    	std::cout << "Error: memory could not be allocated"
                  << "\n";
	}
  	else
  	{
	    for (size_t i = 0; i < n; ++i)
	    {
	        numbers[i] = rand() % 500;
	    }

	}

	return numbers;
}

int main(int argc, char* argv[])
{
    //Recebe o N pelo argv (atoi)
    unsigned int n = atoi (argv[1]);

    //Recebe a soma t pelo argv (atoi)
    int t = atoi (argv[2]);

    //Usa a free store (new)
    int* numeros = get_random_array(n);

    //Recebe o tempo de partida 
    auto start = high_resolution_clock::now(); 

    std::cout << "Busca por soma (comum):    "
              << find_t_from_sum(numeros, n, t)
              << " ";

    //Recebe o tempo de parada 
    auto stop = high_resolution_clock::now(); 

    //Recebe o tempo de duração da excução
    auto duration = duration_cast<microseconds>(stop - start); 
  
    std::cout << "Tempo de execução [ms]: "
              << duration.count()
              << "\n"; 

    //Ordena os números
    numeros = order_array(numeros, n);

    //Recebe o tempo de partida
    start = high_resolution_clock::now(); 

    std::cout << "Busca por soma (ordenada): "
              << find_t_from_sum_better(numeros, n, t)
              << " ";

    //Recebe o tempo de parada 
    stop = high_resolution_clock::now(); 

    //Recebe o tempo de duração da excução
    duration = duration_cast<microseconds>(stop - start); 
  
    std::cout << "Tempo de execução [ms]: "
              << duration.count()
              << "\n"; 

    //Usa a free store (delete)        
    delete[] numeros;

    return 0;
}
