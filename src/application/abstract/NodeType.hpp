#pragma once

#include "fwd.hpp"
#include <memory>
#include <string>
#include <vector>

// Abstract node of a module type we instantiate
// This describes all the input / output types
class NodeType
{
public:
  explicit NodeType(const std::shared_ptr<Module> & module) : mModule(module) {}
  NodeType(const std::shared_ptr<Module> module, const std::string & name, const std::string & description = {}) : mModule(module), mName(name), mDescription(description) {}

protected:
  std::weak_ptr<Module> mModule;
  std::string mName, mDescription;
  std::vector<DataType> mInputs;
  std::vector<DataType> mOutputs;
};
