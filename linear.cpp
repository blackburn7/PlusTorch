#include "model.h"




Linear::Linear(int fan_in, int fan_out): fan_in(fan_in), fan_out(fan_out) {

    // initialize weights to normal dist.
    weights = new float[fan_in * fan_out];
    bias = new float[fan_out];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(0, 1);
    for (int t = 0; t < fan_in; ++t) {
        for (int c = 0; c < fan_out; ++c) {
          weights[t * fan_out + c] = distribution(gen);
      }
    }

    // initialize weight and bias derivatives
    dweights = new float[fan_in * fan_out];
    dbias = new float[fan_out];
    
}



void Linear::forward(Tensor *input) {
  float* data = input->data;
  float* out = new float[fan_in * fan_out];
  for (int b = 0; b < input->B; b++) {
    for (int t = 0; t < input->T; t++) {
      float* out_ptr = out + b * input->T * fan_out + t * fan_out;
      float* inp_ptr = data + b * input->T * fan_in + t * fan_in;
      for(int o = 0; o < fan_out; o++) {
        float val = (bias != NULL) ? bias[o] : 0.0f;
        float* weight_row = weights + o * fan_out;
        for (int i = 0; i < fan_in; i++) {
          val += inp_ptr[i] * weight_row[i];
        }
        out_ptr[o] = val;
      }
    }
  }
  input->data = out;
  input->C = fan_out;
}


void Linear::backward(Tensor *input, Tensor *out) {

  d_input * float = new int[] // (B, T, C)

  // find d_input (d_out @ weights.T)
  for (int b = 0; b < input->B; b++) {
    for (int t = 0 ; t < input->T; t++) {
      float *dout_ptr = dout + b * input->T * fan_out + t * fan_out;
      float *dinp_ptr = dinp + b * input->T * fan_in + t * fan_in;
      for (int o = 0; o < fan_out; o++) {
        float* weight_row = weights + o * fan_out;
        float der = dout_ptr[o];
        for (int i = 0; i < fan_in; i++) {
          dinp_ptr[i] += weight_row[i] * der;
        }
      }
    }
  }

  // find d_weight (input.T @ d_out)
  for (int o = 0; o < fan_out; o++) {
    for (int b = 0; b < input->B; b++) {
      for (int t = 0; t < input->T; t++) {
        float* dout_ptr = dout + b * input->T * fan_out + t * fan_out;
        float* inp_ptr = input + b * input->T * fan_in + t * fan_in
        float* dweight_row = dweights + o*fan_in; 
      }
    }
  }


}