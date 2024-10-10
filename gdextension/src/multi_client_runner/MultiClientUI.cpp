#include "MultiClientUI.hpp"

namespace IT
{
    void MultiClientUI::_bind_methods()
    {
        godot::ClassDB::bind_method(godot::D_METHOD("create_clients", "clientsCount"), &MultiClientUI::CreateClients);
        godot::ClassDB::bind_method(godot::D_METHOD("kill_clients"), &MultiClientUI::KillClients);
    }
    
    void MultiClientUI::_notification(int what)
    {
        if(what == NOTIFICATION_ENTER_TREE)
        {
            m_ProcessRunner = ProcessRunner();
        }

        if(what == NOTIFICATION_EXIT_TREE)
        {
            m_ProcessRunner.KillAllProcesses();
        }
    }

    void MultiClientUI::CreateClients(int clientsCount)
    {
        m_ProcessRunner.CreateProcesses(clientsCount);
    }

    void MultiClientUI::KillClients()
    {
        m_ProcessRunner.KillAllProcesses();
    }
}