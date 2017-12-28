#include <reyco/HttpClient.h>

namespace reyco {

HttpClient::~HttpClient() = default;

HttpClient::HttpClient(const std::string &host, Fetcher &fetcher)
    : host(host), fetcher(fetcher) {}

std::unique_ptr<HttpClient> HttpClient::make(const std::string &host,
                                             HttpClient::Fetcher &fetcher) {
  return std::make_unique<HttpClient>(host, fetcher);
}

std::string HttpClient::get(const std::string &path) {
  using namespace std::literals::string_literals;
  return fetcher.fetch(host + "/"s + path);
}

HttpClient::Fetcher::~Fetcher() {}
}
