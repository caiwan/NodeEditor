#include "application.hpp"

class WindowsApplication : public NodeEditor::Application {
public:
	WindowsApplication(int argc, char **argv) : NodeEditor::Application(argc, argv) {
	}
};

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(resources);
	WindowsApplication a(argc, argv);
	return a.Execute();
}
