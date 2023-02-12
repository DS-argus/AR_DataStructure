#pragma once
#include <stdio.h>

#include "ArrayStack.hpp"

using namespace std;

bool checkMatching(const char* filename) {
	// FILE* p_file = NULL;
	FILE *p_file = fopen(filename, "r");

	if (p_file == NULL)
	{
		error("Error: File does not exist\n");
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

	printf("[%s] Result of inspection:\n", filename);
	if (!stack.isEmpty())
	{
		printf("Error: Error detected!(lines=%d, words=%d)\n\n", nLine, nChar);
	}
	else
	{
		printf("OK: No problem(lines=%d, words=%d)\n\n", nLine, nChar);
	}
	return stack.isEmpty();
};