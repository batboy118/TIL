# 1주차-Colab 사용해보기



## 1-1. 강의를 시작하기 전

### 강의 소개 : 선수과목

- 파이썬 프로그래밍

- 알고리즘, 자료구조

- 수학(이산수학, 선형대수)

- 언어학(이론언어학, 전산언어학)

- 인공지능 이론



### 딥러닝 분야의 세 가지 난제

1. 이론적 바탕 없이 실험에 의존한다.
2. 동작 원리에 대해 이해하기 어렵다.
3. 교육과의 연계방안을 찾기 어렵다.



### 과학이란?

- 계량주의 연구 방법론
  - 동일한 Source를 Input하여 동일한 모델에 적용시키면 동일한 결과가 나와는 것![img](https://i.imgur.com/5WRP928.png)

- 딥러닝이 과학이 아니라고 말하는 이유?
  - 계량주의가 적용되지 않는다.
  - state-of-the-art
    - 몇 개월 만에 세계적인 수준의 결과물을 만들 수 있다.
    - 언어학을 전혀 몰라도 언어처리를 구현할 수 있다.



### 바로 할 수 있는가?

- **GPU**

  - 딥러닝에 GPU는 필수적 요소

  - 딥러닝의 연산을 담당함

  - 병렬처리 : 한번에 여러가지 작업을 수행하는 것

    - 소켓 : 통짜 유닛의 갯수
    - 코어 : 프로세서 내부에 있는 코어의 갯수
    - 논리 프로세서 : 논리적으로 나누어진 프로세서의 수

  - CPU 대신 GPU를 쓰는 이유?

    - 단순작업을 병렬로 처리하는데 GPU가 가격적으로나 물리적으로나 효율적이다.

    |                        | CPU                    | GPU                                   |
    | ---------------------- | ---------------------- | ------------------------------------- |
    | PC에 적용 가능한 수량  | 제한적                 | 제한 없음                             |
    | 단순작업에 대한 적절성 | 단순작업 하기엔 고성능 | 단순작업을 병렬적으로 처리하기에 좋음 |

  - 엔비디아 GPU를 100%사용하기 위해서는 ubuntu 환경에서 작업해야 한다.
  - GPU가 주된 연산을 하긴 하지만, CPU와 메모리, Power, Cooler도 중요하다.
  - 이 모든 것을  구성해서 학습을 시키기는 어렵지만 colab을 사용해서 24시간까지 학습 시킬 수 있다. 그 이상 학습이 필요한경우 개인 환경을 구성해야 합니다.



### 데이터가 있는가?

- coca, coha, glowbe
- 딥러닝에서 데이터가 가장 중요하다.



### 전처리가 되어 있는가?

- tokenizer, stemmer, tagger, parser



### 프로그래밍을 할 수 있는가?

- tensorflow, keras, pytorch



### 처리 모델이 있는가?

- CNN, RNN, LSTM, BiLSTM, Transformer…
- 계속해서 새로운 모델이 나오기 때문에, 프로젝트에 적합한 모델을 그때 그때 학습해서 쓰는 것이 좋다.



### 분석 모델이 있는가?

- error analysis, precision, recall, …



### 연구주제가 있는가?

- lexicon, syntax, semantics, pragmatics



### 최신 동향

- 매일 새로운 논문들이  쏟아져 나오는 분야

- http://bit.ly/2HmcXRx



### 딥러닝 작업 환경 만들기 (코랩을 이용하면 필요 없음)

- 하드웨어

  - GPU(s)
  - Motherboard
  - CPU
  - RAM
  - Power / Cooler
  - NVIDIA drivers
  - CUDA
  - CUDNN

- 소프트웨어

  - 아나콘다 설치하기

    - 운영체제에 맞는 버전 사용
    - Python 3.7 이상
    - Anaconda Prompt

  - 환경 생성

    ```
    $ conda create –n mydeeplearning python=3.7 numpy scipy matplotlib spyder pandas seaborn scikit-learn h5py 
    
    $ activate mydeeplearning
    
    $ pip install tensorflow-gpu
    
    $ pip install keras
    ```

  - PyTorch

    https://pytorch.org/get-started/locally/



### 머신러닝

- 데이터에 기반한 모델링 기법
- 데이터의 영향을 매우 크게 받는다.
- 우수한 데이터가 아니면 결과도 기대하기 어렵다.

<img src="https://i.imgur.com/Hwxf1he.png" alt="img" style="zoom:50%;" />

- **일반화** : 학습데이터와 입력데이터를 같은 맥락으로 맞추는 것.

  ex) 시험범위는 삼각함수인데, 공부를 지수로그 파트를 한 경우 결과가 좋을 수가 없다.

