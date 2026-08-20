# CMyVector

`std::vector`의 핵심 동작을 직접 구현해 보며 C++의 동적 메모리 관리, 복사/이동 의미론과 연산자 오버로딩을 학습한 프로젝트입니다.

## Overview

`double` 값을 저장하는 동적 배열 클래스를 구현했습니다. 내부 배열이 가득 차면 새 메모리를 할당해 기존 데이터를 복사하고, `push_back`, `pop_back`, 검색, 삭제, capacity 축소 등의 동작을 직접 처리합니다.

또한 copy constructor, move constructor, move assignment와 `[]`, `+` 연산자를 구현해 객체 복사와 소유권 이동을 실습했습니다.

## Key Features

- 동적 배열 생성 및 해제
- capacity 초과 시 메모리 확장
- `push_back` / `pop_back`
- index 또는 value 기반 삭제
- 값 검색과 index 접근
- `size`, `capacity`, `empty`, `front`, `back`
- copy constructor / move constructor
- move assignment
- `operator[]`, `operator+`
- 사용 중인 크기에 맞춘 capacity 축소

## Technical Highlights

### 1. 직접 관리하는 동적 메모리

내부 데이터는 `double*`로 관리하고, 필요할 때 `new[]`로 할당한 뒤 destructor에서 `delete[]`로 해제합니다.

```cpp
class CMyVector
{
public:
    double* m_pdData = nullptr;
    int m_nLastIndex = 0;
    int m_nSize = 10;
};
```

capacity가 부족해지면 기존 크기의 두 배로 새 배열을 생성하고 데이터를 복사한 뒤 이전 메모리를 해제합니다.

```text
old buffer
    ↓ copy
larger buffer
    ↓
delete old buffer
    ↓
replace internal pointer
```

### 2. Copy와 Move의 차이 구현

복사 생성자는 새로운 메모리를 할당한 후 원본 데이터를 복사합니다.

반면 이동 생성자는 원본 객체가 가진 포인터를 넘겨받고 원본의 포인터를 `nullptr`로 만들어 동일한 메모리를 중복 해제하지 않도록 처리했습니다.

```cpp
CMyVector::CMyVector(CMyVector&& pParam)
{
    m_pdData = pParam.m_pdData;
    m_nSize = pParam.m_nSize;
    m_nLastIndex = pParam.m_nLastIndex;

    pParam.m_pdData = nullptr;
    pParam.m_nSize = 10;
    pParam.m_nLastIndex = 0;
}
```

### 3. 컨테이너 인터페이스 직접 설계

STL 컨테이너에서 익숙한 API를 직접 만들어 내부 상태 변화와 메모리 관리가 어떻게 연결되는지 확인했습니다.

```text
MyPush_back
MyPop_back
MyAt
MySize
MyCapacity
MyEmpty
Myfront
Myback
MyShrink
```

## Tech Stack

- C++
- Dynamic Memory Allocation
- Copy / Move Semantics
- Operator Overloading
- Visual Studio

## Project Structure

```text
190219-CMyVector/
├─ CMyVector.md        # 당시 작성한 학습 기록
├─ CMyVector.sln
└─ CMyVector/
   ├─ CMyVector.cpp    # 테스트 코드
   ├─ MyVector.h       # 클래스 인터페이스 및 연산자
   └─ MyVector.cpp     # 메모리와 컨테이너 동작 구현
```

## Limitations

이 코드는 학습 당시 구현을 그대로 보존하고 있습니다. 실제 `std::vector` 수준의 안정성과 범용성을 목표로 한 구현은 아닙니다.

- 저장 타입이 `double`로 고정되어 있습니다.
- allocator, iterator, exception safety를 지원하지 않습니다.
- 일부 index 경계 처리와 삭제 루프는 현재 다시 작성한다면 더 엄격하게 검증해야 합니다.
- move assignment에서 기존 대상 객체가 보유한 메모리를 먼저 해제하지 않아, 기존 데이터가 있는 객체에 대입할 경우 메모리 누수 가능성이 있습니다.

이 한계들은 현재 코드를 현대적인 구현처럼 포장하기보다, 당시 C++ 객체 수명과 메모리 소유권을 이해하기 위해 작성한 학습 프로젝트라는 맥락에서 명시했습니다.

## What I Learned

컨테이너 API를 사용하는 것과 직접 구현하는 것은 다른 문제라는 점을 경험했습니다. 배열 확장 시 기존 데이터의 이동, 객체 복사 시 독립적인 저장 공간 확보, 이동 시 포인터 소유권 이전과 원본 객체 초기화 등 C++ 객체 수명과 resource ownership의 기본 원리를 직접 다뤘습니다.

[← Back to project list](../README.md)
