#pragma once
#include <memory>

namespace reyco {

class HttpClient {
public:
  class Fetcher;

  HttpClient(const std::string &host, Fetcher &fetcher);
  virtual ~HttpClient();
  static std::unique_ptr<HttpClient> make(const std::string &host,
                                          Fetcher &fetcher);

  std::string get(const std::string &path);

private:
  std::string host;
  Fetcher &fetcher;
};

class HttpClient::Fetcher {
public:
  virtual ~Fetcher();
  virtual std::string fetch(const std::string &url) = 0;
};
}
