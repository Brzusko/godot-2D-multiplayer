#pragma once
#include "godot_cpp/classes/line_edit.hpp"
#include "PropertyMacro.hpp"

using namespace godot;
using namespace IT_Utils;

namespace IT_UI
{
    class RegexLineEdit: public LineEdit
    {
        GDCLASS(RegexLineEdit, LineEdit)
        PROPERTY(String, m_regexPattern)

    private:
    protected:
        static void _bind_methods();
    public:
    };
}