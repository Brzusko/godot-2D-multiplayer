#include "MultiClientUI.hpp"


namespace IT
{
	void MultiClientUI::_bind_methods()
	{
		godot::ClassDB::bind_method(D_METHOD("get_submit_button"), &MultiClientUI::GetSubmitButton);
		godot::ClassDB::bind_method(D_METHOD("set_submit_button, SubmitButton"), &MultiClientUI::SetSubmitButton);
		ADD_PROPERTY(PropertyInfo(
			godot::Variant::OBJECT, "SubmitButton", godot::PROPERTY_HINT_NODE_TYPE, "Button"),
			"set_submit_button", "get_submit_button");

		godot::ClassDB::bind_method(D_METHOD("get_client_count_line_edit"), &MultiClientUI::GetClientCountLineEdit);
		godot::ClassDB::bind_method(D_METHOD("set_client_count_line_edit", "line edit"), &MultiClientUI::SetClientCountLineEdit);
		ADD_PROPERTY(
			PropertyInfo(godot::Variant::OBJECT, "Client Count Line Edit", godot::PROPERTY_HINT_NODE_TYPE, "RegexLineEdit"),
			"set_client_count_line_edit", "get_client_count_line_edit");
	}
}