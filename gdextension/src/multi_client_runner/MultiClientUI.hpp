#pragma once

#include "godot_cpp/classes/h_box_container.hpp"
#include "ProcessRunner.hpp"

namespace IT
{
    class MultiClientUI: public godot::HBoxContainer
    {
        GDCLASS(MultiClientUI, HBoxContainer)
    private:
    protected:
        ProcessRunner m_ProcessRunner;

        static void _bind_methods();
        void _notification(int what);
    public:
        void CreateClients(int clientsCount);
        void KillClients();
    };
}