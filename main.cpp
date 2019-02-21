#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>

void f() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
    // std::chrono::high_resolution_clock
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    f();
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    // 整数时长：要求 duration_cast
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    // 小数时长：不要求 duration_cast
    std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
    std::cout << "f() took " << fp_ms.count() << " ms, "  << "or " << int_ms.count() << " whole milliseconds\n";

    // steady_clock
    std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();
    f();
    std::chrono::steady_clock::time_point t4 = std::chrono::steady_clock::now();
    std::cout << "f() took " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " us.\n";
}
