//
// Created by kugelblitz on 5/25/19.
//

#ifndef INVINCIBLE_SERVER_REQUESTHANDLER_H
#define INVINCIBLE_SERVER_REQUESTHANDLER_H

#include <pistache/endpoint.h>
#include <iostream>
#include <sstream>

using namespace Pistache;

class requestHandler: public Http::Handler {
public:

HTTP_PROTOTYPE(requestHandler);

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        if (request.method() == Http::Method::Post) {
            if (request.resource() == "/repetir") {
                std::cout << "recibida palabra " << request.query().get("hilera").get() << std::endl;
                response.send(Pistache::Http::Code::Ok, request.query().get("hilera").get());

            }
            else if (request.resource() == "/numChars") {
                int largo = request.query().get("numChars").get().length();
                std::stringstream ss;
                ss << largo;
                response.send(Http::Code::Ok, ss.str());
                std::cout << "got a request with word " << ss.str() << std::endl;
            }
        }
        else {
            response.send(Http::Code::Ok, "<h1>Esta es la respuesta por defecto</h1>");
        }
    }
};


#endif //INVINCIBLE_SERVER_REQUESTHANDLER_H