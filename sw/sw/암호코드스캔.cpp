#include<iostream>
#include<string.h>

using namespace std;

#define MAX 2000L
#define endl "\n"

int HexaToBinary[16][4] = {
	{0,0,0,0}, //0
	{0,0,0,1}, //1
	{0,0,1,0}, //2
	{0,0,1,1}, //3
	{0,1,0,0}, //4
	{0,1,0,1}, //5
	{0,1,1,0}, //6
	{0,1,1,1}, //7
	{1,0,0,0}, //8
	{1,0,0,1}, //9
	{1,0,1,0}, //10(A)
	{1,0,1,1}, //11(B)
	{1,1,0,0}, //12(C)
	{1,1,0,1}, //13(D)
	{1,1,1,0}, //14(E)
	{1,1,1,1} }; //15(F)

int code[5][5][5];
int answer;
int	N, M;
int MAP[MAX][MAX];

//�� ���ڸ� �����ϴ� ���� �־����
void SettingCode() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				code[i][j][k] = -1;
			}
		}
	}
	code[2][1][1] = 0;
	code[2][2][1] = 1;
	code[1][2][2] = 2;
	code[4][1][1] = 3;
	code[1][3][2] = 4;
	code[2][3][1] = 5;
	code[1][1][4] = 6;
	code[3][1][2] = 7;
	code[2][1][3] = 8;
	code[1][1][2] = 9;
}

void Initialize() {
	answer = 0;
}

void Input() {
	
	cin >> N >> M;

	//�Է� �ް� ���� char�� int�� ��ȯ���ָ鼭 2������ ��ȯ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j<M; j++) {
			char C; cin >> C;
			if (C <= '9') C = C - '0';
			else C = C - 'A' + 10;

			for(int k=0;k<4;k++){
				MAP[i][j * 4 + k] = HexaToBinary[C][k];
			}
		}
	}
}

void Solution() {
	int Answer_Idx = 7;
	int Answer_Arr[8] = { 0, };

	//1,0,1�� � ������ �����Ǿ��ִ��� Ȯ�� �۾�
	for (int i = 1; i < N; i++) {
		for (int j = M * 4 - 1; j >= 0; j--) {
			int Part[3] = { 0,0,0 };

			if (MAP[i][j] == 1 && MAP[i - 1][j] == 0) {
				while (MAP[i][j] == 1) {
					Part[2]++;
					j--;
				}
				while (MAP[i][j] == 0) {
					Part[1]++;
					j--;
				}
				while (MAP[i][j] == 1) {
					Part[0]++;
					j--;
				}
				j++;

				int Min = Part[2];
				if (Part[1] < Min) Min = Part[1];
				if (Part[0] < Min) Min = Part[0];

				for (int i = 0; i < 3; i++) Part[i] = Part[i] / Min;

				//answer_arr �� ĭ�� ������ �´� ���� ���ڸ� �־���
				Answer_Arr[Answer_Idx--] = code[Part[0]][Part[1]][Part[2]];
				
				//-1 �� ����ִٸ� �߸��� ��ȣ
				if (Answer_Arr[Answer_Idx + 1] == -1) {
					answer = 0;
					return;
				}
				//answer_idx �� �� / ��� ��ȣ���� �ص��Ϸ� �Ǿ��ٸ�
				if (Answer_Idx == -1) {
					//���� ��ȣ���� Ȯ��
					int Value = (Answer_Arr[0] + Answer_Arr[2] + Answer_Arr[4] + Answer_Arr[6])
						* 3 + Answer_Arr[1] + Answer_Arr[3] + Answer_Arr[5] + Answer_Arr[7];
					//���� ��ȣ��
					if (Value % 10 == 0) {
						for (int i = 0; i < 8; i++)
							answer += Answer_Arr[i];
					}
					Answer_Idx = 7;
				}
			}
		}
	}
}

void Solve() {
	SettingCode();
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		Initialize();
		Input();
		Solution();

		cout << "#" << test_case << " " << answer << endl;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}