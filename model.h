#include "tensor.h"
#include <iostream>
#include <math.h>






class LayerNorm {
private:
  float* gamma;
  float* beta;
  float* prev_mean;
  float* prev_denom;
  float eps;



public:

  LayerNorm (int dim, float eps = 1e-5f) {
    // parameter arrays of size C
    this->gamma = new float[dim];
    this->beta = new float[dim];
    this->eps = eps;
    std::fill(gamma, gamma + dim, 1);
  }

  void forward(Tensor* input);
};