
#include <iostream>
#include <math.h>

class Tensor {
// private:

public:
  float* data;
  int B;
  int T;
  int C;

  Tensor(int B, int T, int C): B(B), T(T), C(C) {
    data = new float[B*T*C];
  }

  void print();


};










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
  }

  void forward(Tensor* input);
};