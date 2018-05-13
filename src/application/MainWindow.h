#pragma once

#include <QMainWindow>

#include "EditorView.h"

namespace NodeEditor
{
    class Editor;

    class MainWindow : public QMainWindow, public EditorView
    {
    public:
        MainWindow(QWidget* parent = nullptr);

        void SetEditor(Editor* const editor) { m_editor = editor; }

    private:
        Editor* m_editor;
    };
}
