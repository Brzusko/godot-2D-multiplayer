#include "godot_cpp/variant/utility_functions.hpp"
#include "multi_client_plugin.hpp"


namespace IT {
    void MultiClientPlugin::_bind_methods() {
    }
    void MultiClientPlugin::_notification(int inWhat) {
        godot::UtilityFunctions::print( "Wet" );
    }
}