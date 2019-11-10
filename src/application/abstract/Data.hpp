#pragma onde

#include <memory>
#include <string>

#include "Fwd.hpp"

class DataType
{

protected:
  std::weak_ptr<Module> mModule;
  std::string mName;
};
