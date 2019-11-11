#pragma once

#include <memory>
#include <string>

#include "fwd.hpp"

class DataType
{

protected:
  std::weak_ptr<Module> mModule;
  std::string mName;
};
