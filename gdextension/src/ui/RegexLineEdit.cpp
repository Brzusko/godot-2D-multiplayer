#include "RegexLineEdit.hpp"
#include "godot_cpp/classes/reg_ex_match.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

namespace IT
{
    void RegexLineEdit::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("get_pattern"), &RegexLineEdit::GetPattern);
        ClassDB::bind_method(D_METHOD("set_pattern", "newPattern"), &RegexLineEdit::SetPattern);

        ADD_PROPERTY(PropertyInfo(godot::Variant::STRING, "Regex Pattern"), "set_pattern", "get_pattern");
    }

    void RegexLineEdit::_notification(int what)
    {
        if (what == NOTIFICATION_READY)
        {
            m_regex = RegEx::create_from_string(m_cachedValue);
            ERR_FAIL_COND_MSG(!m_regex.is_valid(), "Could not create instance of RegEx");

            Error error = m_regex->compile(m_regexPattern);
            ERR_FAIL_COND_MSG(error != OK, "Could not compile RegEx");

            connect("text_changed", callable_mp(this, &RegexLineEdit::TextChanged));
        }
    }

    void RegexLineEdit::TextChanged(const String& newText)
    {
        Ref<RegExMatch> match = m_regex->search(newText);

        if (match.is_valid())
        {
            m_cachedValue = newText;
            m_caretColumn = get_caret_column();
            return;
        }

        set_text(m_cachedValue);
        set_caret_column(m_caretColumn);
    }
}