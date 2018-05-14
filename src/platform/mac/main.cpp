
// Todo: add parent to cmake
#include "Application.h"

class MacApplication : public NodeEditor::Application{
public:
    MacApplication( int argc, char **argv ) : Application(argc, argv){
    }
};

int main( int argc, char **argv )
{
    Q_INIT_RESOURCE(resources);
    MacApplication a (argc, argv);
    return a.Execute();
}
