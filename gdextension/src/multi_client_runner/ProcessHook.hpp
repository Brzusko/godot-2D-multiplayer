#pragma once

namespace IT
{
	struct ProcessHook
	{
	private:
		int m_ProcessID = -1;
	public:
		ProcessHook() {}
		ProcessHook(int processID) : m_ProcessID(processID) {}
		inline int GetProcessID() { return m_ProcessID; }
		bool IsProcessRunning();
		void KillProcess();
		~ProcessHook();
	};
}