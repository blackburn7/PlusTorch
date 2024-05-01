#include "model.h"





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