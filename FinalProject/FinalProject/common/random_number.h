#pragma once
#include <random>
#include <chrono>

class RNGf
{
public:

    RNGf()
	{
	    reseed();
	    dis = std::uniform_real_distribution<float>(0.0f, 1.0f);
	}

	void reseed()
	{
        gen.seed( static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count()) );
	}

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
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;
};
