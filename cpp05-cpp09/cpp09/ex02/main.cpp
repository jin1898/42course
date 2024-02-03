#include "PmergeMe.hpp"
/*
1. 음수안됨 양수정수(integer)만
2. merge-insert sort algorithm (Ford-Johnson algorithm)사용해야함.
3. 오류가 생기면 error출력해야함.

4. 1번째줄 > 인자로 들어온 정렬되지 않은 시퀀스를 출력하기
5. 2번째줄 > 정렬된 시퀀스를 출력하기
6. 3,4번째줄 > vector와 deque의 정렬시간을 출력하기
*/

int main (int argc, char **argv)
{
    try
    {
        if (argc < 2 )
            throw ": invalid arguments.";
        std::vector<int> Vec;
        std::deque<int> Deq;
        double vectorTime;
        double dequeTime;
        int isIntNum;
        for (int index = 1; index < argc; index++)
        {
            std::stringstream readstring(argv[index]);
            if (!(readstring >> isIntNum) || !(readstring.eof()))
                throw "";
            if (isIntNum < 0)
                throw ": Negative numbers are not allowed.";
            if (isIntNum > 2147483647)
                throw ": The number is too large.";
            Vec.push_back(isIntNum);
            Deq.push_back(isIntNum);
        }
        std::cout << std::endl;
        printresult(Vec);
        caluclateTime(Vec, Deq , vectorTime, dequeTime);
        std::cout << std::endl;
        printresult(Vec);
        std::cout << std::endl << "Time to process a range of " <<  argc - 1 <<  " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " <<  argc - 1 <<  " elements with std::deque :  " << dequeTime << " us" << std::endl;
    }
    catch(const char *errorMsg)
    {
        std::cout << "Error " << errorMsg << std::endl;
    }

}
