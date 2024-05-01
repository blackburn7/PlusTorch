
#include <tuple>
#include <algorithm>


#ifndef MYHEADER_H
#define MYHEADER_H
class Tensor {
// private:

public:
  float* data;
  float* grad;
  int B;
  int T;
  int C;

  bool requires_grad;

Tensor(int B, int T, int C, float* data = nullptr, bool requires_grad = true): data(data), B(B), T(T), C(C), requires_grad(requires_grad) {
    // allocate new data & grad memory if needed
    this->data = data ? data : new float[B*T*C];
    this->grad = requires_grad ? new float[B*T*C] : nullptr;
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
    delete[] grad;
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