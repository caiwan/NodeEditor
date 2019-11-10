#include "Module.hpp"
#include "NodeType.hpp"
#include "Data.hpp"

void Module::AddType(const std::shared_ptr<NodeType> & type) { mTypes.push_back(type); }

size_t Module::TypeCount() const { return mTypes.size(); }

std::weak_ptr<NodeType> Module::Type(const size_t id) { return mTypes.at(id); }

std::weak_ptr<Node> Context::CreateNode(size_t id)
{
  // ...
  return {};
}

void Context::Execute() {}
