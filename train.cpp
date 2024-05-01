#include "tensor.h"
#include "layers/model.h"
#include <iostream>

int main() {

  
  
  std::cout << "hello world" << std::endl;
  Tensor arr1 = Tensor(2, 2, 3);
  Tensor arr2 = Tensor(2, 2, 3);

  arr1.arange();
  std::cout << arr1;
  Linear lin1(3, 2);
  Tensor* out = lin1.forward(&arr1);
  std::cout << *out;


  

}