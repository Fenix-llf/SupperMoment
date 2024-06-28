#include <map>
#include <string>

class Module {

public:
    enum MOD_TYPE {
        MOD_NET,
        MOD_GPIO,
        MOD_SERIAL,
        MOD_CAN,
        MOD_BT,
        MOD_DRM,
        MOD_VOLUME,
        MOD_SCRIPT,
    };

    enum MOD_STAT {
        MOD_UNKNOWN,
        MOD_INIT_DONE,
        MOD_INIT_FAILED,
        MOD_BUSY,
        MOD_ENABLE,
        MOD_DISABLE,
    };

    enum TEST_RES {
        TEST_FAILED,
        TEST_SUCCESS
    };

    virtual enum TEST_RES test() = 0;
    virtual void init() = 0;
    virtual void deinit() = 0;

    int getId() { return this->id; };
    enum MOD_TYPE getType() { return this->type; }; 
    enum MOD_STAT getStatus() { return this->status; }; 

protected:
    std::map<std::string, std::string> parameters;

    int id;
    enum MOD_TYPE type;
    enum MOD_STAT status;
    std::string ident;

};
