#pragma once
#include "godot_cpp/classes/editor_plugin.hpp"

namespace IT
{
    
    class MultiClientPlugin : public godot::EditorPlugin
    {
        GDCLASS(MultiClientPlugin, EditorPlugin)
    protected:
        static void _bind_methods();
        void _notification( int inWhat );
    };

} // namespace IT