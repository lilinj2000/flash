#include <memory>
#include "FlashMultiConfig.hh"
#include "MultiMDServer.hh"
#include "soil/Condition.hh"

int main(int argc, char* argv[])
{

  std::auto_ptr<flash::FlashConfig> config;
  config.reset(new flash::FlashConfig(argc, argv));

  flash::FlashMultiOptions* multi_options = config->flashMultiOptions();

  std::auto_ptr<flash::MultiMDServer> server;
  server.reset(new flash::MultiMDServer(config->foalMultiMDOptions(),
                            multi_options->instrument_id,
                            multi_options->multi_md_file));
  
  std::auto_ptr<soil::Condition> cond;
  cond.reset( soil::Condition::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
