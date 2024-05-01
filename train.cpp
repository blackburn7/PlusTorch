#include "tensor.h"
#include "model.h"
#include <iostream>

int main() {

  
  
  std::cout << "hello world" << std::endl;
  Tensor arr1 = Tensor(2, 2, 3);
  Tensor arr2 = Tensor(2, 2, 3);

  arr1.arange();
  std::cout << arr1;

  


  

}