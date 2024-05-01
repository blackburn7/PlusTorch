
#ifndef LAYER_H
#define LAYER_H

#include <memory>
#include "tensor.h"


class Layer {


  protected:
    std::shared_ptr<Tensor> input;
    std::shared_ptr<Tensor> output;

  public:
    Layer() {}
    virtual ~Layer() {}

    virtual void forward(const std::shared_ptr<Tensor>& input) = 0;
    virtual void backward(const std::shared_ptr<Tensor>& grad_output) = 0;


    virtual void clearGradient() {
      if (output && output->requires_grad) {
          output->grad = 0;
      }
    }

  
};

#endif
