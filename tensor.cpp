#include "tensor.h"
#include <iostream>
#include <random>


void Tensor::randn() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());


  std::normal_distribution<double> distribution(0, 1);
  // for (int b = 0; b < this->B; ++b) {
  //   for (int t = 0; t < this->T; ++t) {
  //       for (int c = 0; c < this->C; ++c) {
  //         this->data[b * this->T * this->C + t * this->C + c] = distribution(gen);
  //     }
  //   }
  // }

}




void Tensor::print() {
  for (int b = 0; b < this->B; ++b) {
    for (int t = 0; t < this->T; ++t) {
        for (int c = 0; c < this->C; ++c) {
            std::cout << this->data[b * this->T * this->C + t * this->C + c] << " ";
        }
        std::cout << std::endl;  // Newline after each 'c' loop iteration
    }
    std::cout << std::endl;  // Additional newline after each 'b' loop iteration
  }
}