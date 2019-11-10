#pragma once
#include <vector>
#include <memory>

#include "fwd.hpp"

// An abstract module we create nodes into
class Module
{
public:
  Module() = default;
  explicit Module(const std::string & name) : mName(name) {}

  std::string Name() const { return mName; }
  void AddType(const std::shared_ptr<NodeType> & type);

  size_t TypeCount() const;
  std::weak_ptr<NodeType> Type(size_t id);

private:
  std::string mName;
  std::vector<std::shared_ptr<NodeType>> mTypes;
  std::vector<std::weak_ptr<NodeType>> mContexts;
};

// A context where the set of nodes are executed in
class Context
{
public:
  explicit Context(const std::shared_ptr<Module> & module) : mModule(module) {}
  Context(const std::shared_ptr<Module> & module, const std::string & name) : mName(name), mModule(module) {}

  std::weak_ptr<Module> ParentDescriptor() const { return mModule; }
  std::weak_ptr<Node> CreateNode(size_t id);
  void Execute();

private:
  std::string mName;
  std::weak_ptr<Module> mModule;
  std::vector<std::shared_ptr<Node>> mNodes;
  std::vector<std::shared_ptr<Connection>> mConnection;
};