- **과적합** (overfitting) : 학습을 너무 많이해서 손실이 발생하는 상황

  - 아래 그림에서 선으로 잘 구분되지않는 세모와 원을 오류 또는 잡음이라 한다.

  

  <img src="https://i.imgur.com/RSKCzG1.png" alt="img" style="zoom: 50%;" />

  - 아래의 경우가 오버피팅 된 경우인데, 너무 기준이 빡빡해지기 때문에 변수에 대응이 잘 안된다.

  <img src="https://i.imgur.com/Dbk1fdA.png" alt="img" style="zoom:50%;" />

  - 예를 들어 오버피팅의 경우 아래 네모가 생겼을 경우 어떻게 처리할지 판단하기 어려워진다.

    <img src="https://i.imgur.com/r07ofdo.png" alt="img" style="zoom:50%;" />

  

- 과적합을 피하는 방법

  - 정칙화(regularization)

    •모델의 형태를 최대한 단순하게 만들려는 수치해석적인 기법

    •오컴의 면도날

  - 검증(validation)

    학습 데이터의 일부를 따로 떼어 내서
     학습에는 사용하지 않고 
     모델의 성능 검증용으로 사용하는 기법

    <img src="C:\Users\JUNHYEONG\AppData\Roaming\Typora\typora-user-images\image-20200110142616532.png" alt="image-20200110142616532" style="zoom:50%;" />

    

    <교차 검증>

    <img src="C:\Users\JUNHYEONG\AppData\Roaming\Typora\typora-user-images\image-20200110142242745.png" alt="image-20200110142242745" style="zoom:50%;" />

- 기계 학습의 종류

  - 지도학습(supervised learning): {입력, 정답}  // 비지도학습에 의해 성능은 좋지만, 데이터가 많지 않음

    - **분류(classification)**: 판별
      - binary : 두개의 경우만 존재하는 경우 (남자/여자, 좋아요/싫어요)
      - n-ary : 여러가지 경우가 존재하는 경우 (돼지, 개, 고양이 등)

    - **회귀(regression)** : 추세

  - 비지도학습(unsupervised learning): {입력}   // 비지도학습에 적합한 데이터가 많지만 정확도는 떨어짐

    - **분류**

    - **군집화(clustering)**

  - 강화학습(reinforcement learning): {입력, 출력, 점수}



## 1-2. Colab 실습 시작

학교 계정이 구글인 경우 학교 계정으로 사용하는 것이 좋다.

### 환경 세팅

- 디폴트 환경셋팅은 CPU로 되어있다. 이것을 GPU로 바꿔야 한다.
  - Runtime -  change runtime type
  - 하드웨어 가속기 : None을 GPU로 바꿈
    - TPU : 텐서플로우용 GPU 시스템 (엄청 큰 데이터를 다룰때 좋다.)
    - 그렇게 크지 않은 데이터는 GPU가 더 낫다.
    - None은 CPU 사용

ㄴ

### 코딩 시작

- File - new python3 file
- 코드를 쓰고 실행버튼(화살표)를 누르면 실행된다.
- +Code를 쓰면 새로운 코드작성 가능

