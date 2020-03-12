#include <stdio.h>
#include <Windows.h>

#define DATA_SIZE 40000        //�������ֵ������Χ��
#define FACTOR ((i % 5) == 0)//ɸѡ����
#define BYTE_LEN 8                 //λ�ĳ���

void initData(char* data, int len) {
	unsigned int n = len * BYTE_LEN;
	for (unsigned int i = 0; i < n; i++) {
		if (FACTOR) {
			//�ҵ�i��Ӧ��λ
			char* p = data + (i / BYTE_LEN);
			//����Ӧλ��Ϊ1
			*p = *p | (1 << (i % BYTE_LEN));

		}
		
	}
}
bool check(char* data, int len, int value) {
	//�ҵ���Ӧλ
	char* p = data + value / BYTE_LEN;
	//�ж϶�Ӧλ�Ƿ�Ϊ1
	bool tmp = *p & (1 << (value % BYTE_LEN));
	return tmp;
}
int main() {
	//׼���洢λͼ�Ŀռ�
	unsigned int n = DATA_SIZE;
	int len = n / BYTE_LEN;
	char* data = (char*)malloc(len);
	//λͼ��ʼ��
	if (data) {
		memset(data, 0, len);
		initData(data, len);
		//ѭ���ж�
		while (1) {
			printf("������Ҫ������[����-1�˳�]: ");
			int value;
			scanf_s("%d", &value);
			if (value == -1) {
				break;
			}
			if (value > DATA_SIZE) {
				printf("��������ݳ���������Χ\n");
			}
			else {
				if (check(data, len, value)) {
					printf("%d�����ݼ�����\n", value);
				}
				else {
					printf("%d�������ݼ�����\n", value);
				}
			}
		}
	}
	system("pause");
	free(data);
	return 0;


}