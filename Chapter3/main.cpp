#include <iostream>

const int MAX_STACK_SIZE = 100;

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() 함수는 저장+프로세스 종료 의미, exit(1)은 에러메세지 종료, exit(0)은 정상종료
}

#include "ArrayStack.hpp"
#include "CheckMatching.hpp"
#include "EvalPostfixMain.hpp"
#include "Infix3Postfix.hpp"
#include "MazeSolver.hpp"
#include "OperandStack.hpp"
#include "Student.hpp"
#include "StudentStack.hpp"


int main()
{
	// checkMatching("CheckMatching.h");
	// //checkMatching("ArrayStack.h");
	mazeSolver();

} 

