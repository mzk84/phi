#include "crow_all.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <boost/filesystem.hpp>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

void sendFile(crow::response &res, std::string filename, std::string contentType){
  std::ifstream in("../cpp_web/public/" + filename, std::ifstream::in);
  if(in) {
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    res.set_header("Content-Type", contentType);
    res.write(contents.str());
  } else {
    res.code = 404;
    res.write("Not found: ../public/" + filename);
  }
  res.end();
}

void sendHtml(crow::response &res, std::string filename){
  sendFile(res, filename + ".html", "text/html");
}

void sendImage(crow::response &res, std::string filename){
  sendFile(res, "images/" + filename, "image/jpeg");
}

void sendScript(crow::response &res, std::string filename){
  sendFile(res, "scripts/" + filename, "text/javascript");
}

void sendStyle(crow::response &res, std::string filename){
  sendFile(res, "styles/" + filename, "text/css");
}

int main() {
	crow::SimpleApp app;

  mongocxx::instance inst{};
  std::string mongoUrl = std::string(getenv("MONGODB_URI"));
  mongocxx::client conn{mongocxx::uri{mongoUrl}};
  mongocxx::database db = conn["cpp_web_db"];

  auto collection = db["contacts"];

	CROW_ROUTE(app, "/styles/<string>")
    ([](const crow::request &req, crow::response &res, std::string filename){
      sendStyle(res, filename);
    });

  CROW_ROUTE(app, "/scripts/<string>")
    ([](const crow::request &req, crow::response &res, std::string filename){
      sendScript(res, filename);
    });

  CROW_ROUTE(app, "/images/<string>")
    ([](const crow::request &req, crow::response &res, std::string filename){
      sendImage(res, filename);
    });

  CROW_ROUTE(app, "/")
    ([](const crow::request &req, crow::response &res){
      sendHtml(res, "index");
    });

          CROW_ROUTE(app, "/contacts")
    ([&collection](){
      mongocxx::options::find opts;
      opts.limit(10);
      auto docs = collection.find({}, opts);
      std::ostringstream os;
      for (auto&& doc : docs) {
        os << bsoncxx::to_json(doc) << "\n";
      }
      return crow::response(os.str());
    });

	char* port = getenv("PORT");
	uint16_t iPort = static_cast<uint16_t>(port != nullptr ? std::stoi(port) : 18080);

	std::cout << "Port: " << iPort << "\n";

	app.port(iPort).multithreaded().run();

	return 0;
}
