#pragma once

#include <vector>

#ifndef DLLExport
#define DLLExport __declspec(dllexport) 
#endif

//计算表达式运算时间
#define CALCULATE_ELAPSED_TIME(expression) do { \
    auto start = std::chrono::high_resolution_clock::now(); \
    expression; \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); \
    std::cout << "Time taken by " #expression ": " << duration << " ms" << std::endl; \
} while (false)

//计算表达式累计运算时间
#define CALCULATE_AND_ACCUMULATE_ELAPSED_TIME(expression) do { \
    static auto totalTime = std::chrono::microseconds::zero(); \
    auto start = std::chrono::high_resolution_clock::now(); \
    expression; \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); \
    totalTime += duration; \
    std::cout << "Time taken by " #expression ": " \
              << duration.count() << "mms " \
              << "accumulated: "<< totalTime.count() << " mms" << std::endl; \
} while (false)

#define SETTER(TYPE, NAME, Value) \
    void set##NAME(TYPE val) { \
        Value = val; \
    }

#define GETTER(TYPE, NAME, Value) \
    TYPE get##NAME() const { \
        return Value; \
    }

#define SETTERANDGETTER(TYPE, NAME, Value) \
    TYPE get##NAME() const { \
        return Value; \
    } \
    void set##NAME(TYPE val) { \
        Value = val; \
    }