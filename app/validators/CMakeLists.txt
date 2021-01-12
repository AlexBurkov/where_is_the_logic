add_library(app_validators STATIC
    validator_signup.cpp
)

target_link_libraries(app_validators PUBLIC
	app_records
	data_source
	validators
    json
)
