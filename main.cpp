#include "crow.h"

int main() {
    crow::SimpleApp app;

    // Route: GET Request on Root '/'
    CROW_ROUTE(app, "/")([](){
        return "Welcome to the Crow C++ Web Server!";
    });

    // Route: POST Request on '/submit'
    CROW_ROUTE(app, "/submit").methods("POST"_method)([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(400);
        std::string message = "Received: " + std::string(x["message"].s());
        return crow::response{message};
    });

    // Route: GET Request with URL Parameters '/params/<int>/<string>'
    CROW_ROUTE(app, "/params/<int>/<string>")([](int int_param, std::string str_param){
        std::ostringstream os;
        os << "Int: " << int_param << ", String: " << str_param;
        return crow::response{os.str()};
    });

    // Run the Server
    app.port(18080).multithreaded().run();

    return 0;
}
