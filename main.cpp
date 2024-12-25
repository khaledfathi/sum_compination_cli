/*
file : main.cpp
description : sum compination cli app
author : dev@khaledfathi.com
standerd : C++11
licence : MIT
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<double> getNumbers(int argc, char *argv[]);
std::vector<std::vector<double>> calculate(std::vector<double> numberList);
void printResults(std::vector<std::vector<double>> res);

int main(int argc, char *argv[])
{
    try
    {
        std::vector<double> numbers = getNumbers(argc, argv);
        printResults(calculate(numbers));
    }
    catch (const std::exception &e)
    {
        std::cout << "Error : Invalid Arguments , be sure to enter only numbers" << std::endl;
    }
    return 0;
}

/*##### CORE #####*/

std::vector<double> getNumbers(int argc, char *argv[])
{
    // get numbers
    std::vector<double> numbers;
    for (int i = 1; i < argc; i++)
    {
        double num = std::stod(argv[i]);
        numbers.push_back(num);
    }
    return numbers;
}

std::vector<std::vector<double>> calculate(std::vector<double> numberList)
{
    //get target (last element in list)
    double target = numberList.back(); 
    // sort and reverse
    std::sort(numberList.begin(), numberList.end());
    std::reverse(numberList.begin(), numberList.end());

    // buffer and result
    std::vector<double> bufferList;
    std::vector<std::vector<double>> result;

    //
    std::cout  << target << std::endl; 
    for (int i = 0; i < numberList.size(); i++)
    {
        bufferList.push_back(numberList[i]);
        if (i + 1 < numberList.size())
        {
            for (int j = i + 1; j < numberList.size(); j++)
            {
                bufferList.push_back(numberList[j]);
                // summ all bufferList
                double bufferListSum = std::accumulate(bufferList.begin(), bufferList.end(), decltype(bufferList)::value_type(0));
                if (bufferListSum > target)
                {
                    bufferList.pop_back();
                }
                else if (bufferListSum == target)
                {
                    result.push_back(bufferList);
                    bufferList.pop_back();
                }
            }
        }
        bufferList.clear();
    }
    return result;
}

void printResults(std::vector<std::vector<double>> results)
{
    if(results.size() == 0){
        std::cout<< "Calculation [OK] -> No Result Matches \n"; 
    }
    for (auto  result : results)
    {
        std::cout << "[ ";
        int resultSize = result.size(); 
        for (int i=0 ; i<resultSize; i++)
        {
            std::cout << result[i] ;
            if(i+1 < resultSize){
                std::cout << " + ";
            }
        }

        std::cout << " ]\n";
    }
}