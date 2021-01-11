#pragma once

#include "sources/collections/collection.h"
#include "app/records/user_record.h"

class TCollectionUser : public ICollection<TRecordUser> {
public:
    using ICollection::ICollection;
    bool ExistsWithEmail(const TString& email);
};