#pragma once 

#include <memory>

#include "fwd.hpp"

// Concrete instance of a node
class Node {
  protected:
  std::weak_ptr<NodeType> mType;
  std::weak_ptr<Context> mContext;

  // Other stuff ??? 
};
