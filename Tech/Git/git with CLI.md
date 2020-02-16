# 🐙git with CLI

[TOC]

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

  - 디렉토리 생성

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

  - 텍스트 에디터
  - 새 파일 작성
    - nano
  - 파일 열기
    - nano + 파일명
  - nano 사용법
    - 컨트롤 g : 도움말
    - 컨트롤 o : 저장
    - 컨트롤 x : 끄기



- 순서대로 실행 시키기

  성공 여부에 상관없이 실행시키기  :  `;`  사용

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
    - 수정한 파일들 중 버전을 만들려고 하는 파일들
  - repository
    - 만들어진 버전



- 명령어

  `git status`

  - 깃의 상태 확인
  - No commits yet
  - Untracked files : workign tree상의 아직 버전관리 되지 않은 파일

  `git add 파일명`

  - workign tree에 있는 파일의 수정사항을 staging area에 올림
  
  `git add .` : 현재 디렉토리 밑에 있는 모든 파일을 stage에 올림
  
  - `git add 디렉토리명` : 디렉토리에 있는 모든 파일을 stage에 올림
  
  `git commit -m "메세지"`
  
  - staging area에 있는 버전을 repository로 올린다.
  - 커밋 메세지를 "메세지"에 적는다
  
  `git commit -am "메세지"`  : add와 커밋을 동시에 가능 (하지만 untracked 파일은 add가 자동으로 되지 않는다. 적어도 한번은 add가 된적이 있는 파일만 커밋이 된다.)
  
  - -m을 안쓰면, 에디터가 켜지고 거기서 메세지를 적을 수 있다.
  
  `git commit --amend` : 현재 커밋 커밋메세지 수정 
  
  `git log`
  
  - 버전관리의 역사를 보여줌
  - `git log --stat`   : 로그를 자세하게 보여줌
  - `git log -p` : patch 로그를 더 자세하게 변화내용 까지 보여줌
  
  `git diff`
  
  - 차이점을 출력함
  
  `git reset --hard`
  
  - 변화된 내용들을 이전 상태로 되돌림
  
  `git checkout 커밋이름`
  
  - Head를 특정 커밋으로 가리키게 하여, 현재 상태를 특정 시점으로 돌아감
    - master : 마지막 버전
    - Head -> master : 헤드가 마지막 버전을 가리키고 있다.
  - 다시, `git checkout master`라고 하면, 가장 마지막 커밋으로 돌아간다.
  
  `git reset 커밋이름`
  
  - 대상이 되는 커밋 상태로 돌아가고, 그 이후에 있던 커밋은 지우겠는 것
  
  - `git reset --hard` : 커밋과 수정 중이었던 것 까지 다 지우는것
  - `git reset --soft` : 커밋만 지우고, 수정 중이었던 것은 그냥 두는 것
  - 협업할 경우, 공유된 버전은 reset 시키면 안된다. (엉킴)
  
  `git revert 커밋이름`
  
  - R1, R2, R3, R4 순으로 커밋을 했을 때 R3상태의 커밋으로 돌리고 싶다면, R4를 리버트 해야한다. 즉 R4의 커밋을 취소하는 개념이다. 이 때 log에서 R4의 기록은 유지된다.
  - 만약 R4를 헤드가 가리키고 있을 때, R2를 리버트하면 충돌이 일어난다. 리버트는 대상이 되는 커밋만 취소하는 개념이기 때문에 헤드와 리버트 대상 사이에 위치하는 커밋들과 충돌이 발생 할 수 있다. 충돌을 피하기 위해서는 한단계씩 거꾸로 리버트 해야한다. (R4 -> R3 ->R2)



