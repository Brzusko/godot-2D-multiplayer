#pragma once
#include "godot_cpp/classes/line_edit.hpp"

using namespace godot;

namespace IT_UI
{
    class RegexLineEdit: public LineEdit
    {
        GDCLASS(RegexLineEdit, LineEdit)

    private:
    protected:
        static void _bind_methods();
    public:
    };
}