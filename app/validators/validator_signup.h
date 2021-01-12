#pragma once

#include "contrib/json/json.h"
#include "sources/validators/validator.h"
#include "sources/data_source/data_source.h"

class TValidatorSignup : public IValidator {
public:
	TValidatorSignup() = default;
	TValidatorSignup(const NJson::TJsonValue& jsonData);
	bool Validate(TDataSource& dataSource);
	bool ValidateExists(TDataSource& dataSource);
};