- Shell Command 사용법

  - ! 로 시작

    ![img](https://i.imgur.com/k6ByILe.png)

- 이전에 컴파일 했던 코드를 다시컴파일 하고 싶으면 번호에 마우스를 올려놓으면 실행 버튼이 다시 생긴다.
- 주피터 노트 : 코드와 텍스트를 저장한 형식의 파일
- 파일은 두개를 가져야한다.
  - 입력 파일
  - 학습 파일



### word2vec 실습

- word2vec.jpynb 다운
- thelittlepince 다운
- 코랩에서 노트열기로 word2vec.jpynb 열기
- 첫 코드 실행
- 좌측의 화살표를 눌러서 File thelittleprice 파일을 추가한다. 
- 다음 코드를 차례대로 실행(실행 순서가 번호로 생성된다.)
- 코드 구성
  - 초반 : 초기 설정 코드 및 옵션 설정 코드
  - 신경망 모델부터 딥러닝 구현부라고 생각하면 된다.
  - 마지막 코드 결과 출력 코드



## 1-3. 한국어 임베딩

- 언어란?
  - 형태와 의미를 가지고 있는 것
- 기계가 언어를 어떻게 이해할 수 있는가?
  - 먼저, Yes/No 질문
  - 다음, WH~ 질문

### 임베딩

- 임베딩이란?

  - 컴퓨터는 어디까지나 빠르고 효율적인 계산기일 뿐이다. 
  - 따라서 **인간이 사용하는 언어** (=자연언어) 를 그대로 이해하지 못한다. 
  - 컴퓨터는 자연언어를 숫자로 변형하여 계산한다. 따라서 기계의 자연언어 이해와 생성은 **연산과 처리**의 영역이다.
  - 정리 : **자연어 처리** 분야에서 임베딩이란, 사람이 쓰는 자연어를 기계가 이해할 수 있도록 숫자의 나열인 ‘벡터’로 바꾸는 결과와 과정을 의미한다.

  - **즉, 각 단어를 수치화된 정보로 맵핑하는 것을 임베딩이라고 한다.**
  - 벡터 : 숫자의 나열, 숫자의 그룹 (1차원으로 구성된 행렬)
  - 단어나 문장 각각을 벡터로 변환해 벡터공간 (vector space) 으로 ‘끼워 넣는다(embed)’는 의미에서 임베딩이라는 이름이 붙여졌다.

- 임베딩의 역할

  1. 단어/문장 관련도 

     - 기본 이론 : 벡터를 이용하여 2차원 공간에 좌표를 찍을 수 있다. 2차원(평면 공간) 안에 단어들의 위치를 찍을 수만 있다면, 단어들의 관련성, 어떤 단어들이 가깝고 먼지 알 수 있다.

       예) 아래의 경우, desk와 car보다 desk와 chair가 더 가깝다.

       <img src="https://i.imgur.com/5mxfXMt.png" alt="img" style="zoom: 80%;" />

  2. 의미/문법 정보 함축 

     - 기본 이론 : 기하학적 표상! 수치로 표상된 의미 (의미의 수치화)

       ![img](https://i.imgur.com/TazQR9S.png)

  3. 전이학습

     - 전이 학습 (transfer learning) : (이미 만들어진) 임베딩을 다른 딥러닝 모델의 입력값으로 쓰는 기법
     - 설명 :
       전이학습은 사람과 비슷한 학습법이다. 사람이 무언가를 배울 때, 평생 쌓아 온 지식을 바탕으로 새로운 사실을 빠르게 이해한 다.
       전이학습 또한 대규모 코퍼스로 미리 만들어놓은 임베딩을 입력값으로 쓴다. 이를 통해 문서 분류라는 태스크를 빠르게 잘 할 수 있게 된다.

- 임베딩의 종류와 역사

  - 변화의 흐름 : 

  1. 통계 기반 → 뉴럴 네트워크 기반 
  2. 단어 수준 → 문장 수준 
  3. 룰 (rule) → 엔드투엔드(end-to-end) → 프리트레인 (pre-trained), 파인튜닝 (fine tuning)

- 개발환경
  - 책에서는 docker를 사용하는 환경(하지만, 우리는 colab을 사용)
  - 참고 : https://ratsgo.github.io/embedding/environment.html

- 이책의 데이터와 용어
  - 데이터 : 네이버 영화평가 코퍼스, 한국어 위키피디아 
    - 기본 데이터 단위 : 문장 
    - 책에서 다루는 가장 작은 단위 : 토큰 (token) = 형태소
  - 용어: 
    - 문장 : 토큰의 집합 
    - 문서 : 문장의 집합 
    - 코퍼스 : 문서의 집합
  - 토크나이즈 (tokenize) : 문장을 토큰으로 분석하는 과정을 의미.
  - 어휘 집합 : 코퍼스에 있는 모든 문서를 문장으로 나누고, 토크나이즈 실시한 후 중복을 제거한 토큰들의 집합이다

- 요약
  - 임베딩이란 자연어를 기계가 이해할 수 있는 숫자의 나열인 벡터로 바꾼 결과 혹은 그 일련의 과정 전체를 가리킨다.
  - 임베딩을 사용하면 단어/ 문장 간 관련도를 계산할 수 있다. 
  - 임베딩에는 의미적/ 문법적 정보가 함축되어있다. 
  - 임베딩은 다른 딥러닝 모델의 입력값으로 쓰일 수 있다. (전이 학습)

### 벡터가 어떻게 의미를 가지게 되는가?

- 자연어 계산과 이해

  - 임베딩이 어떻게 자연어의 의미를 함축할 수 있을까? 

    - 이 비결은 자연어의 통계적 패턴 (statistical pattern) 을 통째로 임베딩에 넣는 것이다.

    - 왜냐하면 자연어의 의미는 해당 화자들이 실제 사용하는 일상 언어에서 드러나기 때문이다.

    - 임베딩을 만들 때 쓰는 통계 정보는 크게 세가지가 있다.

      `빈도`, `순서`, `분포`

      <img src="https://i.imgur.com/hIFbGmc.png" alt="img" style="zoom: 80%;" />



- 어떤 단어가 많이 쓰였는가?

  - Bag : 중복 원소를 허용한 집합 (multiset), 즉, 원소들의 순서를 고려하지 않음

  - Bag of words 기법 : 단어의 등장 **순서와 관계 없이** 문서 내 단어의 **등장 빈도**를 임베딩으로 쓰는 기법

    <img src="https://i.imgur.com/waQhmNM.png" alt="img" style="zoom: 67%;" />

  - 장점 : 계산이 쉽다.

  - 단점 : 단어의 빈도수가 꼭 그 문서의 주제를 나타내지는 않는다.
    
- 예시 : 을/를, 이/가 등의 조사는 대부분의 문서에 많이 등장한다.
    
  - 따라서 중요한 데이터란? 
  
  - 다른 문서에는 안 나오는데, 해당 문서에 등장하는 데이터.
  
  - TF-IDF (Term FrequencyInverse Document Frequency)

    - 단점을 보완하는 기법

    - 다른 문서에는 안나오지만 내 문서에만 많이 나오는 경우 주제를 파악 가능

      ![img](https://i.imgur.com/r4ucsDY.png)

    - TF (Term Frequency) = 특정 단어가 특정 문서에서 얼마나 많이 쓰였는가

    - N = 전체 문서 수
  
    - DF (Document Frequency) = 특정 단어가 나타난 문서의 수
    
    - 예시, 운수좋은 날
    
      - ‘담배’ 라는 특정 단어.
      - TF = ‘운수 좋은 날’ 에 등장한 ‘담배'의 수 
      - DF = '담배'가 등장한 문서의 수
      - TF 가 클수록, DF 가 작을수록, 결과값 TF-IDF 는 커진다!
      - 단어 사용 빈도는 저자가 상정한 주제와 관련을 맺고 있을 것이라는 가정에 기초함.
    
    - log를 쓰는 경우, 곱셈 연산을 덧셈연산으로 처리하기 위해
      - 곱셈을 계속하다보면, 엄청 큰 숫자가 될 수도 있다.
      - 곱셈보다는 덧셈이 컴퓨터 연산이 빠르다.
      - 계산상의 편의를 위해 쓰는 것!



- 단어가 어떤 순서로 쓰였는가?

  - 언어모델 (language model) 이란 단어 **시퀀스 (순서)** 에 확률을 부여 하는 모델이다. 

    - 앞선 백오브워즈 가정과는 달리, 언어 모델은 시퀀스 정보를 명시적으로 학습한다.

  - 언어 모델에는 두가지 분류가 있다.

    1. **통계 기반 언어 모델** (통계적으로 다룸)

       - 자연어는 독립사건이 아니고 **종속사건**이기 때문에 주변 단어에 따라 등장할 확률이 달라진다.

       - 통계적 언어모델 (Statistical Language Model, SLM) 

       - 단어가 n개 주어진 상황이라면, 언어 모델은 n개의 단어가 동시에 나타날 확률을 반환한다. 자연스러운 한국어 문장에 높은 확률 값을 부여한다.

       - 예시 : 누명을 쓰다 (0.41) / 누명을 당하다 (0.02) 

         잘 학습된 언어 모델이 있다면 어떤 문장이 그럴듯한지 (확률 값이 높은지) 알 수 있다. (전이학습이 중요한 이유)

       - 예시 : An adorable little boy is spreading smiles. 

         An adorable little boy 뒤에 is가 나올 확률?

         - 최대우도추정법 (Maximum Likelihood Estimation)으로 ‘is'가 나올 확률 계산:

           ![img](https://i.imgur.com/DL5qOzz.png)

           예를 들어 기계가 학습한 코퍼스 데이터에서 (An adorable little boy)가 100번 등장했는데 그 다음에 is가 등장한 경우는 30번이라고 합시다. 이 경우 확률은 30% 입니다. 

           문제 : count(An adorable little boy) = 0 이라면? 즉, 코퍼스에 단어가 없다면? 실생활에서는 분명히 존재하지만, 코퍼스에 존재하지 않는다면 가능성을 파악하지 못한다.

           즉, 데이터의 양이 많을수록 이런 문제를 해결할 가능성은 높아진다.

           • 희소 문제 (Sparsity Problem): 충분한 데이터를 관측하지 못하여 언어를 정확히 모델링하지 못하는 문제
           • 카운트 기반 접근의 한계 언어 모델은 실생활에서 사용되는 언어의 확률 분포를 근사 모델링 합니다. 실제로 정확하게 알아볼 방법은 없겠지만 현실에서도 An adorable little boy가 나 왔을 때 is가 나올 확률이라는 것이 존재합니다. 이를 실제 자연어의 확률 분포, 현실에서의 확률 분포라고 명칭합시다.
           • 기계에게 많은 코퍼스를 훈련시켜서 언어 모델을 통해 현실에서의 확률 분포를 근사 하는 것이 언어 모델의 목표입니다. 그런데 카운트 기반으로 접근하려고 한다면 갖고있는 방대한 양의 코퍼스(corpus)가 필요합니다.

           

           • 문제 1: 기계가 훈련한 코퍼스에 (An adorable little boy is)라는 단어 시퀀스가 없었다면 이 단어 시퀀스에 대한 확률은 0이 됩니다. P=0
           • 문제 2: (An adorable little boy)라는 단어 시퀀스가 없었다면 분모가 0이 되어 확률은 정의되지 않습니다. P = nonexistent
           • 희소 문제 (Sparsity Problem): 충분한 데이터를 관측하지 못하여 언어를 정확히 모델링하지 못하는 문제

           

           N-gram 모델: 직전 n-1개 단어의 등장 확률로 전체 단어 시퀀스 등장 확률을 근사하는 모델. (Markov assumption 을 기반으로)

           ![img](https://i.imgur.com/EUG9I5z.png)

           앞 단어 중 임의의 개수만 포함해서 카운트 후, 근사(approximate) 값을 취한다. 

           효과 : 갖고 있는 코퍼스에서 해당 단어의 시퀀스를 카운트할 확률이 높아진다.

           

           참고 ) 조건부확률 

           > A = 전체 중 여성인 사건 
           >
           > B = 전체 중 남성인 사건 
           >
           > C = 전체 중 대학생인 사건 
           >
           > D = 전체 중 교수인 사건

           ![img](https://i.imgur.com/Dp6pEUT.png)

           한 명을 뽑았을 때, 교수일 확률: P(D) = 60/240 = 1/4 

           한 명을 뽑았을 때, 여성 교수일 확률: P(A∩D) = 20/240 = 1/12 

           교수 중 한 명을 뽑았을 때, 여성일 확률: P(A|D) = P(A∩D)/P(D) = (20/240)/(60/240) =1/3

           

    2. 뉴럴 네트워크 기반 언어 모델 (뉴럴 네트워크 기반으로 다룸)

       2.1. 언어모델

       - 입력과 출력 사이의 관계를 유연하게 포착할 수 있고, 그 자체로 확률 모델로 기능할 수 있다.

       - 예시 : 발 없는 말이 —> (언어 모델) —> 간다. (추측) 

         예시에 주어진 단어 시퀀스를 바탕으로 다음 단어를 맞추는 (prediction) 과정에서 학습된다.

         ELMo, GPT 등 모델이 여기에 해당한다. 

       2.2. Mask 모델

       - 마스크 모델은 뉴럴 네트워크와 다르다. 예시 : 발 없는 말이 (MASK) 간다. —> (MASK) 추측 : [천리]

       - 언어 모델은 일방향으로, 순차적으로 단어를 입력받아 다음 단어를 추측한다. 마스크 모델은 양방향 학습이 가능하다.
       - BERT 가 이 부류에 속한다.



- 어떤 단어가 같이 쓰였는가?

  1. 분포가정

  - 분포 가정은 문장에서 어떤 단어가 같이 쓰였는지가 중요하다. 
  - 자연어 처리에서 분포 (distribution) : 
    - **특정 범위(윈도우)** 내에 동시에 등장하는 이웃 단어/ 문맥의 집합
  - 분포 가정의 전제 : 
    - 어떤 단어 쌍이 비슷한 **문맥** 환경에서 자주 등장한다면 그 의미 또한 유사할 것.

  - 예시 : 다리가 아프다. 

    leg // 팔이 아프다. 머리가 아프다 다리가 지어졌다. 

    bridge // 건물이 지어졌다. 집이 지어졌다.

  * 흔히 사용되는 ‘문맥’ 개념과의 차이점 : 
    * 글월에 표현된 의미의 앞뒤 연결. (X) 
    * 특정 범위 (= 윈도우) 내에 속하는 단어들 (O)

  2. 점별 상호 정보량 (Pointwise Mutual Information)

     두 점이 얼마나 연관심이 있는지 판단

     점별 상호 정보량 (PMI) : 두 확률변수 사이의 상관성을 숫자로 변환하는 단위다.

     ![img](https://i.imgur.com/5kjf2iI.png)

     두 확률변수가 완전히 ‘독립’인 경우 그 값이 0이 된다. 

     PMI 는 두 단어의 등장이 독립일 때 대비해 얼마나 자주 같이 등장하는지를 수치화한 것. 

     조건부확률 : 사건 Y가 일어났을 때 사건 X가 일어날 확률

  3. WORD2VEC

     CBOW (왼쪽): 문맥 단어들을 통해 타깃 단어 하나를 맞추는 과정에서 학습됨. (코퍼스 크기 작을 때 성능 좋음)

     Skip-gram (오른쪽): 타깃 단어를 가지고 문맥 단어가 무엇일지 예측하는 과정에서 학습됨 (코퍼스 일정 크기 이상일 때 많이 쓰임)

     ![img](https://i.imgur.com/XZ6x98J.png)

     둘 모두 특정 타깃 단어 주변의 문맥, 즉 분포 정보를 임베딩에 함축한다.

     - 코사인 유사도 : 

       - 두 벡터 간의 코사인 각도를 이용하여 구할 수 있는 두 벡터의 유사도.

       - 단어를 임베딩하여 수치화하였으면, 이러한 표현 방법에 대해서 코사인 유사도를 이용하여 문서의 유사도를 구하는 게 가능하다.

       - 두 벡터의 방향이 완전히 동일한 경우에는 1의 값을 가지며, 90°의 각을 이루면 0, 180°로 반대의 방향을 가지면 -1의 값을 갖게 됩니다.

       - 즉, 결국 코사인 유사도는 -1 이상 1 이하의 값을 가지며 값이 1에 가까울수록 유사도가 높다고 판단할 수 있습니다. 이를 직관적으로 이해하면 두 벡터가 가리키는 방향이 얼마나 유사한가를 의미합니다.

       - -1에 가까울 수록 배타적인 경향을 보이고, 0에 가까울 수록 서로 상관관계가 없다고 판단된다.

         ![img](https://i.imgur.com/Qns4GKd.png)

         

- 요약

  임베딩이 자연어의 의미를 함축하는 방법은 자연어의 통계적 패턴 (statistical pattern) 을 통째로 임베딩에 넣는 것이다.

  백오브워즈 가정, 언어 모델, 분포 가정은 코퍼스의 통계적 패턴을 서로 다른 각도에서 분석하는 것이며 상호 보완적이다.



- 참고

  한국어 임베딩 이기창. 2019. 에이콘 출판사.

  딥러닝을 이용한 자연어 처리 입문 Won Joon Yoo. 2020~. https://wikidocs.net/book/2155

  한국어 임베딩 깃헙 https://ratsgo.github.io/embedding/



## 1-4. 영화추천 시스템 실습 코드 분석

> Kaggle에서 사용되었던 영화 데이터셋을 가지고 영화 추천 시스템을 만들어보겠습니다.
>
> TF-IDF와 코사인 유사도만으로 영화의 줄거리에 기반해서 영화를 추천하는 추천 시스템을 만들 수 있습니다.
>
> 다운로드 링크 : https://www.kaggle.com/rounakbanik/the-movies-dataset

```python
import pandas as pd
import numpy as np

# Data에 예외 제거 
data = pd.read_csv('movies_metadata.csv', error_bad_lines=False)
#에러 라인은 무시

print(data.columns)
```

> 데이터 분류기준이 출력됨
>
> Index(['adult', 'belongs_to_collection', 'budget', 'genres', 'homepage', 'id',       'imdb_id', 'original_language', 'original_title', 'overview',       'popularity', 'poster_path', 'production_companies',       'production_countries', 'release_date', 'revenue', 'runtime',       'spoken_languages', 'status', 'tagline', 'title', 'video',       'vote_average', 'vote_count'],      dtype='object')

```python
display(data.head(2))
```

> 2개 만 데이터를 보여준다

줄거리가 비슷한 영화 추천 : overview 기준으로 추천

```python
# 훈련 데이터의 양을 줄이고 학습을 진행하고 싶은 경우, 변경하여 재저장
data = data[:3000]
# data의 overview 열에 Null 값을 빈 값으로 대체(줄거리가 없는 것을 ' '로 설정하여 에러 방지)
data['overview'] = data['overview'].fillna('')
```

코사인 유사도 적용

```python
from sklearn.feature_extraction.text import TfidfVectorizer

#tf-idf를 사용
tfidf = TfidfVectorizer(stop_words='english') #의미 없는 단어를 넣어서 해당 단어는 무시한다. 예) 의미없이 반복되는 단어
tfidf_matrix = tfidf.fit_transform(data['overview'].apply(lambda tfidf_matrix: np.str(tfidf_matrix)))

# overview에 대해서 tf-idf 수행
print(f"데이터 수, 단어 수: {tfidf_matrix.shape}")
```

```python
# 코사인 유사도를 사용한 문서의 유사도

from sklearn.metrics.pairwise import linear_kernel

cosine_sim = linear_kernel(tfidf_matrix, tfidf_matrix) # 벡터의 내적 값 계산으로 코사인 유사도를 구함

indices = pd.Series(data.index, index=data['title']).drop_duplicates()
display(indices.head(50))
print()

idx = indices['Father of the Bride Part II']
print(idx)
```

인덱스화 되었다.

출력해주는 함수

```python
def get_recommendations(title, cosine_sim = cosine_sim):
  # 선택한 영화 제목의 인덱스를 저장한다.
  idx = indices[title]
  
  # 모든 영화에 대해서 해당 영화와의 유사도를 쌍으로 구한다. 
  sim_scores = list(enumerate(cosine_sim[idx]))

  # 유사도에 따라 영화들을 정렬한다.
  sim_scores = sorted(sim_scores, key=lambda x: x[1], reverse=True)

  # 가장 유사한 10개의 영화를 받아온다.
  sim_scores = sim_scores[1:11]

  # 가장 유사한 10개의 영화의 인덱스를 받아온다.
  movie_indices = [i[0] for i in sim_scores]

  # 가장 유사한 10개의 영화의 제목을 리턴한다.
  return data['title'].iloc[movie_indices]
```

이제 결과를 출력하자

토이스토리와 가장 유사한 내용의 영화를 추천 받는다.

```python
get_recommendations('Toy Story')
```

> 2997              Toy Story 2 
>
> 1071    Rebel Without a Cause 
>
> 485                    Malice 
>
> 1932                Condorman 
>
> 448         For Love or Money 
>
> 1032            The Sunchaser 
>
> 2157        Indecent Proposal 
>
> 1884           Child's Play 3 
>
> 2635               Radio Days 
>
> 2681               Funny Farm Name: title, dtype: object