#pragma once
#include "godot_cpp/classes/editor_plugin.hpp"

using namespace godot;

namespace IT
{
    
    class MultiClientPlugin : public EditorPlugin
    {
    private:
        GDCLASS(MultiClientPlugin, EditorPlugin)

        static MultiClientPlugin* m_instance;

    protected:
        static void _bind_methods();
        void _notification( int inWhat );
    public:
        MultiClientPlugin();
        inline static MultiClientPlugin* get_singleton() { return m_instance; }
    };

} // namespace IT