#include "tensor.h"
#include <iostream>
#include <math.h>
#include <random>



class Linear {
private:
  float *weights;
  float *bias;
  int fan_in;
  int fan_out;




public:

  Linear(int fan_in, int fan_out): fan_in(fan_in), fan_out(fan_out) {

    // initialize weights to normal dist.
    weights = new float[fan_in * fan_out];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(0, 1);
    for (int t = 0; t < fan_in; ++t) {
        for (int c = 0; c < fan_out; ++c) {
          weights[t * fan_out + c] = distribution(gen);
      }
    }
    
  }

  void forward(Tensor* input);
  void backward();

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
    std::fill(gamma, gamma + dim, 1);
  }

  void forward(Tensor* input);
};


