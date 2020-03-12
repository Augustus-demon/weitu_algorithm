#include <stdio.h>
#include <Windows.h>

#define DATA_SIZE 40000        //数据最大值（即范围）
#define FACTOR ((i % 5) == 0)//筛选条件
#define BYTE_LEN 8                 //位的长度

void initData(char* data, int len) {
	unsigned int n = len * BYTE_LEN;
	for (unsigned int i = 0; i < n; i++) {
		if (FACTOR) {
			//找到i对应的位
			char* p = data + (i / BYTE_LEN);
			//将对应位设为1
			*p = *p | (1 << (i % BYTE_LEN));

		}
		
	}
}
bool check(char* data, int len, int value) {
	//找到对应位
	char* p = data + value / BYTE_LEN;
	//判断对应位是否为1
	bool tmp = *p & (1 << (value % BYTE_LEN));
	return tmp;
}
int main() {
	//准备存储位图的空间
	unsigned int n = DATA_SIZE;
	int len = n / BYTE_LEN;
	char* data = (char*)malloc(len);
	//位图初始化
	if (data) {
		memset(data, 0, len);
		initData(data, len);
		//循环判断
		while (1) {
			printf("请输入要检测的数[输入-1退出]: ");
			int value;
			scanf_s("%d", &value);
			if (value == -1) {
				break;
			}
			if (value > DATA_SIZE) {
				printf("输入的数据超出所给范围\n");
			}
			else {
				if (check(data, len, value)) {
					printf("%d在数据集合中\n", value);
				}
				else {
					printf("%d不在数据集合中\n", value);
				}
			}
		}
	}
	system("pause");
	free(data);
	return 0;


}