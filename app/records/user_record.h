#pragma once

#include "sources/records/record.h"
#include "util/generic/string.h"
#include "contrib/json/json.h"

namespace {
	const TString RECORD_USER_FIELD_NAME = "Name";
	const TString RECORD_USER_FIELD_EMAIL = "Email";
	const TString RECORD_USER_FIELD_PASSWORD = "Password";
	const TString RECORD_USER_FIELD_REPEAT_PASSWORD = "RepeatPassword";
};

class TRecordUser : public IRecord {
public:
	TRecordUser(const NJson::TJsonValue& json);
	NJson::TJsonValue ForDB() const override;
	NJson::TJsonValue ToJson() const override;
private:
	TString Email, Password, RepeatPassword, Name;
};
