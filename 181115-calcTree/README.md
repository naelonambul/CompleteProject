# Expression Tree Calculator

문자열로 입력된 사칙연산 수식을 검증하고, 연산자와 피연산자를 분리해 Binary Tree로 구성한 뒤 계산 결과를 출력하는 C 콘솔 프로그램입니다.

## Overview

단순히 문자열을 순서대로 계산하지 않고, 입력 검증 → 토큰 분류 → 트리 생성 → 순회 및 계산의 단계로 나눠 수식 처리 과정을 직접 구현했습니다.

지원 연산자는 `+`, `-`, `*`, `/`이며 괄호를 포함한 수식을 처리합니다. 단항 연산은 지원하지 않습니다.

## Key Features

- 허용 문자와 수식 구조 검증
- 숫자, 연산자, 괄호 토큰 분류
- 양방향 연결 구조를 이용한 파싱 중간 표현
- Binary Tree 노드 생성 및 연결
- 트리 출력과 연산 결과 계산
- 동적으로 할당한 parser / stack / tree 메모리 해제

## Technical Highlights

### 1. 입력 검증과 파싱 단계 분리

`ASCII_Validation`, `my_Validation`, `symbolcount_Validation` 등의 함수를 통해 허용되지 않은 문자와 잘못된 기호 배치를 먼저 검사합니다.

파싱 결과는 `MYDUAL` 구조체에 저장하며, 각 노드는 데이터 종류와 문자열 값, 이전/다음 포인터를 가집니다.

```c
typedef struct myDual {
    int dataType;
    char cNum[BUFFER];

    struct myDual *pPrev;
    struct myDual *pNext;
} MYDUAL;
```

### 2. 수식을 Binary Tree로 표현

파싱된 토큰을 `MYTREE` 구조로 변환합니다. 각 노드는 연산자 또는 숫자를 저장하고 좌우 자식 노드를 연결합니다.

```c
typedef struct myTree {
    int dataType;
    char cNum[BUFFER];

    struct myTree *p_Left;
    struct myTree *p_Right;
} MYTREE;
```

수식을 트리로 표현하면서 연산 우선순위와 괄호가 실제 자료구조에서 어떻게 표현되는지 확인하는 데 초점을 둔 프로젝트입니다.

### 3. 자료구조를 역할별로 분리

프로젝트를 parser, binary tree, stack 모듈로 나눴습니다.

```text
Input String
    ↓
Validation / Parser
    ↓
Token Structure
    ↓
Binary Expression Tree
    ↓
Stack / Tree Processing
    ↓
Result
```

## Tech Stack

- C
- Binary Tree
- Stack
- Doubly Linked Structure
- Dynamic Memory Allocation
- Visual Studio

## Project Structure

```text
181115-calcTree/Postorder/
├─ main.c            # 입력과 전체 처리 흐름
├─ myParser.c/.h     # 문자열 검증 및 파싱
├─ myBinaryTree.c/.h # 트리 생성, 연결, 출력, 해제
└─ stack.c/.h        # 계산에 사용하는 스택 구현
```

## Limitations

- 단항 연산은 지원하지 않습니다.
- 학습 목적의 수식 파서로, 표준 parser generator나 AST 라이브러리를 사용하지 않고 직접 구현했습니다.
- 입력 길이와 오류 처리 방식은 현재 제품 수준의 parser보다 단순합니다.

## What I Learned

문자열 처리, 연결 자료구조, 스택과 트리를 따로 학습하는 대신 하나의 수식 계산 문제 안에서 연결했습니다. 특히 연산 우선순위를 자료구조로 표현하고, 파싱 단계와 실행 단계를 분리하는 기본 개념을 직접 구현해 본 프로젝트입니다.

[← Back to project list](../README.md)
