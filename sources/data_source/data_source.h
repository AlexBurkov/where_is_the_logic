#pragma once

#include "library/mongo/wrappers.h"

#include "app/collections/user_collection.h"
#include "sources/collections/base.h"

#include "util/generic/holder.h"

class TDataSource {
public:
    TDataSource(const TString& uri, const TString& db);
    ~TDataSource();

private:
    struct TMongoDriver {
        TMongoDriver() {
            NMongo::Init();
        }
        ~TMongoDriver() {
            NMongo::Cleanup();
        }
    };

    TMongoDriver MongoDriver;
    THolder<NMongo::THelper> Master;

public:
    TCollectionBase CollectionBase;
    TCollectionUser CollectionUser;
};
