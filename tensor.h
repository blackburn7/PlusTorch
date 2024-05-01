
#include <tuple>

#ifndef MYHEADER_H
#define MYHEADER_H
class Tensor {
// private:

public:
  float* data;
  int B;
  int T;
  int C;

  Tensor(int B, int T, int C, float* data = nullptr): B(B), T(T), C(C) {
    if (!data) data = new float[B*T*C];
  }

  // Copy constructor
  Tensor(const Tensor& other) : B(other.B), T(other.T), C(other.C) {
      int size = B * T * C;
      data = new float[size];
      std::copy(other.data, other.data + size, data);
  }

  // Destructor
  ~Tensor() {
      delete[] data;
  }

  // initializers
  void randn();
  void arange();


  // helpers
  friend std::ostream& operator<<(std::ostream& os, const Tensor& tensor);

  std::tuple<int, int, int> shape() const {
      return std::make_tuple(B, T, C);
  }


};

#endif