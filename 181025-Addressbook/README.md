# Address Book

C로 직접 만든 단일 연결 리스트에 연락처를 저장하고, 파일에서 초기 데이터를 읽어 추가·검색·삭제·전체 출력 기능을 제공하는 콘솔 주소록입니다.

## Overview

각 연락처를 `Address` 구조체 노드로 표현하고 `p_Next` 포인터로 연결했습니다. 프로그램 시작 시 `text.txt`를 읽어 연결 리스트를 구성하고, 이후 메뉴 입력에 따라 CRUD 성격의 연산을 수행합니다.

메뉴 실행은 함수 포인터 테이블을 통해 선택하도록 구성했습니다.

## Key Features

- 텍스트 파일에서 초기 연락처 로드
- 연락처 노드 동적 할당
- 단일 연결 리스트에 연락처 추가
- 이름 기반 검색
- 이름 기반 삭제
- 전체 연락처 출력
- 함수 포인터 기반 메뉴 dispatch

## Technical Highlights

### 1. 직접 구현한 단일 연결 리스트

연락처는 이름, 전화번호와 다음 노드 포인터를 갖는 구조체로 정의했습니다.

```c
struct Address {
    char c_Name[32];
    char c_Number[20];
    struct Address *p_Next;
};
```

`create_instance`에서 `malloc`으로 노드를 생성하고, `Add_people`은 리스트 끝까지 순회한 뒤 새 노드를 연결합니다.

### 2. 검색과 삭제 시 포인터 연결 변경

검색은 현재 노드의 이름을 비교하며 순차 탐색합니다. 삭제는 이전 노드와 현재 노드를 함께 추적해 대상 노드를 제거한 후 연결 관계를 다시 설정합니다.

```text
head → node A → node B → node C
                  ↓ delete
head → node A ─────────→ node C
```

head 자체가 삭제되는 경우도 별도 처리합니다.

### 3. 함수 포인터를 이용한 메뉴 실행

메뉴 번호에 대응하는 함수들을 테이블에 저장하고 사용자 입력을 통해 해당 함수를 호출하는 구조를 실습했습니다.

```text
User Menu Input
      ↓
Function Pointer Table
      ↓
Add / Search / Print / Delete / Exit
```

## Tech Stack

- C
- Singly Linked List
- Dynamic Memory Allocation
- File I/O
- Function Pointer
- Visual Studio

## Project Structure

```text
181025-Addressbook/Addressbook/
├─ main.c       # 파일 로드, 메뉴와 event loop
├─ List.c/.h    # 연결 리스트 생성·검색·삭제
├─ Handler.c/.h # 메뉴별 처리
├─ stringtool.* # 문자열 입력 보조
└─ text.txt     # 초기 주소 데이터
```

## Limitations

- 학습 당시 코드로 입력 validation과 오류 처리가 제한적입니다.
- 고정 길이 문자 배열과 C 문자열 함수를 사용합니다.
- 프로그램 종료 시 전체 리스트를 일괄 해제하는 별도 정리 루틴은 확인되지 않습니다.
- 파일은 초기 데이터를 읽는 데 사용하며 변경 내용을 다시 저장하는 persistence 기능은 제한적입니다.

## What I Learned

연결 리스트의 노드 생성, 탐색, 삭제와 포인터 재연결을 직접 구현하면서 동적 자료구조의 기본 동작을 익혔습니다. 또한 파일에서 읽은 데이터를 메모리 구조로 변환하고 함수 포인터로 메뉴 동작을 연결하는 경험을 했습니다.

[← Back to project list](../README.md)
