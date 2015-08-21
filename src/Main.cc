#include <memory>
#include "FlashServer.hh"

int main(int argc, char* argv[])
{
  std::auto_ptr<flash::FlashServer> flash_server;

  flash_server.reset(new flash::FlashServer(argc, argv));
  
  return 0;
}
