// minesweeperService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "minesweeperStubImpl.hpp"

using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<minesweeperStubImpl> myService =
        std::make_shared<minesweeperStubImpl>();
    runtime->registerService("local", "minesweeper", myService);
    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
 }
