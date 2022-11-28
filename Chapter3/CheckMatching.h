#pragma once
#include "ArrayStack.h"
using namespace std;

bool checkMatching(const char* filename) {
	FILE* p_file = NULL;
	errno_t fp = fopen_s(&p_file, filename, "r");

	if (p_file == NULL)
	{
		error("Error: 파일이 존재하지 않습니다\n");
	}

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;
	bool small_quote_flag = false;

	while ((ch = getc(p_file)) != EOF)
	{

		stack.display();
		cout << "Line : " << nLine << endl;

		if (ch == '\n')
		{
			nLine++;
		}

		nChar++;

		if (ch == '\'' && small_quote_flag == false)
		{
			small_quote_flag = true;
		}
		else if (ch == '\'' && small_quote_flag == true)
		{
			small_quote_flag = false;
		}


		if (ch == '[' || ch == '(' || ch == '{')
		{
			if (small_quote_flag == false)
			{
				stack.push(ch);
			}
		}
		else if (ch == ']' || ch == ')' || ch == '}')
		{

			if (small_quote_flag == false)
			{
				int prev = stack.pop();
				if ((ch == ']' && prev != '[') ||
					(ch == ')' && prev != '(') ||
					(ch == '}' && prev != '{'))
				{
					break;
				}
			}
		}
	}

	fclose(p_file);

	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
	{
		printf("Error: 문제발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	}
	else
	{
		printf("OK: 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	}
	return stack.isEmpty();
};