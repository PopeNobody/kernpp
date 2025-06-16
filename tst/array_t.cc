void test_array() {
    array<int, 8> a;

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    for (auto x : a)
        puti(x);  // Replace with whatever output you use
}
