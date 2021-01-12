add_library(app_collections STATIC
    user_collection.cpp
)

target_link_libraries(app_collections PUBLIC
   collections
   app_records
   json
)
