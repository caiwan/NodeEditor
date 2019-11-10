#pragma once

#include <QApplication>

namespace NodeEditor
{

  class DataModel;

  class Application : public QObject
  {
    Q_OBJECT
  public:
    Application(int argc, char ** argv);
    ~Application();

    int Execute();

  private:
    QApplication mQapp;
  };

} // namespace NodeEditor
