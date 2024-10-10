target_sources( ${PROJECT_NAME}
    PRIVATE
        MultiClientPlugin.cpp
 ProcessRunner.cpp ProcessHook.cpp "MultiClientUI.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE .)