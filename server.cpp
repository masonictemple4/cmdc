#include <boost/asio/error.hpp>
#include <boost/system/error_code.hpp>
#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <unordered_set>
#include <ostream>

using boost::asio::ip::tcp;

class ChatSession;

std::unordered_set<ChatSession*> clients;

class ChatSession : public std::enable_shared_from_this<ChatSession> {
  ChatSession(tcp::socket socket) : socket_(std::move(socket)) {}

  void start() {
    clients.insert(this);
  }

  void deliver(const std::string &msg) {
    boost::asio::async_write(socket_, boost::asio::buffer(msg+"\n"),
        [this](boost::system::error_code ec, std::size_t) {

        });
  }

  private void read_header() {
  }

  tcp::socket socket_;
  std::string data_;
  std::string nickname_ = "anonymous";
};
