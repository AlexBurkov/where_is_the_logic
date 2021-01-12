#include "app/records/user_record.h"
#include "app/validators/validator_signup.h"
#include "app/handlers/common.h"

#include "contrib/httplib/httplib.h"
#include "sources/data_source/data_source.h"
#include "contrib/json/json.h"

void UserSignupHandler(TDataSource& dataSource, const httplib::Request& req, httplib::Response& res) {
	const NJson::TJsonValue& jsonRecord = NJson::TJsonValue::parse(req.body);
	NJson::TJsonValue response;
	TValidatorSignup validatorUser(jsonRecord);
	if (validatorUser.Validate(dataSource)) {
		TRecordUser recordUser(jsonRecord);
		if (!dataSource.CollectionUser.Create(recordUser)) {
	        response[RESPONSE_STATUS] = RESPONSE_STATUS_INSERT_ERROR;
	    } else {
	        response[RESPONSE_STATUS] = RESPONSE_STATUS_OK;
	        response[RESPONSE_BODY] = jsonRecord.dump();
	    }
	} else {
		response[RESPONSE_STATUS] = RESPONSE_STATUS_VALIDATION_ERROR;
		response[RESPONSE_VALIDATION_ERRORS] = validatorUser.GetValidationErrors();
	}
	res.set_content(response.dump(), "application/json");
}
