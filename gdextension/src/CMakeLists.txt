add_subdirectory(utils)
add_subdirectory(multi_client_runner)
add_subdirectory(example)
add_subdirectory(ui)

target_sources( ${PROJECT_NAME}
    PRIVATE
        RegisterExtension.cpp
)
