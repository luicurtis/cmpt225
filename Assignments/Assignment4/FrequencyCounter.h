/*
 * FrequencyCounter.h
 *
 * Description: Counts the frequncy of characters that appear in a file
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: March 2019
 *
 */

#pragma once


class FrequencyCounter
{
    private:
        int frequency;

    public:
    FrequencyCounter();

    int getFrequency() const;
    void incrementFrequency();
};