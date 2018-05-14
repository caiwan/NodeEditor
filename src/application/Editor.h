#pragma once 

namespace NodeEditor
{
	class EditorView;

	class  Editor
	{
	public:
		Editor();

		void SetView(EditorView* const view) { m_view = view; }

	private:
		EditorView * m_view;
	};

}

