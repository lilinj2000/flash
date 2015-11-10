#include <memory>
#include "FlashMultiConfig.hh"
#include "MultiMDServer.hh"
#include "soil/STimer.hh"

int main(int argc, char* argv[])
{

  std::unique_ptr<flash::FlashConfig> config;
  config.reset(new flash::FlashConfig(argc, argv));

  flash::FlashMultiOptions* multi_options = config->flashMultiOptions();

  std::unique_ptr<flash::MultiMDServer> server;
  server.reset(new flash::MultiMDServer(config->foalMultiMDOptions(),
                                        multi_options->instrument_id,
                                        multi_options->multi_md_file,
                                        multi_options->speed_md_file));
  
  std::unique_ptr<soil::STimer> cond;
  cond.reset( soil::STimer::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
