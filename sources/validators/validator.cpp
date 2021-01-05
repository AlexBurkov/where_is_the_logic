#include "validator.h"

#include "util/generic/ctype.h"

IValidator::IValidator(const NJson::TJsonValue& jsonData): OriginJson(jsonData), ValidationErrors(NJson::TJsonValue::object()) {}

NJson::TJsonValue IValidator::GetValidationErrors() const {
    return ValidationErrors;
}

bool IValidator::ValidateRequired(const TString& field) {
    if (NJson::GetString(OriginJson, field, "").empty()) {
        ValidationErrors[field].push_back(VALIDATION_ERROR_REQUIRED);
        return false;
    }

    return true;
}

bool IValidator::ValidateEmail(const TString& field) {
    if (!NString::Contains(NJson::GetString(OriginJson, field, ""), '@')) {
        ValidationErrors[field].push_back(VALIDATION_ERROR_EMAIL);
        return false;
    }

    return true;
}

bool IValidator::ValidateInt(const TString& field) {
    if (!NType::IsInt(NJson::GetString(OriginJson, field, ""))) {
        ValidationErrors[field].push_back(VALIDATION_ERROR_MUST_BE_INT);
        return false;
    }

    return true;
}

bool IValidator::ValidateUnsignedInt(const TString& field) {
    if (!NType::IsUnsignedInt(NJson::GetString(OriginJson, field, ""))) {
        ValidationErrors[field].push_back(VALIDATION_ERROR_MUST_BE_UNSIGNED_INT);
        return false;
    }

    return true;
}

bool IValidator::ValidateLessThan(const TString& field, const int value) {
    const TString& strValue = NJson::GetString(OriginJson, field, "");
    if (!NType::IsInt32(strValue) || !NType::LessThan(strValue, value)) {
        ValidationErrors[field].push_back(VALIDATION_ERROR_MUST_BE_LESS_THAN);
        return false;
    }

    return true;
}

bool IValidator::ValidateSame(const TString& validateField, const TString& sameField) {
    if (NJson::GetString(OriginJson, validateField, "") != NJson::GetString(OriginJson, sameField, "")) {
        ValidationErrors[validateField].push_back(VALIDATION_ERROR_SAME);
        return false;
    }

    return true;
}
