#pragma once
#include "godot_cpp/classes/line_edit.hpp"
#include "godot_cpp/classes/reg_ex.hpp"

using namespace godot;
namespace IT
{
    class RegexLineEdit: public LineEdit
    {
        GDCLASS(RegexLineEdit, LineEdit)

    private:
        String m_cachedValue;
        String m_regexPattern;
        int m_caretColumn = 0;
        Ref<RegEx> m_regex;
        void TextChanged(const String& newText);
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    public:
        inline String GetPattern() const { return m_regexPattern; }
        inline void SetPattern(const String& newPattern) { m_regexPattern = newPattern; }
    };
}