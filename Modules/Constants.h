#pragma once

class Constants {
public:
    static constexpr double AccRate = 3.5;           // Acceleration rate for cars in m/s
    static constexpr double AccRateEmpty = 2.5;      // Acceleration rate for light trucks in m/s
    static constexpr double AccRateFull = 1.0;       // Acceleration rate for heavy trucks in m/s
    static constexpr double DecRate = 7.0;           // Braking rate for cars in m/s
    static constexpr double DecRateEmpty = 5.0;      // Braking rate for light trucks in m/s
    static constexpr double DecRateFull = 2.0;       // Braking rate for light trucks in m/s
    static constexpr double MpsToMph = 2.237;
};
