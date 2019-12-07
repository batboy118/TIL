# 🐙git with CLI



## 1. git의 세 가지 목적

1. Version 관리
   1. 파일의 버전 관리를 commit을 통해 할 수 있다.
2. Backup
   1. 원격 저장소(git hub 등)에 파일과 버전관리 내역을 저장 할 수있다. 
3. Collaborate
   1. 원격 저장소에 저장된 내용을 다른 사람이 자신의 로컬 저장소에 저장시켜서 작업
   2. 작업이 완료되면, 다시 원격 저장소에 저장
   3. 반복



## 2. POSIX CLI

**portable operating system interface**

- posix 표준  :  유닉스, 리눅스, 맥

  ​	cf) 윈도우 : cmd, powershell



- 사전 준비

  POSIX 호환 운영체제 (유닉스, 리눅스, 맥)

  - 터미널만 키면 된다.

  그외(윈도우나 안드로이드, IOS)

  - 별도의 에뮬레이터을 설치해야 하거나 별도의 POSIX 호환 서버(Secure Shell)를 운영해야 한다.
    - 윈도우에서는 git 수업이므로 그냥 git bash를 이용하는 걸로...
    - 안드로이드 Termux 어플



- 수업의 목적

  File과 Directory 다루기

  - CRUD 

  | CRUD   | File            | Directory |
  | ------ | --------------- | --------- |
  | create | editor          | mkdir     |
  | read   | editor, cat, ls | ls        |
  | upadte | editor, mv      | mv        |
  | delete | rm              | rm        |

    

- 기본 명령어

  `pwd`

  - 현재 위치 출력
  - / : root directory
  - 처음 터미널을 켜게 될 때의 위치를 Home Directory라고 함

  `cd` 

  - change directory 
  - cd /   :  root 디렉토리로 이동

  - cd ~  :  home 디렉토리로 이동
  - cd ./디렉토리명 : 현재 디렉토리를 기준으로
  - cd /디렉토리명 : root 디렉토리를 기준으로
  - cd ~/디렉토리명 : home 디렉토리를 기준으로
  - cd .. : 부모 디렉토리로 이동
  - cd ../디렉토리명 : 부모 디렉토리를 기준으로 이동
  - **상대경로와 절대경로**
    - 상대경로 이동 : 현재 경로를 기준으로 이동
      - cd ./디렉토리명 
      - cd 디렉토리명 (./ 생략 가능 )
      - cd ..
    - 절대경로 이동 : root 디렉토리를 기준으로 이동
      - cd /디렉토리명/디렉토리명

  `ls`

  - 현재 디렉토리에 있는 파일과 디렉토리를 보여줌
  - ls -l : 파일과 디렉토리의 정보를 더 자세하게 보여줌
  - ls -a : 숨김 파일( 파일명이 .으로 시작하는 파일) 까지 보여줌
  - ls -l -a : 동시에 사용 가능 (ls -al 또는 -la 도 가능)
  - ls -R : 하위 디렉토리까지 다 보여줌

  `man`

  - 메뉴얼
  - man + 명령어 : 명령어의 사용법이 나옴

  `touch`

  - 파일 만들기
  - touch + 파일명

  `mkdir`

  - 디렉토리 생성

  - mkdir + 디렉토리 명

  `mv`

  - 디렉토리 또는 파일을 이동시킴
    - mv 이동하는 대상이름 + 디렉토리위치/대상이름
  - 디렉토리 또는 파일명을 변경함
    - mv 이전이름 + 바꿀이름

  `rm`

  - 기본적으로 파일을 삭제
  - rm + 파일명
  - 디렉토리를 지우고 싶으면 -r(재귀)을 붙여야 함
    - rm -r + 디렉토리명

  `cat`

  - 파일 안의 내요을 화면에 출력
  - cat + 파일명

  `nano`

  - 텍스트 에디터
  - 새 파일 작성
    - nano
  - 파일 열기
    - nano + 파일명
  - nano 사용법
    - 컨트롤 g : 도움말
    - 컨트롤 o : 저장
    - 컨트롤 x : 끄기



- 순서대로 실행 시키기

  성공 여부에 상관없이 실행시키기  :  `;`  사용

  `mkdir dummy; cd dummy; touch hello.txt; cd ..; ls -R`

  

  순차적으로 앞의 명령어가 성공해야 다음 명력어 실행 :  `&& `사용

  `mkdir dummy && cd dummy && touch hello.txt && cd .. && ls -R`

  

- 패키지 매니저
  - apt-get  : 리눅스
  - yum  : 리눅스
  - homebrew  : 맥
  - chocolatey  : 윈도우



- Maintain
  - storage
  - memory
  - processor



## 3. 버전관리

- git 설치
  - 터미널 환경에서 git을 쳤을 때 뭔가 나오면 git이 깔린 것이다.
  - 없으면 git을 인터넷에서 설치한다.



- 현재 폴더에  버전관리 만들기

  - `git init .`
  - `ls -al`

  

- 기본적인 버전관리 파일 흐름

  `working tree 👉 staging area 👉 repository`

  - working tree
    - 수정한 파일들
  - staging area
    - 수정한 파일들 중 버전을 만들려고 하는 파일들
  - repository
    - 만들어진 버전



- 명령어

  `git status`

  - 깃의 상태 확인
  - No commits yet
  - Untracked files : workign tree상의 아직 버전관리 되지 않은 파일

  `git add 파일명`

  - workign tree에 있는 파일의 수정사항을 staging area에 올림

  `git commit -m "메세지"`

  - staging area에 있는 버전을 repository로 올린다.
  - 커밋 메세지를 "메세지"에 적는다

  `git log`

  - 버전관리의 역사를 보여줌