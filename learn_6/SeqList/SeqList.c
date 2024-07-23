#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//��������
SeqListInfo SLData = { 0 };

//���ռ�����,�ж��Ƿ񿪱ٿռ���߿ռ䲻��,���ٿռ�
void CheckCapacity(SeqListInfo* ps)
{
	while (ps->SLCapacity <= ps->size)
	{
		//�ж��Ƿ񿪱ٳ�ʼ�ռ�,�������ݿռ�
		int newcapacity = ps->SLCapacity == 0 ? 4 : 2 * ps->SLCapacity;
		//���ٿռ�
		SLDataType* tmp = (SLDataType*)realloc(ps->arr,newcapacity * sizeof(SeqListInfo));//����ַΪNULL,����ͬmalloc
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);	//�˳���������
		}
		//���ٳɹ�
		ps->arr = tmp;
		ps->SLCapacity = newcapacity;
		tmp = NULL;
	}
}

//���ٿռ�
void SeqListDestory(SeqListInfo* ps)
{
	free(ps->arr);
	ps->arr = NULL;
}

// ��ʼ��
void SeqListInit(SeqListInfo* ps)
{
	//��ʼ����Ϊ��
	ps->SLCapacity = ps->size = 0;
	ps->arr = NULL;
}
//���
void SeqListPushBack(SeqListInfo* ps, SLDataType x)
{
	////���ռ�����,�ж��Ƿ񿪱ٿռ���߿ռ䲻��,���ٿռ�
	//CheckCapacity(ps);

	////���ռ��㹻,������������
	//ps->arr[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}
//��ɾ
void SeqListPopBack(SeqListInfo* ps)
{
	//����Խ�����
	//1.0
	if (ps->size > 0)
	{
		ps->size--;
	}
	//2.0
	//assert(ps->size >= 0);
}
//ǰ����
void SeqListPushFront(SeqListInfo* ps, SLDataType x)
{
	//���ռ�����,�ж��Ƿ񿪱ٿռ���߿ռ䲻��,���ٿռ�
	//CheckCapacity(ps);

	//�ռ��㹻,��������
	//������˳�����,���뵽ps->arr[0]
	//int i = 0;
	//for (i = ps->size; i > 0 ; i--)	//ע��Ų������,���⸲��,�Ӻ�ʼŲ��
	//{
	//	ps->arr[i] = ps->arr[i - 1];
	//}
	//ps->arr[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);

}
//ǰɾ
void SeqlistPopFront(SeqListInfo* ps)
{
	if (ps->size > 0)	//����Խ��
	{
		//������˳����ǰŲ��	��ǰ��ʼŲ��
		int i = 1;
		while (i < ps->size)
		{
			ps->arr[i - 1] = ps->arr[i];
			i++;
		}
		ps->size--;
	}

}
//�м����
//pos�����±�λ��,�� 0 ��ʼ
void SeqListInsert(SeqListInfo* ps, int pos, SLDataType x)
{
	//���ռ�����,�ж��Ƿ񿪱ٿռ���߿ռ䲻��,���ٿռ�
	CheckCapacity(ps);

	//pos�Լ���֮������ݺ���	�Ӻ��濪ʼ�ƶ�
	// 
	//�ж�pos�Ϸ���
	////1.0
	//if (pos < 0 || pos >ps->size)
	//{
	//	return;
	//}
	//2.0
	assert(pos >= 0 && pos <= ps->size);

	if (pos == ps->size)//���
	{
		ps->arr[ps->size] = x;
		ps->size++;
	}
	else	//�м����
	{
		int i = 0;
		for (i = ps->size; i > pos; i--)
		{
			ps->arr[i] = ps->arr[i - 1];
		}
		ps->arr[pos] = x;
		ps->size++;
	}

}
//�м��޸�
void SeqListReviseMiddle(SeqListInfo* ps, int pos, SLDataType x)
{
	//�ж�pos�Ϸ���
	if (pos < 0)
	{
		pos = 0;
	}
	else if (pos > ps->size)
	{
		pos = ps->size;
	}
	ps->arr[pos] = x;

}
//�м�ɾ��
void SeqListErase(SeqListInfo* ps, int pos)
{
	//�ж�pos�Ϸ���
	if (pos <= 0)//ǰɾ
	{
		SeqlistPopFront(ps);
	}
	else if (pos >= ps->size)//��ɾ
	{
		SeqListPopBack(ps);
	}
	else
	{
		int i = pos;	//��ǰ��ʼŲ��
		while (i < ps->size - 1)
		{
			ps->arr[i] = ps->arr[i + 1];
			i++;
		}
		ps->size--;
	}

}

// ˳������
int SeqListFind(SeqListInfo* ps, SLDataType x)
{
	int i = 0;
	while (i < ps->size)
	{
		if (x == ps->arr[i])
		{
			return i;	//�����±�λ��
		}
		i++;
	}
	
	return -1;
}

//�˵�
void menu()
{
	printf("************************************************************\n");
	printf("******************     ˳���             ******************\n");
	printf("******************  1.ǰ��     2.ǰɾ     ******************\n");
	printf("******************  3.���     4.��ɾ     ******************\n");
	printf("******************  5.�м��   6.�м�ɾ   ******************\n");
	printf("******************  7.�м��   8.��ӡ     ******************\n");
	printf("******************  9.��ȡ�ļ� 10.����    ******************\n");
	printf("******************  0.�����˳�            ******************\n");
	printf("************************************************************\n");

}

//��ӡ����
void SeqListPrint(SeqListInfo* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf(PRINTTYPE, ps->arr[i]);
	}
	printf("\n");
}


//��ȡ�ļ�
void GetData(SeqListInfo* ps)
{
	//���ļ�	r
	FILE* pf = fopen("SeqListData.bin", "rb");
	if (pf == NULL)
	{
		//�����ļ�
		pf = fopen("SeqListData.bin", "wb");
		if (pf == NULL)
		{
			perror("fopen SeqListData.bin error");
			exit(-1);
		}
	}
	//�ж��ļ��ֽڴ�С
	fseek(pf, 0, SEEK_END);
	long Isize = ftell(pf);//��ռ�ֽڴ�С
	rewind(pf);

	ps->size = Isize / sizeof(SLDataType);
	CheckCapacity(ps);//����

	fread(ps->arr, Isize, 1, pf);

	
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
//�˳������ļ�
void ExitSave(SeqListInfo* ps)
{
	//���ļ� WB
	FILE* pf = fopen("SeqListData.bin", "wb");
	if (pf == NULL)
	{
		perror("fopen save error");
		exit(-1);
	}
	int i = 0;
	while (i < ps->size)
	{
		fwrite(&(ps->arr[i]), sizeof(SLDataType), 1, pf);
		i++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	//���ٿռ�
	SeqListDestory(ps);
}