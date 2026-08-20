# Drag & Drop File Hash

Windows Explorer에서 파일을 MFC 프로그램으로 Drag & Drop하면 파일의 절대 경로와 SHA-1 해시를 계산해 표시하는 프로젝트입니다.

## Overview

`WM_DROPFILES` 메시지를 처리해 외부에서 드롭된 파일 목록을 가져오고, 각 파일을 Windows API로 열어 내용을 읽으면서 SHA-1 해시를 계산합니다.

파일 경로와 계산된 해시 값은 ListBox에 순서대로 표시됩니다.

## Key Features

- Explorer 파일 Drag & Drop 수신
- 여러 파일의 절대 경로 읽기
- 파일을 순차적으로 읽어 SHA-1 계산
- SHA-1 결과를 hexadecimal 문자열로 변환
- 경로와 hash를 ListBox에 출력

## Technical Highlights

### 1. Windows Drag & Drop 메시지 처리

Dialog 초기화 시 `DragAcceptFiles(TRUE)`를 호출하고 `WM_DROPFILES` 메시지를 등록했습니다.

`OnDropFiles`에서는 `DragQueryFile`로 드롭된 파일 수와 각 파일의 경로를 가져옵니다.

```cpp
int nFiles = ::DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);

for (int i = 0; i < nFiles; i++)
{
    nBuffer = ::DragQueryFile(hDropInfo, i, NULL, 0);
    DragQueryFile(hDropInfo, i,
                  sFile.GetBuffer(nBuffer + 1),
                  nBuffer + 1);
}
```

### 2. 파일 내용을 읽어 SHA-1 계산

파일을 `CreateFile`로 열고 `ReadFile`을 반복 호출하여 buffer 단위로 데이터를 읽습니다. 읽은 데이터는 Windows CryptoAPI의 `CryptHashData`에 전달합니다.

```text
Dropped File
    ↓
CreateFile
    ↓
ReadFile (buffer)
    ↓
CryptHashData
    ↓
CryptGetHashParam
    ↓
Hex String
```

### 3. Windows CryptoAPI 사용

`CryptAcquireContext`, `CryptCreateHash`, `CryptHashData`, `CryptGetHashParam`을 이용해 `CALG_SHA1` 해시를 계산했습니다. 작업이 끝나면 hash, provider, file handle을 순서대로 해제합니다.

## Tech Stack

- C++
- MFC
- Windows API
- Windows CryptoAPI
- SHA-1
- Visual Studio

## Project Structure

```text
190220-DragAndDropTest/
├─ DragAndDropTest.md
├─ DragAndDropTest.sln
└─ DragAndDropTest/
   ├─ FormDrag.cpp    # Drop 처리 및 SHA-1 계산
   ├─ FormDrag.h
   └─ ...             # MFC application files
```

## Limitations

- SHA-1은 현재 충돌 저항성이 필요한 보안 용도로 권장되는 해시가 아닙니다. 이 프로젝트에서는 Windows CryptoAPI와 파일 hashing 흐름을 학습하기 위한 알고리즘으로 사용했습니다.
- 파일 오류에 대한 정보는 내부 status code로 처리하며 사용자에게 상세한 오류 UI를 제공하지 않습니다.

## What I Learned

Windows 메시지로 외부 파일 입력을 받고, 파일 handle과 cryptographic provider 같은 OS resource를 직접 획득하고 해제하는 과정을 경험했습니다. GUI 이벤트, 파일 I/O와 시스템 API를 하나의 작은 프로그램 안에서 연결해 본 프로젝트입니다.

[← Back to project list](../README.md)
