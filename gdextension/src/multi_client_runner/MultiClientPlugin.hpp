#pragma once
#include "godot_cpp/classes/editor_plugin.hpp"

using namespace godot;

namespace IT
{
    class Control;
    
    class MultiClientPlugin : public EditorPlugin
    {
        GDCLASS(MultiClientPlugin, EditorPlugin)
    private:
        static MultiClientPlugin* m_instance;
        StringName m_MainUIPath = "res://addons/mutli_client/scenes/multi_client_ui.tscn";
        godot::Control* m_MainUI;

    protected:
        static void _bind_methods();
        void _notification( int inWhat );

    public:
        MultiClientPlugin();
        inline static MultiClientPlugin* get_singleton() { return m_instance; }
    };

} // namespace IT