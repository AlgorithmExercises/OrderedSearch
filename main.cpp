#include "Test.h"
#include <iostream>
using namespace std;


bool search(vector<int> ordered_numbers, int x, int begin, int end){
  int current = begin + (end -begin)/2;
  printf("Current %d y comparo con %d \n",current,ordered_numbers[current]);
  if(current>=0 && ordered_numbers[current]==x){
    printf("Retorno true\n");
    return true;
  }

  if(begin == end || begin > end)
    return false;

  printf("Fallo\n");
  if(current >=0 && ordered_numbers[current]>x){
    printf("Se fue con begin %d y final %d\n",begin, current-1 );
    return search(ordered_numbers,x,begin,current-1);
  }
  printf("Fallo2\n");
  if(current< ordered_numbers.size() && ordered_numbers[current]<x){
    printf("Se fue con current %d y final %d\n",current, end );
    return search(ordered_numbers,x,current+1,end);
  }
  printf("Retorno false\n");
  return false;
}


bool numberExists(vector<int> ordered_numbers, int x)
{
    printf("Buscando %d, size %u\n",x,ordered_numbers.size() );
    for(int i =0; i< ordered_numbers.size(); i++){
      printf("%d - ",ordered_numbers[i] );
    }
    printf("\n");

    return search(ordered_numbers,x,0,ordered_numbers.size()-1);
}

int main ()
{
    test();
    return 0;
}
