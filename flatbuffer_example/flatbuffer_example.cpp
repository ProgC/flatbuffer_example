#include "stdafx.h"
#include <iostream>

#include "flatbuffers/flatbuffers.h"
#include "mydata_generated.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace ProgC::PlayerData;

	// 메모리에 데이터를 만들고 읽어 들이기.
	/*flatbuffers::FlatBufferBuilder builder;
	auto name = builder.CreateString("ProgC");
	auto object = CreatePlayer(builder, 0, 100);	
	builder.Finish(object);
	
	uint8_t* buf = builder.GetBufferPointer();

	auto player = ProgC::PlayerData::GetPlayer(buf);
	cout << player->id() << endl;
	cout << player->hp() << endl;*/

	// 메모리에 데이터를 만들고 파일로 저장한 후 파일에서 읽어 들이기
	flatbuffers::FlatBufferBuilder builder;
	auto name = builder.CreateString("ProgC");
	auto object = CreatePlayer(builder, 1, 250);
	builder.Finish(object);
	
	FILE* fp = fopen("progc.dat", "wb");
	uint8_t* buf = builder.GetBufferPointer();
	fwrite(buf, builder.GetSize(), 1, fp);
	fclose(fp);

	FILE* readingFile = fopen("progc.dat", "rb");
	fseek(readingFile, 0L, SEEK_END);
	int length = ftell(readingFile);
	fseek(readingFile, 0L, SEEK_SET);
	char *data = new char[length];
	fread(data, sizeof(char), length, readingFile);
	fclose(readingFile);

	auto player = ProgC::PlayerData::GetPlayer(data);
	cout << player->id() << endl;
	cout << player->hp() << endl;
	return 0;
}

