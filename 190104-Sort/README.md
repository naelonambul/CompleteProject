# Sort Visualization

Bubble Sort의 비교·교환 과정을 MFC와 GDI로 시각화한 Windows 프로그램입니다. 정렬 작업을 worker thread로 분리해 UI 블로킹을 줄이는 방식도 함께 실습했습니다.

## Overview

무작위 배열 값을 막대 높이로 표현하고, Bubble Sort가 인접한 두 값을 비교하고 교환하는 과정을 화면에 단계적으로 표시합니다.

Enter 키를 누르면 worker thread에서 정렬을 수행하며, 비교 중인 위치를 화살표로 표시하고 값이 교환될 때 막대와 숫자 표시를 갱신합니다.

## Key Features

- 무작위 배열 생성
- 배열 값을 막대 그래프로 시각화
- Bubble Sort 비교·교환 과정 표시
- 현재 비교 위치를 화살표로 표시
- Enter 키 기반 정렬 시작 / 재초기화
- worker thread에서 정렬 수행
- `CCriticalSection`을 이용한 일부 공유 상태 보호
- 메모리 DC를 이용한 화면 그리기

## Technical Highlights

### 1. 알고리즘 상태를 GUI로 표현

배열의 index와 값을 화면에 함께 출력하고, 각 값의 크기를 막대 높이로 변환했습니다. 정렬 과정에서 실제 배열 값이 바뀔 때 해당 영역을 다시 그려 알고리즘 진행 상태를 시각적으로 확인할 수 있게 했습니다.

### 2. UI thread와 작업 분리

초기 구현에서 정렬을 UI 이벤트 안에서 수행할 경우 화면이 멈추는 문제가 있어 `AfxBeginThread`로 worker thread를 시작하도록 변경했습니다.

```cpp
if (nChar == VK_RETURN && m_nThread == 0)
{
    AfxBeginThread(MyThread01, NULL);
}
```

worker thread는 Bubble Sort를 진행하면서 View의 배열 값을 변경하고 화면 표시 함수를 호출합니다.

### 3. 더블 버퍼링을 이용한 그리기

`OnPaint`에서 compatible bitmap과 memory DC를 구성하고 최종 화면을 `BitBlt`로 복사하는 방식으로 화면을 그립니다. 반복적으로 갱신되는 그래픽에서 발생할 수 있는 깜빡임을 줄이기 위한 기본적인 GDI 버퍼링 방식을 적용했습니다.

## Flow

```text
Generate Random Array
        ↓
Draw Bars / Index / Values
        ↓
      Enter
        ↓
AfxBeginThread
        ↓
Bubble Sort Compare
        ↓
Swap Array Values
        ↓
Update Bars + Arrow
        ↓
Sorted State
```

## Tech Stack

- C++
- MFC
- Windows GDI
- Worker Thread
- `CCriticalSection`
- Visual Studio

## Project Structure

```text
190104-Sort/
├─ GDI.md            # 당시 작성한 프로젝트 기록
├─ GDI.sln
└─ GDI/
   ├─ GDIView.cpp    # 정렬, thread, GDI rendering
   ├─ GDIView.h
   └─ MainFrm.*
```

## Limitations

- Bubble Sort 하나만 시각화합니다.
- worker thread에서 View drawing 함수를 직접 호출하는 구조는 현대적인 GUI 애플리케이션에서는 UI thread에 메시지를 전달하는 방식으로 개선하는 편이 안전합니다.
- 학습용 프로그램이므로 정렬 속도, 화면 크기와 배열 개수 등이 고정된 값에 의존합니다.

## What I Learned

알고리즘의 내부 상태를 GUI로 표현하는 과정에서 데이터와 화면 표현을 연결하는 방법을 익혔습니다. 또한 시간이 걸리는 작업을 UI 이벤트 루프에서 직접 실행했을 때 발생하는 블로킹 문제를 경험하고, worker thread를 이용해 작업을 분리하는 기본 개념을 적용했습니다.

[← Back to project list](../README.md)
