#pragma once 

#include <QApplication>

namespace NodeEditor {

	class DataModel;

	class Application : public QObject {
		Q_OBJECT
	public:
		static Application* App() { return s_self; }

		Application(int argc, char **argv);
		~Application();

	    int Execute();

	private:
	    void BuildPrototypes(DataModel** prototypes);

	    QApplication m_qapp;

		// ReSharper disable CppInconsistentNaming
		static Application* s_self;
		// ReSharper restore CppInconsistentNaming
	};

}
