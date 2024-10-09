#pragma once

#include <cstdio>

#include "ProcessHook.hpp"

namespace IT
{
	class ProcessRunner
	{
	private:
		size_t m_ArraySize = 0;
		ProcessHook* m_ProcessHookContainer = nullptr;

		bool AnyProccessIsRunning();
	public:
		ProcessRunner() {};
		~ProcessRunner();
		
		void CreateProcesses(size_t count);
		void KillAllProcesses();
	};
}