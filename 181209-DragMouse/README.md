# Mouse Drag Interaction

MFC에서 마우스 이동과 드래그 이벤트, 메뉴 상태 변경을 연습하기 위해 작성한 GUI 프로젝트의 기록입니다.

> **Archive note**  
> 현재 저장소에는 `DragSomething.sln`과 기존 설명 문서만 남아 있고, solution이 참조하는 실제 `DragSomething/` 소스 디렉터리는 포함되어 있지 않습니다. 아래 내용은 보존된 프로젝트 문서를 기준으로 정리했습니다.

## Overview

View 영역 안에서 마우스 좌표를 표시하고, 사각형을 드래그해 위치를 변경하며 메뉴를 통해 크기와 색상 상태를 변경하는 프로그램으로 기록되어 있습니다.

핵심 목적은 `WM_MOUSEMOVE`를 포함한 Windows mouse message와 MFC event handler의 동작을 이해하는 것이었습니다.

## Documented Features

- 현재 마우스 좌표 표시
- 사각형 Drag 이동
- 사각형 크기 확대 / 축소
- 색상 변경
- 메뉴 enable / disable 상태 변경
- 위치, 크기, 색상과 좌표 표시 상태 Reset

## Technical Focus

기존 문서에 따르면 마우스가 움직일 때 전달되는 `WM_MOUSEMOVE`를 event handler에 연결하고, 매 이동 시점의 좌표와 객체 상태를 View에 반영하는 방식으로 작성했습니다.

또한 메뉴 선택 결과에 따라 도형의 크기와 색상 같은 상태를 변경하고, 가능한 동작에 맞춰 메뉴 활성화 상태도 함께 조정했습니다.

## Tech Stack

- C++
- MFC
- Windows Messages
- Visual Studio 2015 solution format

## Repository Status

```text
181209-DragMouse/
├─ README.md
├─ DragSomething.md    # 당시 작성한 프로젝트 설명
├─ DragSomething.html
└─ DragSomething.sln   # source project path를 참조하지만 실제 소스는 누락
```

원본 source가 없는 상태이므로 이 프로젝트는 구현 세부 사항을 증명할 수 있는 대표 포트폴리오 항목보다는, 초기 Windows GUI 학습 기록을 보존하는 archive 성격으로 분류했습니다.

[← Back to project list](../README.md)
