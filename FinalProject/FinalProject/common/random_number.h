#pragma once
#include <random>

class RNGf
{
public:

    RNGf()
		: gen( rd() )
		, dis(0.0f, 1.0f)
	{}

    float get()
	{
		return dis(gen);
	}

    float getRange(float min, float max)
	{
		return min + get() * (max - min);
	}

    float getRange(float width)
	{
		return getRange(-width * 0.5f, width * 0.5f);
	}

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;
};
