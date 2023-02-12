#pragma once
#include "CustomerQueue.hpp"

class BankSimulator {
private:
	int nSimulation;
	double probArrival;
	int tMaxService;
	int totalWaitTime;
	int nCustomers;
	int nServedCustomers;

	CustomerQueue que;

	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewCustomer() { return Random() < probArrival; }
	int RandServiceTime() { return(int)(tMaxService * Random()) + 1; }

	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		printf("���� %d �湮(���� �ð�:%d��)\n", a.id, a.tService);
		que.enqueue(a);
	}

public:
	BankSimulator(): nCustomers(0), totalWaitTime(0), nServedCustomers(0){}

	void readSimulationParameters() {
		printf("�ùķ��̼� �� �ִ� �ð� (��:10) = ");
		scanf("%d", &nSimulation);

		printf("�����ð��� �����ϴ� ���� �� (��:0.7) = ");
		scanf("%lf", &probArrival);

		printf("�� ������ ���� �ִ� ���� �ð� (��:5) = ");
		scanf("%d", &tMaxService);

		printf("====================================================\n");
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;
	
		while (clock < nSimulation)
		{
			clock++;
			printf("����ð�?=%d\n", clock);

			if (IsNewCustomer())
			{
				InsertCustomer(clock);
			}

			if (serviceTime > 0)
			{
				serviceTime--;
			}
			else
			{
				if (que.isEmpty())
				{
					continue;
				}

				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArrival;
				printf("���� %d ���� ���� (���ð�:%d��)\n", a.id, clock - a.tArrival);

				serviceTime = a.tService - 1;
			}
		}
	}

	void printStat() {
		printf("================================================\n");

		printf("	���� ���� ������	=%d\n", nServedCustomers);
		printf("	��ü ���? �ð�	=%d��\n", totalWaitTime);
		printf("	���񽺰��� ��մ��ð�?	=%-5.2f��\n", (double)totalWaitTime/nServedCustomers);
		printf("	���� ���? ���� ��	=%d\n", nCustomers -nServedCustomers);
	}

};