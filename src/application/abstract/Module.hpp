#pragma once

#include <vector>
#include <memory>

#include "fwd.hpp"

/* Objectives
 * - Represent node types with inputs and outputs
 * - Represent a node implementation which takes the inputs and produces outputs
 * - Represent the node graph
 * - Span the node graph, and execute it iteratively
 * - In some special cases the node signature (input/output) can change (shader) which needs to be handled (update)
 * - Validation shall be done accordingly - match up the connection types and disconnect if does not match when changed
 */

/* This represents the execution module where
 * - The node descriptions are located in
 * - The execution contexts (instances of nodes and connections) are located in
 * TODO: Validation
 *
 * Intended use
 * -
 * */

class Module {
public:
    Module() = default;

    explicit Module(const std::string &name) : mName(name) {}

    std::string Name() const { return mName; }

    // Types
    void AddType(const std::shared_ptr<NodeType> &type);

    size_t TypeCount() const;

    std::weak_ptr<NodeType> Type(size_t id);

    // Contexts
    void AddContext(const std::shared_ptr<ExecutionContext> &context);

    size_t ContexCount() const;

    std::weak_ptr<ExecutionContext> Context(size_t id);

    void RemoveContext(size_t id); // TODO: How do we delete this properly?

    // TODO Split Module representation and it's interface
    // - This will needed to store the types and name, but also to hold the context which are created
    // - This also needed for the context which nees to refer back to the Module internal representation, but not (neseccarly) alter it

private:
    std::string mName;
    std::vector<std::shared_ptr<NodeType>> mTypes;
    std::vector<std::shared_ptr<ExecutionContext>> mContexts;
};

// A context where the set of nodes are executed in
class ExecutionContext {
public:
    explicit ExecutionContext(const std::shared_ptr<Module> &module) : mModule(module) {}

    ExecutionContext(const std::shared_ptr<Module> &module, const std::string &name) : mName(name), mModule(module) {}

    std::weak_ptr<Module> ParentDescriptor() const { return mModule; }

    std::weak_ptr<Node> CreateNode(size_t id);

    void Execute();

private:
    std::string mName;
    std::weak_ptr<Module> mModule;
    std::vector<std::shared_ptr<Node>> mNodes;
    std::vector<std::shared_ptr<Connection>> mConnection;
};
