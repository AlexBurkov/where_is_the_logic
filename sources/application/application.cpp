#include "application.h"

#include "contrib/json/json.h"

#include "sources/handlers/hi.h"
#include "sources/handlers/numbers.h"

#include "app/handlers/user_handler.h"

#include "util/generic/ctype.h"

TApplication::TApplication(NJson::TJsonValue& config)
    : Config(config)
{
    INFO_LOG << "Starting server..." << Endl;
    DataSource.reset(new TDataSource(Config["Server"]["MongoUri"], Config["Server"]["MongoDbName"]));
    Server.reset(new httplib::Server());

    Server->Get("/api/admin/hi", [&](const httplib::Request& req, httplib::Response& res) {
        HiHandler(*DataSource, req, res);
    });
    Server->Get(R"(/api/admin/numbers/(\d+))", [&](const httplib::Request& req, httplib::Response& res) {
        NumbersHandler(*DataSource, req, res);
    });

    Server->Post("/api/signup", [&](const httplib::Request& req, httplib::Response& res) {
        UserSignupHandler(*DataSource, req, res);
    });
}

void TApplication::Start() {
    INFO_LOG << "Started HTTP-server on port: " << Config["Server"]["Port"] << Endl;
    Server->listen("0.0.0.0", Config["Server"]["Port"]);
}

TApplication::~TApplication() {
    Server->stop();
    INFO_LOG << "Stopped HTTP-server" << Endl;
}
