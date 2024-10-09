#include "godot_cpp/variant/utility_functions.hpp"
#include "MultiClientPlugin.hpp"


namespace IT 
{
    MultiClientPlugin* MultiClientPlugin::m_instance = nullptr;

    MultiClientPlugin::MultiClientPlugin()
    {
        m_instance = this;
    }

    void MultiClientPlugin::_bind_methods()
    {
    }

    void MultiClientPlugin::_notification(int inWhat) 
    {
    }
}