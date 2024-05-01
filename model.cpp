#include "model.h"



// forward function for layernorm
void LayerNorm::forward(Tensor* input) {
    
  // initialize cache to store mean and denominator of norm
  this->prev_mean = new float[input->B * input->T];
  this->prev_denom = new float[input->B * input->T];


  float* data = input->data;
  int B = input->B, T = input->T, C = input->C;

  for (int b = 0; b < input->B; b++) {
    for (int t = 0; t < input->T; t++) {
      // find x[b,t,:]
      float* x = input->data + b * T * C + t * C;

      // find mean wrt channel
      float mean = 0.0f;
      for (int i = 0; i < input->C; i++) {
        mean += x[i];
      }
      mean /= input->C;

      // find var wrt channel
      float var = 0.0f;
      for(int i = 0; i < C; i++) {
        float xshift = x[i] - mean;
        var += xshift * xshift;
      }
      var /= input->C;

      // calc rstd
      float denom = 1.0f / sqrtf(var + eps);

      for (int i = 0; i < input->C; i++) {
        float n = (denom * (x[i] - mean));
        float o = n * this->gamma[i] + this->beta[i];
        x[i] = o;
      }
      // cache mean and rstd for backward pass
      prev_mean[b * T * t] = mean;
      prev_denom[b * input->T * t] = denom;
    }
  }
}