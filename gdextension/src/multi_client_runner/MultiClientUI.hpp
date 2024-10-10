#pragma once

#include "godot_cpp/classes/h_box_container.hpp"
#include "RegexLineEdit.hpp"
#include "godot_cpp/classes/button.hpp"

namespace IT
{
	class MultiClientUI: public godot::HBoxContainer
	{
		GDCLASS(MultiClientUI, HBoxContainer)

	private:
		Button* m_SubmitButton = nullptr;
		RegexLineEdit* m_ClientCountLineEdit = nullptr;
	protected:
		static void _bind_methods();
	public:
		inline Button* GetSubmitButton() { return m_SubmitButton; }
		inline void SetSubmitButton(Button* buttonPtr) { m_SubmitButton = buttonPtr; }
		inline RegexLineEdit* GetClientCountLineEdit() { return m_ClientCountLineEdit; }
		inline void SetClientCountLineEdit(RegexLineEdit* lineEditPtr) { m_ClientCountLineEdit = lineEditPtr; }
	};
}