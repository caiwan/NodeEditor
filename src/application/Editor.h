#ifndef _EDITOR_H_
#define _EDITOR_H_

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

#endif // _EDITOR_H_
