#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/control.hpp"
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
            ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
            ERR_FAIL_NULL_MSG(resourceLoader, "Could not fetch resource loader singleton");

            Ref<PackedScene> packedScene = resourceLoader->load(m_MainUIPath);

            ERR_FAIL_COND_MSG(!packedScene.is_valid(), "Could not load packed scene");
            godot::Control* loadedScene = Object::cast_to<godot::Control>(packedScene->instantiate());
            ERR_FAIL_NULL_MSG(loadedScene, "Could not cast loaded scene to control type");

            m_MainUI = loadedScene;

            add_control_to_bottom_panel(m_MainUI, "MultiClient");
        }

        if (inWhat == NOTIFICATION_EXIT_TREE)
        {
            if(m_MainUI == nullptr)
                return;
            
            remove_control_from_bottom_panel(m_MainUI);
            memdelete(m_MainUI);
            
            m_MainUI = nullptr;
        }
    }
}