- 참고

  `.gitignore` : 버전관리에서 제외시킬 수 있다.

  `diff tool`  : 차이점 비교를 잘 활용하면 유용하다 (구글 검색 

  `branch` : 하나의 저장소에서 다양한 작업을 할 수 있다. 여러가지 버전을 동시에 작업 가능

  `tag` : 태그를 활용해서 특정 커밋에 이름을 붙일 수 있다.

  

## 4. 백업

- PUSH : 원격 저장소에 로컬 저장소를 저장 
- PULL : 원경 저장소를 로컬 저장소에 저장



- Git Hosting 사이트 : 원격 저장소를 제공해줌 (ex. 깃허브)
  - 원격저장소 생성



- HTTP방식과 SSH방식의 원격 저장소가 있는데 HTTP 방식의 원격 저장소를 사용할 예정



- **로컬 저장소와 원격 저장소 연결**

  `git remote add [별명] http://githube.com/깃허브이름/레포이름.git` 

  - 원격 저장소를 여러개 연결 할 수 있기 때문에, 원격 저장소에 별명을 붙여준다. 기본적인 별명은 관습적으로 origin을 많이 사용한다.

  `gir remote` : 원격 저장소를 보여달라고 요청하는 명령어로 원격 저장소의 별명을 출력한다.

  `gir remote -v` : 원격 저장소의 별명과 주소까지 출력한다.



- **원격 저장소에 저장**

  `git push` : 연결되어 있는 원격 저장소에 저장

  `git push --set-upstream origin master` : 지역 저장소가 여러개의 원격 저장소와 연결 될 수 있는데, 그중 기본 원격 저장소를 세팅해 주는 것 (origin : 별명)`

  - 깃헙의 이메일과 비밀번호 입력



- **원격저장소 복제**

  `git clone 깃허브주소 [디렉토리 경로]`" : 원격저장소를 원하는 경로에 복제함. 자동으로 깃허브와 연동됨 만약 경로를 지정하지 않으면 현재 디렉토리에 복제 됨



- **원격저장소에 저장된 최신 내용 로컬 저장소에 저장**

  `'git pull'` :  원격 저장소에 저장 된 최신 상태를 로컬 저장소에 저장



- 작업 시 기본적 Flow

  **PULL - 작업 - COMMIT - PUSH**



## 5. 브랜치&충돌

- **branch**

  `git branch` : 현재 브랜치 목록 출력

  - 기본적 브랜치는 master 이고, 별표가 있는 브랜치가 현재 브랜치(헤드가 가리키고 있는)이다.

  `git branch 브랜치명` : 새로운 브랜치 생성 (현재 헤드가 가리키고 있는 버전 상태와 동일한 내용의 신규 브랜치가 생성됨)

  만약, 브랜치가 생성된 상태에서 새로운 버전을 커밋을 한다면, 현재 헤드가 가리키고 있는 브랜치만 새로운 버전으로 바뀜.

  `git checkout 브랜치명` : 헤드를 원하는 브랜치로 바꿀 수 있다. 또한, 저장소의 파일이 해당 브랜치의 버전으로 바뀌게 된다.  이때 작업을 하고 커밋하면 해당 브랜치에 작업이 저장된다.

  `git checkout 버전이름` : 헤드를 브랜치가 아닌 버전을 직접 가리키게 할 수 있다 . 그러면, 저장소는 해당 버전의 상태로 바뀐다. (헤드가 브랜치를 가리키고 있지 않을때 detached 상태라고 한다.)

  

  cf) reset과 checkout의 차이점

  reset은 브랜치의 버전을 바꾸는 것이고, checkout은 헤드의 대상 브랜치 또는 버전을 바꾸는 것이다.

  - google 브랜치가 선택된 상황에서 각 명령어를 실행할 때 의 결과

    checkout master : 헤드를 마스터로 바꿈

    reset master : google 브랜치를 master(2번커밋 상태)로 바꿈

    ![img](https://i.imgur.com/RCiBC3P.png)

  cf) 브랜치 보는 법

  `git log --all --graph --online` : 모든 브랜치를, 시각적으로, 한줄씩 출력

  

- **merge**

  두 개의 브랜치를 합쳐서 새로운 버전을 만드는 작업

  ![img](https://i.imgur.com/SqimTZT.png)

  cf) **base** : 병합하려는 두 브랜치의 공통 조상

  

**★ 브랜치 1에 브랜치 2 합치기 ★**

- **서로 다른 파일 병합**

  1.  `git checkout master 브랜치1` : 브랜치1 상태로 바꿔야 함
  2. `git merge 브랜치2` : 브랜치2를 머지하면서 생기는 머지커밋 생성

  cf) 병합을 취소하고 싶다면, 브랜치1 상태에서 `git reset --hard [병합 전 브랜치1의 커밋]` 하면 병합전 상태로 돌아간다.



- **같은 파일, 다른 부분 병합** (다른부분을 수정했다면, 문제 없이 병합된다.!!!  갓깃!!)

  1.  `git checkout master 브랜치1` : 브랜치1 상태로 바꿔야 함
  2. `git merge 브랜치2` : 브랜치2를 머지하면서 생기는 머지커밋 생성

  cf) 병합을 취소하고 싶다면, 브랜치1 상태에서 `git reset --hard [병합 전 브랜치1의 커밋]` 하면 병합전 상태로 돌아간다.



- **conflict (충돌) : 같은 파일, 같은 부분 병합할 때 발생**

  1.  `git checkout master 브랜치1` : 브랜치1 상태로 바꿔야 함

  2. `git merge 브랜치2` : 브랜치2를 머지하면서 생기는 머지커밋 생성

     **!! 충돌이 발생함**, 충돌이 발생한 파일을 알려준다.

  3. 해당 파일을 보면 충돌이 발생한 부분이 있는데, 해당 부분을 수정한다.

  4. `git add 파일명`

  5. `git commit`

  cf) 병합을 취소하고 싶다면, 브랜치1 상태에서 `git reset --hard [병합 전 브랜치1의 커밋]` 하면 병합전 상태로 돌아간다.



- **3 way merge**

  | branch1 | base | branch2 | 2way merge | 3way merge |
  | ------- | ---- | ------- | ---------- | ---------- |
  | A       | A    | A       | A          | A          |
  | H       | B    | B       | ?          | H          |
  | C       | C    | T       | ?          | T          |
  | H       | D    | T       | ?          | ?          |

  ? : 충돌 의미

  base : 공통조상

  3way merge : base를 기준으로 바뀐 부분이 있는 것을 채택함, 두 브랜치 모두 바뀌었다면 충돌

  

- **외부도구를 이용한 병합**

  p4Merge 구글에서 찾아 설치 후, git config를 해준다(운영체제 환경에 따라 방법 다름)

  `git mergetool`

  수정을 완료하면, add까지 자동으로 된다.

  `git status` :  수정된 파일은 자동 add됐지만, ~~~.orig (충돌 상태 그대로의 파일)은 add되지 않는다.

  `rm ~~~.orig`

  `git commit`

   

- **git workflow** : 구글에서 모범 사례를 찾아 볼 수 있음



- **cherry-pick** : 병합과 관련된 기능

  ![img](https://i.imgur.com/7Z4ZAL5.png)

  - a3와 b2를 머지하는 것을 체리 픽이라 한다.



- **rebase** : merge와 비슷하지만 조금더 타임라인이 깔끔하다.

  ![image-20191209170816200](C:\Users\JUNHYEONG\AppData\Roaming\Typora\typora-user-images\image-20191209170816200.png)

  - other 브랜치는 그대로 두고, master 브랜치에 b2,b3내용을 병합하는 방식