
#ifndef MYHEADER_H
#define MYHEADER_H
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

  // initializers
  void randn();


  // helpers
  void print();


};

#endif