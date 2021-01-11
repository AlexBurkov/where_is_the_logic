#include "user_record.h"

#include "util/generic/ctype.h"

TRecordUser::TRecordUser(const NJson::TJsonValue& json) {
    Email = NJson::GetString(json, RECORD_USER_FIELD_EMAIL, "");
    Password = NJson::GetString(json, RECORD_USER_FIELD_PASSWORD, "");
    Name = NJson::GetString(json, RECORD_USER_FIELD_NAME, "");
    RepeatPassword = NJson::GetString(json, RECORD_USER_FIELD_REPEAT_PASSWORD, "");
}

NJson::TJsonValue TRecordUser::ForDB() const {
    NJson::TJsonValue json;
    json[RECORD_USER_FIELD_EMAIL] = Email;
    json[RECORD_USER_FIELD_PASSWORD] = Password;
    json[RECORD_USER_FIELD_NAME] = Name;
    return json;
}

NJson::TJsonValue TRecordUser::ToJson() const {
    auto json = ForDB();
    json[RECORD_USER_FIELD_REPEAT_PASSWORD] = RepeatPassword;
    return json;
}
