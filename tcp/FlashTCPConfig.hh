#ifndef FLASH_TCP_CONFIG_HH
#define FLASH_TCP_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace flash
{

namespace po = boost::program_options;

class FlashTCPOptions : public soil::Options
{
 public:

  FlashTCPOptions();
  
  virtual ~FlashTCPOptions();

  virtual po::options_description* configOptions();

  std::string instrument_id;
  std::string tcp_md_file;
  std::string speed_md_file;
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class FlashConfig
{
 public:
  
  FlashConfig(int argc=0, char* argv[]=NULL);
  ~FlashConfig();

  FlashTCPOptions* flashTCPOptions()
  {
    return flash_tcp_options_.get();
  }

  soil::Options* foalMDOptions()
  {
    return foal_md_options_.get();
  }

 private:
  std::unique_ptr<FlashTCPOptions> flash_tcp_options_;
  
  std::unique_ptr<soil::Options> foal_md_options_;

};

}  


#endif 
