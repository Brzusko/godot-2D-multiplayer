#include "ProcessRunner.hpp"
#include "godot_cpp/classes/os.hpp"
#include "godot_cpp/core/error_macros.hpp"
#include "godot_cpp/variant/packed_string_array.hpp"
#include <cstdint>

namespace IT
{
	ProcessRunner::~ProcessRunner()
	{
		delete[] m_ProcessHookContainer;
	}

	void ProcessRunner::CreateProcesses(size_t count)
	{
		godot::OS* os_singleton = godot::OS::get_singleton();
		ERR_FAIL_NULL_MSG(os_singleton, "Please run process runner when Godot instance is running");

		if (AnyProccessIsRunning())
		{
			KillAllProcesses();
		}

		m_ProcessHookContainer = new ProcessHook[count];
		m_ArraySize = count;

		for (size_t i = 0; i < count; i++)
		{
			int32_t pid = -1;

			if (os_singleton->has_feature("windows") || os_singleton->has_feature("linux"))
			{
				pid = os_singleton->create_instance(godot::PackedStringArray());
				
			}
			else
			{
				pid = os_singleton->create_process(os_singleton->get_executable_path(), godot::PackedStringArray());
			}
			
			if (pid == -1)
			{
				KillAllProcesses();
				break;
			}

			ProcessHook* processHook = new ProcessHook(pid);
			m_ProcessHookContainer[i] = *processHook;
		}
	}

	void ProcessRunner::KillAllProcesses()
	{
		ERR_FAIL_NULL_EDMSG(m_ProcessHookContainer, "Could not kill empty process runner");
		delete[] m_ProcessHookContainer;
		m_ProcessHookContainer = nullptr;
		m_ArraySize = 0;
	}

	bool ProcessRunner::AnyProccessIsRunning()
	{
		if (m_ProcessHookContainer == nullptr)
			return false;

		for (size_t i = 0; i < m_ArraySize; i++)
		{
			ProcessHook processHook = m_ProcessHookContainer[i];
			if (processHook.IsProcessRunning())
				return true;
		}

		return false;
	}
}
