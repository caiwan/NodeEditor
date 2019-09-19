#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include "Application.h"
#include "MainWindow.h"

#include "Editor.h"
#include "model/DataModel.h"
#include "model/DataPort.h"

using namespace NodeEditor;
using namespace QtNodes;


Application* Application::s_self;

Application::Application(int argc, char **argv) :
	m_qapp(argc, argv)
{
	if (s_self) {
		// app is already inited, halt
		exit(1);
	}

	QApplication::setOrganizationDomain("hu.caiwan.nodeeditor");
	QApplication::setOrganizationName("Caiwan");
	QApplication::setApplicationName("NodeEditor");

	s_self = this;
}

Application::~Application() {
	s_self = nullptr;
}

void Application::BuildPrototypes(DataModel** prototypes)
{
	NodeDataType ports[3];
    ports[0] = NodeDataType{ "int", "int" };
    ports[1] = NodeDataType{ "string", "string" };
    ports[2] = NodeDataType{ "float", "float" };

    prototypes[0] = new DataModel();
    prototypes[0]->SetCaption("Cica");
    prototypes[0]->SetName("CicaComponent");
    prototypes[0]->SetIsCaptionVisible(true);

    prototypes[0]->AddInputType(ports[0]);
    prototypes[0]->AddInputType(ports[1]);
    prototypes[0]->AddInputType(ports[2]);

    prototypes[0]->AddOutputType(ports[0]);
    prototypes[0]->AddOutputType(ports[1]);
    prototypes[0]->AddOutputType(ports[2]);

    prototypes[1] = new DataModel();
    prototypes[1]->SetCaption("Kutya");
    prototypes[1]->SetName("KutyaComponent");
    prototypes[1]->SetIsCaptionVisible(true);

    prototypes[1]->AddInputType(ports[0]);
    prototypes[1]->AddInputType(ports[1]);
    prototypes[1]->AddInputType(ports[2]);
}

int Application::Execute()
{
	Editor editor;
	MainWindow mw(nullptr);

	// ... 

    DataModel* prototypes[2];
    BuildPrototypes(prototypes);


    auto registry = std::make_shared<DataModelRegistry>();
	for (auto & prototype : prototypes)
	{
		registry->registerModel<DataModel>([&prototype]() {return std::unique_ptr<DataModel>(prototype->Copy()); });
	}

	FlowScene scene;

	scene.setRegistry((registry));

	FlowView view(&scene);

	mw.SetEditor(&editor);
	editor.SetView(&mw);

	mw.setCentralWidget(&view);

	mw.show();
	mw.setFixedSize(800, 600);

	return QApplication::exec();
}
