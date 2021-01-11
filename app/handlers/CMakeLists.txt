add_library(app_handlers STATIC
    user_handler.cpp
)

target_link_libraries(app_handlers PUBLIC
    httplib
    data_source
    app_validators
    json
)