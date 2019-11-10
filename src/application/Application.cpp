#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>
#include <nodes/TypeConverter>
#include <nodes/FlowViewStyle>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>

#include <nodes/DataModelRegistry>

#include "model/NumberSourceDataModel.hpp"
#include "model/NumberDisplayDataModel.hpp"
#include "model/AdditionModel.hpp"
#include "model/SubtractionModel.hpp"
#include "model/MultiplicationModel.hpp"
#include "model/DivisionModel.hpp"
#include "model/ModuloModel.hpp"
#include "model/Converters.hpp"

using QtNodes::ConnectionStyle;
using QtNodes::DataModelRegistry;
using QtNodes::FlowScene;
using QtNodes::FlowView;
using QtNodes::FlowViewStyle;
using QtNodes::NodeStyle;
using QtNodes::TypeConverter;
using QtNodes::TypeConverterId;


static std::shared_ptr<DataModelRegistry> RegisterDataModels()
{
  auto ret = std::make_shared<DataModelRegistry>();
  ret->registerModel<NumberSourceDataModel>("Sources");
  ret->registerModel<NumberDisplayDataModel>("Displays");
  ret->registerModel<AdditionModel>("Operators");
  ret->registerModel<SubtractionModel>("Operators");
  ret->registerModel<MultiplicationModel>("Operators");
  ret->registerModel<DivisionModel>("Operators");
  ret->registerModel<ModuloModel>("Operators");
  ret->registerTypeConverter(std::make_pair(DecimalData().type(), IntegerData().type()), TypeConverter{ DecimalToIntegerConverter() });
  ret->registerTypeConverter(std::make_pair(IntegerData().type(), DecimalData().type()), TypeConverter{ IntegerToDecimalConverter() });
  return ret;
}

#include "Application.hpp"
#include "MainWindow.hpp"

#include "Editor.hpp"

using namespace NodeEditor;
using namespace QtNodes;


Application::Application(int argc, char ** argv) : mQapp(argc, argv)
{
  QApplication::setOrganizationDomain("hu.caiwan.nodeeditor");
  QApplication::setOrganizationName("Caiwan");
  QApplication::setApplicationName("NodeEditor");
}

Application::~Application() {}

int Application::Execute()
{
  Editor editor;
  MainWindow mw(nullptr);

  auto menuBar = mw.menuBar();
  auto saveAction = menuBar->addAction("Save..");
  auto loadAction = menuBar->addAction("Load..");

  FlowScene scene;
  scene.setRegistry(RegisterDataModels());
  FlowView view(&scene);

  mw.SetEditor(&editor);
  editor.SetView(&mw);

  connect(saveAction, &QAction::triggered, &scene, &FlowScene::save);
  connect(loadAction, &QAction::triggered, &scene, &FlowScene::load);

  mw.setCentralWidget(&view);

  mw.show();
  mw.setFixedSize(800, 600);

  return QApplication::exec();
}
