#pragma once
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;
using namespace std::chrono;
using namespace std::placeholders;

static auto measureTime = [](auto func) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
};