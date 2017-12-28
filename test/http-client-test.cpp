#include <iostream>
#include <reyco/AppFactory.h>
#include <reyco/HttpClient.h>

namespace reyco {

class HttpClientFetcher : public HttpClient::Fetcher {
public:
  std::string fetch(const std::string &url) override {
    using namespace std::literals::string_literals;

    return "Hello from: "s + url;
  }
};

void main() {
  HttpClientFetcher fetcher;
  auto client = HttpClient::make("127.0.0.1:8080", fetcher);
  std::cout << client->get("") << std::endl;
  std::cout << client->get("about") << std::endl;
}
}
int main() { return reyco::AppFactory::make(reyco::main); }
