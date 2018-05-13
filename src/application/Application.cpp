#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include "Application.h"
#include "MainWindow.h"

#include "Editor.h"

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

	// do init sequence here
	s_self = this;
}

Application::~Application() {
	s_self = nullptr;
}

int Application::Execute()
{
	Editor editor;
	MainWindow mw(nullptr);

	mw.SetEditor(&editor);
    editor.SetView(&mw);
	mw.show();

    // ... 
	FlowScene scene;
	FlowView view(&scene);

	mw.setCentralWidget(&view);

	return QApplication::exec();
}
