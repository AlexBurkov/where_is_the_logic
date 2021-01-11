#include "user_collection.h"
#include "contrib/json/json.h"

bool TCollectionUser::ExistsWithEmail(const TString& email) {
	return Exists({{RECORD_USER_FIELD_EMAIL, email}});
}