#include "rtweekend.h"

#include <iostream>
#include <iomanip>

int main()
{
    int inside_circle = 0;
    int inside_circle_stratified = 0;
    int sqrt_N = 10000;
    for (int i = 0; i < sqrt_N; i++)
    {
        for (int j = 0; j < sqrt_N; j++)
        {
            // 普通抽样
            auto x = random_double(-1, 1);
            auto y = random_double(-1, 1);
            if (x * x + y * y < 1)
                inside_circle++;

            // 分层抽样
            // random_double()的范围是[0,1）
            // (i + random_double()) / sqrt_N 的范围是[0,1)
            // 2*((i + random_double()) / sqrt_N) - 1 取值范围是(-1,1)
            x = 2 * ((i + random_double()) / sqrt_N) - 1; // x的取值范围是(-1,1)
            y = 2 * ((j + random_double()) / sqrt_N) - 1; // y的取值范围是(-1,1)
            if (x * x + y * y < 1)
                inside_circle_stratified++;
        }
    }

    auto N = static_cast<double>(sqrt_N) * sqrt_N;
    std::cout << std::fixed << std::setprecision(12);
    std::cout
        << "Regular    Estimate of Pi = "
        << 4 * double(inside_circle) / (sqrt_N * sqrt_N) << '\n'
        << "Stratified Estimate of Pi = "
        << 4 * double(inside_circle_stratified) / (sqrt_N * sqrt_N) << '\n';
}