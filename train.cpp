#include "tensor.h"
#include "model.h"
#include <iostream>

int main() {

  
  
  std::cout << "hello world" << std::endl;
  Tensor arr = Tensor(2, 2, 3);
  arr.randn();

  LayerNorm lnorm = LayerNorm(3);
  lnorm.forward(&arr);
  arr.print();



}