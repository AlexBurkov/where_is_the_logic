#include "validator_signup.h"
#include "app/records/user_record.h"

TValidatorSignup::TValidatorSignup(const NJson::TJsonValue& jsonData) : IValidator(jsonData) {}

bool TValidatorSignup::Validate(TDataSource& dataSource) {
	int isValid = 1;
	isValid &= ValidateRequired(RECORD_USER_FIELD_EMAIL);
	isValid &= ValidateRequired(RECORD_USER_FIELD_NAME);
	isValid &= ValidateRequired(RECORD_USER_FIELD_PASSWORD);
	isValid &= ValidateSame(RECORD_USER_FIELD_REPEAT_PASSWORD, RECORD_USER_FIELD_PASSWORD);
	isValid &= ValidateEmail(RECORD_USER_FIELD_EMAIL);
	isValid &= ValidateExists(dataSource);
	return isValid;
}

bool TValidatorSignup::ValidateExists(TDataSource& dataSource) {
	if (dataSource.CollectionUser.ExistsWithEmail(NJson::GetString(OriginJson, RECORD_USER_FIELD_EMAIL, ""))) {
        ValidationErrors[RECORD_USER_FIELD_EMAIL].push_back(VALIDATION_ERROR_ALREADY_EXISTS);
        return false;
    }

    return true;
}
