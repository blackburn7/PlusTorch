#include "tensor.h"
#include "model.h"
#include <iostream>

int main() {

  
  
  std::cout << "hello world" << std::endl;
  Tensor arr1 = Tensor(2, 2, 3);
  Tensor arr2 = Tensor(2, 2, 3);

  for (int b = 0; b < 2; b++) {
    for (int c = 0; c < 2; c++) {
      for (int d = 0; d < 3; d++) {
        arr1.data[b * 2 * 3 + c * 3 + d] = b * 2 * 3 + c * 3 + d;
      }
    }
  }

  for (int b = 0; b < 2; b++) {
    for (int c = 0; c < 2; c++) {
      for (int d = 0; d < 3; d++) {
        arr2.data[b * 2 * 3 + c * 3 + d] = b * 2 * 3 + c * 3 + d;
      }
    }
  }
  LayerNorm lnorm = LayerNorm(3);
  Linear lin = Linear(3, 2);
  // lnorm.forward(&arr);
  lin.forward(&arr1);
  arr1.print();
  arr2.print();


  

}