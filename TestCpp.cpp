﻿//메모리 사용량이 계속 늘어나는 문제가 있음. 코드상의 문제를 찾고 해결하시오. 

#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int questionsCount)
        : answers(NULL)
    {
        this->questionsCount = questionsCount;
        if(questionsCount > 0){
            answers = new int[questionsCount];
            for (int i = 0; i < questionsCount; i++)
            {
                answers[i] = -1;
            }
        }        
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }
    
    ~MultipleChoiceTest()
    {
        if(answers) 
            delete[] answers;
    }

protected:
    int questionsCount;

private:
    int* answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }
    
    ~TimedMultipleChoiceTest()
    {
        if(times)
            delete[] times;
        
    }

private:
    int* times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);

    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }

    for (int i = 0; i < 5; i++)
    {

    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif
