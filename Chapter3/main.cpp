#include <iostream>

const int MAX_STACK_SIZE = 100;

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() �Լ��� ����+���μ��� ���� �ǹ�, exit(1)�� �����޼��� ����, exit(0)�� ��������
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

