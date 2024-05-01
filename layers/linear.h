#include "../tensor.h"


class Linear {
private:
  float *weights;
  float *bias;
  int fan_in;
  int fan_out;

  float *dweights;
  float *dbias;


public:


  Linear(int fan_in, int fan_out);
  ~Linear() {
    free(weights);
    free(bias);
    free(dweights);
    free(dbias);
  }

  
  Tensor* forward(Tensor* input);
  void backward(Tensor* input, Tensor* output);

};