#include "Util.hh"

namespace flash
{

air::SpeedMData* Util::toSpeedMData(const foal::DepthMarketData* data)
{
  std::auto_ptr<air::SpeedMData> speed_data(new air::SpeedMData());
  
  speed_data->instru = data->InstrumentID;
  speed_data->update_time = data->UpdateTime;
  speed_data->update_millisec = data->UpdateMillisec;
  speed_data->time_stamp = data->time_stamp;

  return speed_data.release();
}


air::CffexMData* Util::toCffexMData(const foal::DepthMarketData* data)
{
  std::auto_ptr<air::CffexMData> cffex_data(new air::CffexMData());

  cffex_data->TradingDay = data->TradingDay;
  cffex_data->SettlementGroupID = data->SettlementGroupID;
  cffex_data->SettlementID = data->SettlementID;
  cffex_data->PreSettlementPrice = data->PreSettlementPrice;
  cffex_data->PreClosePrice = data->PreClosePrice;
  cffex_data->PreOpenInterest = data->PreOpenInterest;
  cffex_data->PreDelta = data->PreDelta;
  cffex_data->OpenPrice = data->OpenPrice;
  cffex_data->HighestPrice = data->HighestPrice;
  cffex_data->LowestPrice = data->LowestPrice;
  cffex_data->ClosePrice = data->ClosePrice;
  cffex_data->UpperLimitPrice = data->UpperLimitPrice;
  cffex_data->LowerLimitPrice = data->LowerLimitPrice;
  cffex_data->SettlementPrice = data->SettlementPrice;
  cffex_data->CurrDelta = data->CurrDelta;
  cffex_data->LastPrice = data->LastPrice;
  cffex_data->Volume = data->LastPrice;
  cffex_data->Turnover = data->Turnover;
  cffex_data->OpenInterest = data->OpenInterest;
  
  cffex_data->BidPrice1 = data->BidPrice1;
  cffex_data->BidVolume1 = data->BidVolume1;
  cffex_data->AskPrice1 = data->AskPrice1;
  cffex_data->AskVolume1 = data->AskVolume1;
  
  cffex_data->BidPrice2 = data->BidPrice2;
  cffex_data->BidVolume2 = data->BidVolume2;
  cffex_data->AskPrice2 = data->AskPrice2;
  cffex_data->AskVolume2 = data->AskVolume2;

  cffex_data->BidPrice3 = data->BidPrice3;
  cffex_data->BidVolume3 = data->BidVolume3;
  cffex_data->AskPrice3 = data->AskPrice3;
  cffex_data->AskVolume3 = data->AskVolume3;

  cffex_data->BidPrice4 = data->BidPrice4;
  cffex_data->BidVolume4 = data->BidVolume4;
  cffex_data->AskPrice4 = data->AskPrice4;
  cffex_data->AskVolume4 = data->AskVolume4;

  cffex_data->BidPrice5 = data->BidPrice5;
  cffex_data->BidVolume5 = data->BidVolume5;
  cffex_data->AskPrice5 = data->AskPrice5;
  cffex_data->AskVolume5 = data->AskVolume5;

  cffex_data->InstrumentID = data->InstrumentID;
  cffex_data->UpdateTime = data->UpdateTime;
  cffex_data->UpdateMillisec = data->UpdateMillisec;

  return cffex_data.release();

}

};
