#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <QApplication>

namespace NodeEditor {

	class Application : public QObject {
		Q_OBJECT
	public:
		static Application* App() { return s_self; }

		Application(int argc, char **argv);
		~Application();

		int Execute();

	private:
		QApplication m_qapp;

		// ReSharper disable CppInconsistentNaming
		static Application* s_self;
		// ReSharper restore CppInconsistentNaming
	};

}

#endif // _APPLICATION_H_
