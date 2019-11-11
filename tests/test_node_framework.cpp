#include <gtest/gtest.h>

#include "abstract/Module.hpp"
#include "abstract/NodeType.hpp"
#include "abstract/Data.hpp"

class NodeTest : public testing::Test {
public:
    std::shared_ptr<Module> myModule;

    // TODO: Add a simple addition ex.
    void CreateModule() {
      myModule = std::make_shared<Module>("myTestModule");

      auto myFristType = std::make_shared<NodeType>(myModule, "my1stType");
      auto mySecondType = std::make_shared<NodeType>(myModule, "my2ndType");
      myModule->AddType(myFristType);
      myModule->AddType(mySecondType);
    }
};

TEST_F(NodeTest, ModuleTest) {
  // Create module than create an empty context on it

  // Given
  CreateModule();

  // When
  auto myContext = std::make_shared<Context>(myModule, "my execution queue");
  auto myFirstNode = myContext->CreateNode(0);
  auto mySecondNode = myContext->CreateNode(1);

  // Then
  myContext->Execute();
}
