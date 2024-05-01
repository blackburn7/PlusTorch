
#include "model.h"
#include <iostream>

int main() {

  
  
  std::cout << "hello world" << std::endl;
  Tensor arr = Tensor(2, 2, 3);
  arr.print();
  for (int b = 0; b < 2; b++) {
    for (int c = 0; c < 2; c++) {
      for (int d = 0; d < 3; d++) {
        arr.data[b * 2 * 3 + c * 3 + d] = b * 2 * 3 + c * 3 + d;
      }
    }
  }

  LayerNorm lnorm = LayerNorm(3);
  lnorm.forward(&arr);
  arr.print();

  

}