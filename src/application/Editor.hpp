#pragma once

class QWidget;

namespace NodeEditor
{
  class EditorView;

  class Editor
  {
  public:
    Editor();

    void SetView(EditorView * const view) { mView = view; }

  private:
    EditorView * mView;
  };

} // namespace NodeEditor
