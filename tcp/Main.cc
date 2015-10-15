#include <memory>
#include "FlashTCPConfig.hh"
#include "MDServer.hh"
#include "soil/Condition.hh"

int main(int argc, char* argv[])
{

  std::auto_ptr<flash::FlashConfig> config;
  config.reset(new flash::FlashConfig(argc, argv));

  flash::FlashTCPOptions* tcp_options = config->flashTCPOptions();

  std::auto_ptr<flash::MDServer> server;
  server.reset(new flash::MDServer(config->foalMDOptions(),
                                   tcp_options->instrument_id,
                                   tcp_options->tcp_md_file,
                                   tcp_options->speed_md_file));
  
  std::auto_ptr<soil::Condition> cond;
  cond.reset( soil::Condition::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
