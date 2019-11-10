#pragma once

#include <QMainWindow>

#include "EditorView.hpp"

namespace NodeEditor
{
    class Editor;

    class MainWindow : public QMainWindow, public EditorView
    {
    public:
        MainWindow(QWidget* parent = nullptr);

        void SetEditor(Editor* const editor) { mEditor = editor; }

      private:
        Editor* mEditor;
    };
}
