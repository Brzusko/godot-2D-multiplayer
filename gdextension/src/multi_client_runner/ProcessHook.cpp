#include "ProcessHook.hpp"
#include "godot_cpp/core/error_macros.hpp"
#include "godot_cpp/classes/os.hpp"

namespace IT
{
	bool ProcessHook::IsProcessRunning()
	{
		ERR_FAIL_COND_V_MSG(m_ProcessID == 0 || m_ProcessID < 0, false, "ProcessHook ID is invalid");
		godot::OS* os_singleton = godot::OS::get_singleton();
		ERR_FAIL_NULL_V_MSG(os_singleton, false,"Please run process runner when Godot instance is running");
		return os_singleton->is_process_running(m_ProcessID);
	}

	void ProcessHook::KillProcess()
	{
		if (!IsProcessRunning())
			return;

		godot::OS* os_singleton = godot::OS::get_singleton();
		ERR_FAIL_NULL_MSG(os_singleton, "Please run process runner when Godot instance is running");

		godot::Error error = os_singleton->kill(m_ProcessID);
		ERR_FAIL_COND_MSG(error != godot::Error::OK, "Could not kill process, error code: ");
	}

	ProcessHook::~ProcessHook()
	{
		KillProcess();
	}
}
