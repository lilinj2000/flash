#ifndef FLASH_SERVER_HH
#define FLASH_SERVER_HH

#include <memory>
#include "soil/Condition.hh"

namespace flash
{

class FlashConfig;
class MDServer;
class MultiMDServer;

class FlashServer
{
 public:
  FlashServer(int argc, char* argv[]);

  ~FlashServer();

 private:
  std::auto_ptr<soil::Condition> cond_;
  
  std::auto_ptr<FlashConfig> flash_config_;
  
  std::auto_ptr<MDServer> md_server_;
  
  std::auto_ptr<MultiMDServer> multimd_server_;
};

};

#endif
