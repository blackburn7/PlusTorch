#include "tensor.h"
#include <iostream>
#include <random>


void Tensor::randn() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());


  std::normal_distribution<double> distribution(0, 1);
  for (int b = 0; b < this->B; ++b) {
    for (int t = 0; t < this->T; ++t) {
        for (int c = 0; c < this->C; ++c) {
          this->data[b * this->T * this->C + t * this->C + c] = distribution(gen);
      }
    }
  }

}




std::ostream& operator<<(std::ostream& os, const Tensor& tensor) {
    for (int b = 0; b < tensor.B; ++b) {
        for (int t = 0; t < tensor.T; ++t) {
            for (int c = 0; c < tensor.C; ++c) {
                os << tensor.data[b * tensor.T * tensor.C + t * tensor.C + c] << " ";
            }
            os << std::endl; // Newline after each 'c' loop iteration
        }
        os << std::endl; // Additional newline after each 'b' loop iteration
    }
    return os;
}