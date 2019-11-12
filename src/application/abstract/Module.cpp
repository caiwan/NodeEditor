#include "Module.hpp"
#include "NodeType.hpp"
#include "Data.hpp"

void Module::AddType(const std::shared_ptr<NodeType> &type) { mTypes.push_back(type); }

size_t Module::TypeCount() const { return mTypes.size(); }

std::weak_ptr<NodeType> Module::Type(const size_t id) { return mTypes.at(id); }

void Module::AddContext(const std::shared_ptr<ExecutionContext> &context) { mContexts.push_back(context); }

size_t Module::ContexCount() const { return mContexts.size(); }

std::weak_ptr<ExecutionContext> Module::Context(size_t id) { return mContexts.at(id); }

void Module::RemoveContext(size_t id) {} // What should happen?

void ExecutionContext::Execute() {}
