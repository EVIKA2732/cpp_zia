#ifndef CPP_ZIA_PARSER_HH
#define CPP_ZIA_PARSER_HH

#include "api.h"

namespace nz {
  class Parser
  {
   public:
    Parser();

    void callbackRequestReceived(::zia::api::Net::Raw raw, ::zia::api::NetInfo netInfo);
  };
}

#endif //CPP_ZIA_PARSER_HH