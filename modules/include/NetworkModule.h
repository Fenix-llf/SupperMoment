#include "Module.h"
#include <map>

#define NET_MOD_ETH_IDENT   "eth"
#define NET_MOD_CAN_IDENT   "can"
#define NET_MOD_WIFI_IDENT  "wifi"

class NetworkModule : public Module {
    enum NET_MOD_TYPE {
        NET_MOD_ETH,
        NET_MOD_CAN,
        NET_MOD_WIFI,
    };

public:
    NetworkModule(std::map<std::string, std::string> parameters);
    void init();
    void deinit();
    Module::TEST_RES test();

private:
    std::string netIdent;
};
