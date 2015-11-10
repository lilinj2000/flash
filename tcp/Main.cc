#include <memory>
#include "FlashTCPConfig.hh"
#include "MDServer.hh"
#include "soil/STimer.hh"

int main(int argc, char* argv[])
{

  std::unique_ptr<flash::FlashConfig> config;
  config.reset(new flash::FlashConfig(argc, argv));

  flash::FlashTCPOptions* tcp_options = config->flashTCPOptions();

  std::unique_ptr<flash::MDServer> server;
  server.reset(new flash::MDServer(config->foalMDOptions(),
                                   tcp_options->instrument_id,
                                   tcp_options->tcp_md_file,
                                   tcp_options->speed_md_file));
  
  std::unique_ptr<soil::STimer> cond;
  cond.reset( soil::STimer::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
