
const int MAXNAMELEN = 101;//������󳤶� 
const int MAXLEN = 10001;//�����ģ����� 
struct Data{//ÿ��Data�洢һ��ģ��Ľ��
	char dataName[MAXNAMELEN];
	int roundCount;//�غ��� 
	int startTeam;//��ʼ�������飨1A 2B�� 
	char nameA[MAXNAMELEN];//A������ 
	char nameB[MAXNAMELEN];//B������ 
	double winRateA;//A��ʤ��
	double winRateB;//B��ʤ��
	
	int result[MAXLEN];//ÿ�ֱ���ʤ������1A��2B�� 
	 
};
Data nullData = {"NULL", 0, 0, "NULL", 0, 0, 0, 0};

Data CreateNewData(char* dataName, int roundCount, int startTeam, char* nameA, char* nameB, double winRateA, double winRateB){
	Data data;
	strcpy(data.dataName, dataName);
	data.roundCount = roundCount;
	data.startTeam = startTeam;
	strcpy(data.nameA, nameA);
	strcpy(data.nameB, nameB);
	data.winRateA = winRateA;
	data.winRateB = winRateB;
	
	return data;
}

void SetResult(Data* data, int* resultArray){
	for(int i = 0; i < data->roundCount; i++){
		data->result[i] = resultArray[i];
	}
}

void PrintDataInfo(Data *data){
	printf("��ǰͳ��:\n");
	printf("�������ƣ�%s\n", data->dataName);
	printf("����˫����%s(����ʤ��%.2lf) VS %s(����ʤ��%.2lf)\n", data->nameA, data->winRateA, data->nameB, data->winRateB);
	printf("�غ�����%d\n", data->roundCount);
	printf("�������飺%s\n", (data->startTeam == 1) ? data->nameA : data->nameB);
	printf("�������:\n");
	int aWin = 0, bWin = 0;
	for(int i = 0; i < data->roundCount; i++){
		if(data->result[i] == 1) aWin++;
		if(data->result[i] == 2) bWin++;
	}
	printf("���� %s��ʤ��������%d���Ծ�ʤ�ʣ�%.2lf\n", data->nameA, aWin, (double)aWin / data->roundCount);
	printf("���� %s��ʤ��������%d���Ծ�ʤ�ʣ�%.2lf\n", data->nameB, bWin, (double)bWin / data->roundCount);
	printf("����Ӯ�ң�%s\n", aWin == bWin ? "ƽ��" : aWin > bWin ? data->nameA : data->nameB); 
}


//��ʼ��������ʼʱ����ȡ������ļ���������ӵ�lst������ 
Data Load(){
	FILE *pf = fopen("Data.sav", "r");
	if(pf != NULL){
		char dataName[MAXNAMELEN];
		int roundCount;//�غ��� 
		int startTeam;//��ʼ�������飨1A 2B�� 
		char nameA[MAXNAMELEN];//A������ 
		char nameB[MAXNAMELEN];//B������ 
		double winRateA;//A��ʤ��
		double winRateB;//B��ʤ��
		
		int result[MAXLEN];
		
		fscanf(pf, "%s", dataName);
		fscanf(pf, "%d", &roundCount);
		fscanf(pf, "%d", &startTeam);
		fscanf(pf, "%s", nameA);
		fscanf(pf, "%s", nameB);
		fscanf(pf, "%lf", &winRateA);
		fscanf(pf, "%lf", &winRateB);
		
		
		for(int i = 0; i < roundCount; i++){
			fscanf(pf, "%d", &result[i]);
		}
		
		Data loadData = CreateNewData(dataName, roundCount, startTeam, nameA, nameB, winRateA, winRateB);
		SetResult(&loadData, result);
		
		fclose(pf);
		return loadData;
	}
	else{
		fclose(pf);
		return nullData;
	}
}

//�洢���ѵ�ǰ���б�洢����������ļ��У�������һ���汾���ļ��� 
void Save(Data* data){
	FILE *pf = fopen("Data.sav", "w");
	fprintf(pf, "%s\n%d\n%d\n%s\n%s\n%lf\n%lf\n", data->dataName, data->roundCount, data->startTeam, data->nameA, data->nameB, data->winRateA, data->winRateB); 
	for(int i = 0; i < data->roundCount; i++){
		fprintf(pf, "%d ", data->result[i]);
	}
	fclose(pf);
}

