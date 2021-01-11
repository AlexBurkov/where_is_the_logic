add_library(app_records STATIC
    user_record.cpp
)

target_link_libraries(app_records PUBLIC
    records
    json
    generic
)