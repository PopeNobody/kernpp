#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Tracer {
    char id;
    static char next_id;

    Tracer() : id(next_id++) {
        cout << "Default constructor [" << id << "]\n";
    }

    Tracer(const Tracer& other) : id(next_id++) {
        cout << "Copy constructor [" << id << "] from [" << other.id << "]\n";
    }

    Tracer(Tracer&& other) noexcept : id(next_id++) {
        cout << "Move constructor [" << id << "] from [" << other.id << "]\n";
    }

    Tracer& operator=(const Tracer& other) {
        cout << "Copy assignment [" << id << "] from [" << other.id << "]\n";
        return *this;
    }

    Tracer& operator=(Tracer&& other) noexcept {
        cout << "Move assignment [" << id << "] from [" << other.id << "]\n";
        return *this;
    }

    ~Tracer() {
        cout << "Destructor [" << id << "]\n";
    }
};

char Tracer::next_id = 'a';

template<typename T>
void pass_through(T&& t) {
    cout << "--- In pass_through ---\n";
    Tracer local = std::forward<T>(t);
    cout << "--- Leaving pass_through ---\n";
}

int main() {
    cout << "---- Construct a ----\n";
    Tracer a;

    cout << "---- Copy construct b from a ----\n";
    Tracer b = a;  // copy constructor

    cout << "---- Move construct c from a ----\n";
    Tracer c = std::move(a);  // move constructor

    cout << "---- Copy assign c from b ----\n";
    c = b;  // copy assignment

    cout << "---- Move assign c from b ----\n";
    c = std::move(b);  // move assignment

    cout << "---- Push into vector ----\n";
    vector<Tracer> v;

    cout << "---- v.push_back(a) ----\n";
    v.push_back(a);  // copy

    cout << "---- v.push_back(move(a)) ----\n";
    v.push_back(std::move(a));  // move

    cout << "---- Calling pass_through(a) ----\n";
    pass_through(a);  // lvalue, triggers copy

    cout << "---- Calling pass_through(move(a)) ----\n";
    pass_through(std::move(a));  // rvalue, triggers move

    cout << "---- End of scope ----\n";
}
