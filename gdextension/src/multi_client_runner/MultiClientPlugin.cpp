#include "godot_cpp/variant/utility_functions.hpp"
#include "MultiClientPlugin.hpp"
#include "ProcessRunner.hpp"

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
        if (inWhat == NOTIFICATION_ENTER_TREE)
        {

        }

        if (inWhat == NOTIFICATION_EXIT_TREE)
        {
            //delete m_runner;
        }
    }
}