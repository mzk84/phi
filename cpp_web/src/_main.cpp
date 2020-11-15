#include "crow_all.h"
#include "_mzk84_utils.h"

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")
		([]() {
		return "<div><h1>Hello, World! :)</h1></div>";
			});

	char* port = getenv("PORT");
	uint16_t iPort = static_cast<uint16_t>(port != nullptr ? std::stoi(port) : 18080);

	std::cout << "Port: " << iPort << "\n";

	app.port(iPort).multithreaded().run();

	return 0;
}
