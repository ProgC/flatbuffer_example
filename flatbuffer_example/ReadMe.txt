﻿이 프로젝트는 google의 flat buffer의 간단한 사용법에 대한 코드입니다.

flatbuffer를 실제로 받으신 후에 컴파일 하시면 flatc라는 플랫 버퍼 컴파일러가 생기는데 이것으로

flatc --cpp 파일명

과 같이 파일을 만드신 후 이것으로 시리얼라이즈/디시리얼라이즈 가능합니다.

대략적인 순서.

1. flatbuffer 프로젝트를 받은 후 컴파일러를 빌드 한다.
2. flatc 컴파일러를 이용해서 idl파일로 c++용 헤더를 만든다.
3. 헤더를 이용해서 인스턴스를 만들거나 바이너리 형태로 시리얼라이즈 한다.

예제에는 2가지 형태를 제공하는데 

첫번째는 메모리에서 인스턴스를 만들고 바로 사용하는 방법과
둘째는 메모리에서 인스턴스를 만들고 시리얼라이즈 해 바이너리 파일로 만든 후 해당 파일을 다시 메모리로 읽어들여 디시리얼라이즈 하는 방법을 다루고 있습니다.

