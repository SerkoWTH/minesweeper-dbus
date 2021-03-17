// minesweeperStubImpl.hpp
#ifndef MINESWEEPERSTUBIMPL_H_
#define MINESWEEPERSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/minesweeperStubDefault.hpp>

class minesweeperStubImpl: public v1_0::commonapi::minesweeperStubDefault {
public:
    minesweeperStubImpl();
    virtual ~minesweeperStubImpl();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sayHelloReply_t _return);
};
#endif /* MINESWEEPERSTUBIMPL_H_ */
