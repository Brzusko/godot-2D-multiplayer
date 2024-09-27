add_subdirectory(multi_client_runner)
add_subdirectory(example)

target_sources( ${PROJECT_NAME}
    PRIVATE
        RegisterExtension.cpp
)
