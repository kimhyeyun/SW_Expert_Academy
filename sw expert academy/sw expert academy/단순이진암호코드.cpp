#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

int N, M, sum, sum_a;
string code[] = { "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" }; 
//�� �ε��� ��ȯ �ڵ�
int c_code[9] = { 0, };
//�˻��� �ڵ尡 �� �迭
string tmp;
//�Է¹��� string ���� ����� string �� ������ string

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;

		string str;

		for (int a = 0; a < N; a++) {
			cin >> str;
			if (str.find('1') != -1) //1�� �߰ߵǸ� string �� �ֱ�
				tmp = str;

		}
		tmp.assign(tmp, tmp.rfind("1") - 55, 56); //�˻��� string �߿��� ����� 56���� �ڵ常 ��������
		int num_idx = 1;
		
		for (int i = 0; i < tmp.length(); i = i + 7) { //7���� �߶�
			string c_str = tmp.substr(i, 7); 

			for (int i = 0; i < 10; i++) {//������ �����س��� string �� ��
				if (c_str == code[i]) {
					c_code[num_idx] = i; //��ġ�ϸ� �� �ڵ��� ���� ���ڸ� �־��ֱ�
					num_idx++;
					break;
				}
			}

		}	

		sum = 0;
		sum_a = 0;
		
		//�ڵ尡 ���������� �˻�
		for (int a = 1; a <= 7; a++) {
			sum_a += c_code[a];

			if (a % 2 == 0)
				sum += c_code[a];
			else
				sum += (c_code[a] * 3);
		}
		sum += c_code[8];
		sum_a += c_code[8];
		

		if (sum % 10 == 0)
			cout << "#" << test_case << " " << sum_a << endl;
		else
			cout << "#" << test_case << " " << 0 << endl;

		memset(c_code, 0, sizeof(c_code)); //�迭 �ʱ�ȭ

	}

}
